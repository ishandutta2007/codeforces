#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef long long i64;
const int inf = 1e9+100500;
const int maxn = 200500;

struct node
{
	int l, r;
	node *L, *R;
	vi val;
	node(){}
	node(int lq, int rq, int a[])
	{
		l = lq, r = rq;
		if (l == r)
		{
			L = R = NULL;
			val = vi(1, a[l]);
		}
		else
		{
			L = new node(lq, (lq+rq)/2, a);
			R = new node((lq+rq)/2+1, rq, a);
			val.resize(rq-lq+1);
			merge(L->val.begin(), L->val.end(), R->val.begin(), R->val.end(), val.begin());
		}
	}
	int get(int lq, int rq, int x)
	{
		if (lq > r || rq < l) return 0;
		else if (lq <= l && rq >= r) return upper_bound(val.begin(), val.end(), x) - lower_bound(val.begin(), val.end(), x);
		else return L->get(lq, rq, x) + R->get(lq, rq, x);
	}
};

int n;
int p[maxn][20];
int h[maxn];
int a[maxn], pa=0;
int le[maxn], re[maxn];
vector<int> e[maxn];
node* t;
void dfs(int v)
{
	le[v] = pa;
	a[pa++] = h[v];
	forn(i, e[v].size())
	{
		int to = e[v][i];
		h[to] = h[v] + 1;
		dfs(to);
	}
	re[v] = pa;
	a[pa++] = h[v];
}
void init()
{
	forn(i, n) if (p[i][0] == -1) p[i][0] = i, dfs(i);
	forn(k, 20) if (k)
		forn(i, n) p[i][k] = p[p[i][k-1]][k-1];
	t = new node(0, pa-1, a);
}
int up(int x, int k) {forn(i, 20) if (k&(1<<i)) x = p[x][i]; return x;}
int get(int v, int x)
{
	if (h[v] < x)
		return 0;
	int p = up(v, x);
	return (t->get(le[p], re[p], h[v])) / 2 - 1;//- t->get(le[q], re[q], h[v])) / 2;
}
void solve()
{
	init();
	int q;
	cin >> q;
	forn(i, q)
	{
		int a, b;
		cin >> a >> b;
		cout << get(a-1, b) << " \n"[i == q-1];
	}
}

void scan()
{
	cin >> n;
	forn(i, n)
	{
		cin >> p[i][0];
		if (p[i][0])
			e[p[i][0]-1].pb(i);
		--p[i][0];
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scan();
	solve();
	
	return 0;
}