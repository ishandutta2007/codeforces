#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 1000;

vector<int> gr[maxn];
char s[maxn];

class Blossom
{
	public:
	const static int N = 1000 + 100;
	int mate[N], n, ret;
	int run(int n, const  std::vector<int> G[]) {
		this->n = n;
		std::fill(mate, mate + n, -1);
		for (int i = 0; i < n; i++) if (mate[i] == -1) aug(i, G);
		for (int i=ret=0;i < n; i++) ret += (mate[i] > i);
		return ret;
	}
	private:
	int next[N], dsu[N], mark[N], vis[N];
	std::queue<int> Q;
	int get(int x) {return (x == dsu[x])?x:(dsu[x]=get(dsu[x]));}
	void merge(int a, int b) { dsu[get(a)] = get(b); }
	int lca(int x, int y)
	{
		static int t  =0; ++t;
		for(;;std::swap(x, y)) if (x != -1) {
			if (vis[x=get(x)]==t) return x; vis[x] = t;
			x=(mate[x]!=-1)?next[mate[x]]:-1;
		}
	}
	void group(int a, int p)
	{
		for (int b, c; a != p; merge(a, b), merge(b, c), a = c) {
			b=mate[a],c = next[b];
			if (get(c) != p) next[c] = b;
			
			if (mark[b] == 2) mark[b] = 1, Q.push(b);
			if (mark[c] == 2) mark[c] = 1, Q.push(c);
		}
	}
	void aug(int s, const  std::vector<int> G[]) {
		for (int i = 0; i < n; i++) next[i] = vis[i] = -1, dsu[i] = i, mark[i] = 0;
		while (!Q.empty()) Q.pop(); Q.push(s); mark[s] = 1;
		while(mate[s] == -1 && !Q.empty())
		{
			int x = Q.front(); Q.pop();
			for (int i = 0, y; i < (int)G[x].size(); i++)
			{
				if ((y = G[x][i])!=mate[x]&&get(x)!=get(y)&&mark[y]!=2)
				{
					if (mark[y] == 1)
					{
						int p = lca(x, y);
						if (get(x)!=p) next[x] = y;
						if (get(y) != p) next[y] = x;
						group(x, p);
						group(y, p);
					} else if (mate[y] == -1) {
						next[y] = x;
						
						for (int j = y, k, l; j != -1; j=l) {
							k=next[j]; l = mate[k];
							mate[j] = k; mate[k] = j;
						}
						break;
					} else
					{
						next[y] = x; Q.push(mate[y]);
						mark[mate[y]] = 1; mark[y] = 2;
					}
			}
		}
	}
}
} B;

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < 2 * n + m; i++) gr[i].clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			for (int j = 0; j < m; j++) if (s[j] == '1')
			{
				gr[i].pb(2 * n + j);
				gr[2 * n + j].pb(i);
				gr[n + i].pb(2 * n + j);
				gr[2 * n + j].pb(n + i);
			}
			gr[i].pb(n + i);
			gr[n + i].pb(i);
		}
		int ans = B.run(2 * n + m, gr);
		printf("%d\n", ans - n);
	}
    return 0;
}