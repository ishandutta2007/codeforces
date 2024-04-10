#include <bits/stdc++.h>

using namespace std;

namespace program
{
	struct node;

	const int MAXN = 200000, MAXL = 200000;
	const int MAXQ = 500000, M = 26;
	char PoolS[MAXN + MAXL + 10], *S[MAXN + 10];
	node *root, *PoolW[MAXN + MAXL + 10], **W[MAXN + 10];
	int n, dfn, Ans[MAXQ + 10], C[MAXN + MAXL + 10];

	int read()
	{
		int s = 0, ch;
		while(!isdigit(ch = getchar()));
		do
			s = s * 10 + ch - '0';
		while(isdigit(ch = getchar()));
		return s;
	}

	void write(int x)
	{
		static int Buf[30];
		int top = 0;
		do
			Buf[top++] = x % 10 + '0';
		while(x /= 10);
		while(top)
			putchar(Buf[--top]);
	}

	struct query_t { int u, l, r, mul, *ans; } L[(MAXQ << 1) + 10];

	struct edge
	{
		node *v;
		edge *next;
		edge(node *_v, edge *_next) : v(_v), next(_next) { }
	};

	struct node
	{
		int st, ed;
		node *son[M], *fail;
		edge *head;
		node() : head(NULL) { memset(son, 0, sizeof(son)); }
		void add_edge(node *v) { head = new edge(v, head); }
	};

	inline bool operator <(const query_t &x, const query_t &y)
		{ return x.u < y.u; }

	node **insert(node **w, const char *ch)
	{
		vector<node *> R;
		if(!root)
			root = new node();
		*w++ = root;
		for(node *p = root; *ch; ch++)
		{
			node *&t = p->son[(*ch) - 'a'];
			if(!t)
				t = new node();
			p = t;
			*w++ = p;
		}
		return w;
	}

	void bfs_fail()
	{
		queue<node *> Q;
		root->fail = root;
		Q.push(root);
		while(!Q.empty())
		{
			node *u = Q.front();
			Q.pop();
			if(u->fail != u)
				u->fail->add_edge(u);
			for(int i = 0; i < M; i++)
				if(u->son[i])
				{
					if(u->son[i] != u->fail->son[i])
						u->son[i]->fail = u->fail->son[i];
					else
						u->son[i]->fail = root;
					Q.push(u->son[i]);
				}
				else
				{
					if(u->son[i] != u->fail->son[i])
						u->son[i] = u->fail->son[i];
					else
						u->son[i] = root;
				}
		}
	}

	void dfs_dfn(node *u)
	{
		u->st = ++dfn;
		for(edge *p = u->head; p; p = p->next)
			dfs_dfn(p->v);
		u->ed = dfn;
	}

#define lowbit(i) ((i) & -(i))

	void update(int i, int v)
	{
		while(i <= dfn)
		{
			C[i] += v;
			i += lowbit(i);
		}
	}

	int query(int i)
	{
		int tot = 0;
		while(i > 0)
		{
			tot += C[i];
			i -= lowbit(i);
		}
		return tot;
	}

#undef lowbit

	void add_val(int i)
	{
		for(node **p = W[i]; p < W[i + 1]; p++)
			update((*p)->st, 1);
	}

	void work()
	{
		int q, t = 0;
		n = read();
		q = read();
		S[1] = PoolS;
		W[1] = PoolW;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", S[i]);
			W[i + 1] = insert(W[i], S[i]);
			S[i + 1] = S[i] + strlen(S[i]) + 1;
		}
		bfs_fail();
		dfs_dfn(root);
		for(int i = 0; i < q; i++)
		{
			int l, r, k, x, y;
			l = read();
			r = read();
			k = read();
			x = (*(W[k + 1] - 1))->st;
			y = (*(W[k + 1] - 1))->ed;
			L[t++] = (query_t) { r, x, y, 1, &Ans[i] };
			L[t++] = (query_t) { l - 1, x, y, -1, &Ans[i] };
		}
		memset(Ans, 0, sizeof(int) * q);
		memset(C + 1, 0, sizeof(int) * n);
		sort(L, L + t);
		for(int i = 0, p = 1; i < t; i++)
		{
			while(p <= L[i].u)
				add_val(p++);
			*L[i].ans += L[i].mul * (query(L[i].r) - query(L[i].l - 1));
		}
		for(int i = 0; i < q; i++)
		{
			write(Ans[i]);
			putchar('\n');
		}
	}
}

int main()
{
	program::work();
	return 0;
}