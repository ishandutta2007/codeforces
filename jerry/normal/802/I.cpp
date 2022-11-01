#include <bits/stdc++.h>
using namespace std;

class Suffix_Tree
{
	public:
		struct Suffix_Node
		{
			int ch[30];

			int suffix_link;

			/* Characteristics of the edge leading to this node */
			int ptrlo;
			int ptrhi;

			int substr_len;

			Suffix_Node(int low, int high);
			Suffix_Node();

			int get_len() const;
		};

		string self;
		int num_nodes;
		Suffix_Node all_nodes[200005];

		int active_node;
		char active_edge;
		int active_length;

		int remain;

		int get_new_node(int low, int high);


		/* constant representing a leaf node */
		const static int LEAF = 2147483647;

		Suffix_Tree();

		void append(const char x);
		void build(const string& buf);
		void print_tree(int at, int depth) const;
};

Suffix_Tree::Suffix_Node::Suffix_Node(int low, int high)
{
	suffix_link = -1;
	ptrlo = low;
	ptrhi = high;
	for (int i = 0;i < 30;i++)
		ch[i] = -1;
}

Suffix_Tree::Suffix_Node::Suffix_Node()
{
}

int Suffix_Tree::Suffix_Node::get_len() const
{
	return (ptrhi - ptrlo);
}

Suffix_Tree::Suffix_Tree()
{
	num_nodes = 0;
	self = string();
	all_nodes[get_new_node(0, 0)].substr_len = 0;
	active_node = 0;
	active_edge = 0;
	active_length = 0;
	remain = 0;
}

int Suffix_Tree::get_new_node(int low, int high)
{
	all_nodes[num_nodes] = Suffix_Node(low, high);
	return num_nodes++;
}

void Suffix_Tree::append(const char x)
{
	int previous = -1;
	self.push_back(x);
	for (remain++;remain > 0;remain--)
	{
		int idx = self.size() - remain;
		if (active_node == -1)
			active_node = 0;
		while (all_nodes[active_node].ch[active_edge] != -1 && active_length >= all_nodes[all_nodes[active_node].ch[active_edge]].get_len())
		{
			active_length -= all_nodes[all_nodes[active_node].ch[active_edge]].get_len();
			active_node = all_nodes[active_node].ch[active_edge];
			if (active_length == 0)
				active_edge = 0;
			else
				active_edge = self[idx+all_nodes[active_node].substr_len];
		}
		if (active_length == 0)
		{
			if (previous != -1)
				all_nodes[previous].suffix_link = active_node;
			previous = active_node;
			int tmp = idx + all_nodes[active_node].substr_len;
			if (all_nodes[active_node].ch[self[tmp]] != -1)
			{
				active_length++;
				active_edge = self[tmp];
				break;
			}
			all_nodes[active_node].ch[self[tmp]] = get_new_node(tmp, LEAF);
			active_node = all_nodes[active_node].suffix_link;
			continue;
		}
		int match_idx = all_nodes[all_nodes[active_node].ch[active_edge]].ptrlo + active_length;
		if (self[match_idx] == x)
		{
			active_length++;
			break;
		}
		// split
		int oldlink = get_new_node(all_nodes[all_nodes[active_node].ch[active_edge]].ptrlo, match_idx);
		all_nodes[oldlink].ch[self[match_idx]] = all_nodes[active_node].ch[active_edge];
		all_nodes[all_nodes[oldlink].ch[self[match_idx]]].ptrlo = match_idx;
		all_nodes[active_node].ch[active_edge] = oldlink;
		all_nodes[oldlink].substr_len = all_nodes[active_node].substr_len + all_nodes[oldlink].get_len();
		int tmp = idx+match_idx-all_nodes[all_nodes[active_node].ch[active_edge]].ptrlo+all_nodes[active_node].substr_len;
		all_nodes[oldlink].ch[self[tmp]] = get_new_node(tmp, LEAF);
		if (previous != -1)
			all_nodes[previous].suffix_link = oldlink;
		previous = oldlink;
		if (active_node != 0)
			active_node = all_nodes[active_node].suffix_link;
		else
		{
			if (remain != 1)
				active_edge = self[self.size()-remain+1];
			active_length--;
		}
	}
	if (active_node == -1)
		active_node = 0;
	if (all_nodes[active_node].ch[active_edge] != -1 && active_length == all_nodes[all_nodes[active_node].ch[active_edge]].get_len())
	{
		active_node = all_nodes[active_node].ch[active_edge];
		active_edge = 0;
		active_length = 0;
	}
}

void Suffix_Tree::build(const string& buf)
{
	for (const char& x: buf) append(x);
	append(0);
}

void Suffix_Tree::print_tree(int at, int depth) const
{
	if (at == -1) return;
	for (int i = 0;i < depth;i++) printf("--> ");
	for (int i = all_nodes[at].ptrlo;i < all_nodes[at].ptrhi && i < self.size();i++)
		printf("%c", self[i]+'a'-1);
	printf("\n");
	for (int i = 0;i < 30;i++)
		print_tree(all_nodes[at].ch[i], depth+1);
}


typedef long long ll;

ll ans;
string todo;
int N;

ll dfs(const Suffix_Tree& st, int at, int far)
{
	ll occ = 0;
	for (int i = 0;i < 30;i++) if (st.all_nodes[at].ch[i] != -1)
	{
		int nxt = far+st.all_nodes[st.all_nodes[at].ch[i]].ptrhi-st.all_nodes[st.all_nodes[at].ch[i]].ptrlo;
		if (st.all_nodes[st.all_nodes[at].ch[i]].ptrhi == Suffix_Tree::LEAF) nxt = far+N-st.all_nodes[st.all_nodes[at].ch[i]].ptrlo;
		ll n_occ = dfs(st, st.all_nodes[at].ch[i], nxt);
		occ += n_occ;
		ans += (nxt-far)*n_occ*n_occ;
	}
	if (occ == 0) occ++;
	return occ;
}

ll slv(const Suffix_Tree& st)
{
	ans = 0;
	dfs(st, 0, 0);
	return ans;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		Suffix_Tree st;
		cin >> todo;
		N = todo.size()+1;
		for (char &c: todo) c -= 'a', c++;
		st.build(todo);
		printf("%lld\n", slv(st)-N);
	}
	return 0;
}