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

const int maxn = 300005;

int init[maxn];
pair2<int> p[maxn];
int c[maxn];
int sz[maxn][2];
bool must[maxn];
int col[maxn];
int n, k;
vector<int> who[maxn];
int answer;
char s[maxn];

pair2<int> find(int x)
{
	if (p[x].first == x) return {x, 0};
	auto ret = find(p[x].fi);
	ret.se ^= p[x].se;
	p[x] = ret;
	return ret;
}

inline void add(int a, int t)
{
	if (must[a]) answer += t * sz[a][col[a]];
	else answer += t * min(sz[a][1], sz[a][0]);
}

inline void unite(int a, int b, int t)
{
	auto ra = find(a);
	t ^= ra.se;
	a = ra.fi;
	auto rb = find(b);
	t ^= rb.se;
	b = rb.fi;
	if (a == b)
	{
		assert(t == 0);
		return;
	}
	add(a, -1);
	add(b, -1);
	if (c[a] > c[b]) swap(a, b);
	//cout << "unite " << a << ' ' << b << ' ' << t << endl;
	p[a] = {b, t};
	sz[b][0] += sz[a][0 ^ t];
	sz[b][1] += sz[a][1 ^ t];
	if (must[a]) col[b] = (col[a] ^ t);
	must[b] |= must[a];
	if (c[a] == c[b]) c[b]++;
	//cout << b << ' ' << must[b] << ' ' << sz[b][0] << ' ' << sz[b][1] << endl;
	add(b, 1);
}

inline void addedge(int a, int b, int t) { unite(a, b, t); }

inline void restrict(int a, int t)
{
	auto ra = find(a);
	t ^= ra.se;
	a = ra.fi;
	add(a, -1);
	//cout << "restrict " << a << ' ' << t << endl;
	//cout << sz[a][0] << ' ' << sz[a][1] << endl;
	col[a] = t;
	must[a] = true;
	add(a, 1);
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++) init[i] = s[i] - '0';
	for (int i = 0; i < k; i++)
	{
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			who[x].pb(i);
		}
	}
	answer = 0;
	for (int i = 0; i < k; i++)
	{
		p[i] = {i, 0};
		c[i] = 0;
		sz[i][0] = 0;
		sz[i][1] = 1;
		must[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (init[i] == 0)
		{
			if (who[i].size() == 1) restrict(who[i][0], 1);
			else addedge(who[i][0], who[i][1], 1);
		} else
		{
			if (who[i].size() == 1) restrict(who[i][0], 0);
			else if (who[i].size() == 2) addedge(who[i][0], who[i][1], 0);
		}
		printf("%d\n", answer);
	}
    return 0;
}