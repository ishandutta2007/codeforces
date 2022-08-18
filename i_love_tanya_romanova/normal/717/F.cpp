#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define debug_flag 1
#else
	#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p) 
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

typedef long long int int64;

const int64 int64_INF = (int64)1e18;
const int pow2 = (1 << 18);

struct Node
{
	int len;
	int64 min_val[2][2];
	int64 sum[2];

	Node()
	{
		len = 1;
		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
					min_val[i][j] = int64_INF;
				else
					min_val[i][j] = 0;
			}
		}
		
		for (int i = 0; i < 2; i++)
			sum[i] = 0;
	}

	bool is_good() const
	{
		for (int check_len = 0; check_len < 2; check_len++)
		{
			int f = check_len;
			int64 val = min_val[f][check_len];
			if (check_len == 0)
				val--;
		
			if (val < 0)
				return false;
		}

		int64 val = sum[len];
		if (len % 2 == 0)
			val--;
		
		return val == 0;
	}
};

Node EMPTY_NODE;

Node merge(const Node &l, const Node &r)
{
	Node res;

	res.len = (l.len + r.len) % 2;

	for (int f = 0; f < 2; f++)
	{
		int f2 = (f + l.len) % 2;
		res.sum[f] = l.sum[f] + r.sum[f2];
	}

	for (int f = 0; f < 2; f++)
	{
		for (int len = 0; len < 2; len++)
		{
			int64 a = l.min_val[f][len];

			int f2 = (f + l.len) % 2;
			int l2 = (len + l.len) % 2;
			int64 b = l.sum[f] + r.min_val[f2][l2];

			res.min_val[f][len] = min(a, b);
		}
	}

	return res;
}

Node apply(const Node &v, int64 x)
{
	Node res = v;

	for (int f = 0; f < 2; f++)
	{
		int cnt1 = res.len;

		if (f == 0)
			res.sum[f] += cnt1 * (-x);
		else
			res.sum[f] += cnt1 * x;
	}

	for (int f = 0; f < 2; f++)
	{
		for (int len = 0; len < 2; len++)
		{
			int cnt1 = len;

			if (f == 0)
				res.min_val[f][len] += cnt1 * (-x);
			else
				res.min_val[f][len] += cnt1 * x;
			
		}
	}

	return res;
}

void print(const Node &v)
{
	dbg("---");
	dbg(v.len);
	for (int f = 0; f < 2; f++)
		dbg(f, v.sum[f]);
	for (int f = 0; f < 2; f++)
		for (int l = 0; l < 2; l++)
			dbg(f, l, v.min_val[f][l]);
	dbg("~~~");
}

struct Tree
{
	Node node[pow2 * 2];
	int64 flag[pow2 * 2];

	Tree()
	{
		for (int i = pow2; i < 2 * pow2; i++)
			node[i] = Node();

		for (int i = pow2 - 1; i >= 1; i--)
			node[i] = merge(node[i * 2], node[i * 2 + 1]);

		for (int i = 0; i < pow2 * 2; i++)
			flag[i] = 0;
	}

	bool not_inter(int l, int r, int a, int b)
	{
		return l > b || r < a;
	}

	bool is_in(int l, int r, int a, int b)
	{
		return a <= l && r <= b;
	}

	void push(int v)
	{
		if (v < pow2)
		{
			int64 f = flag[v];
			flag[v] = 0;
			flag[v * 2] += f;
			flag[v * 2 + 1] += f;
			node[v * 2] = apply(node[v * 2], f);
			node[v * 2 + 1] = apply(node[v * 2 + 1], f);
		}
	}

	void add(int a, int b, int64 x)
	{
		add(1, 0, pow2 - 1, a, b, x);
	}

	void add(int v, int l, int r, int a, int b, int64 x)
	{
		if (not_inter(l, r, a, b))
			return;
		
		if (is_in(l, r, a, b))
		{
			flag[v] += x;
			node[v] = apply(node[v], x);
			return;
		}

		push(v);

		int m = (l + r) / 2;
		add(v * 2, l, m, a, b, x);
		add(v * 2 + 1, m + 1, r, a, b, x);
		node[v] = merge(node[v * 2], node[v * 2 + 1]);
	}

	Node get_sum(int a, int b)
	{
		return get_sum(1, 0, pow2 - 1, a, b);
	}

	Node get_sum(int v, int l, int r, int a, int b)
	{
		if (not_inter(l, r, a, b))
			return EMPTY_NODE;

		if (is_in(l, r, a, b))
			return node[v];

		push(v);
		
		int m = (l + r) / 2;
		Node l_node = get_sum(v * 2, l, m, a, b);
		Node r_node = get_sum(v * 2 + 1, m + 1, r, a, b);
		return merge(l_node, r_node);
	}
};

void init_empty_node()
{
	EMPTY_NODE.len = 0;
	
	for (int f = 0; f < 2; f++)
		EMPTY_NODE.sum[f] = 0;

	for (int f = 0; f < 2; f++)
		for (int l = 0; l < 2; l++)
			EMPTY_NODE.min_val[f][l] = int64_INF;
}

int n;
Tree tree;

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	init_empty_node();
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		
		tree.add(i, i, a);
	}
	
	int q;
	scanf("%d", &q);
	for (int it = 0; it < q; it++)
	{
		int type;
		scanf("%d", &type);
		
		int a, b;
		scanf("%d%d", &a, &b);

		if (type == 1)
		{
			int x;
			scanf("%d", &x);
		
			tree.add(a, b, x);
		}
		else
		{
			tree.add(a, a, -1);
			
			Node node = tree.get_sum(a, b);
	
			bool is_good = node.is_good();

			tree.add(a, a, 1);
			
			printf("%d\n", (int)is_good);
		}
	}

	return 0;
}