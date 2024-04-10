#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
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

const int maxn = 50005;

int d[maxn];
int when[maxn];
int a[maxn], b[maxn];
int n, nq;
int timer;
int tin[maxn], tout[maxn];
vector<int> gr[maxn];

void go(int cur, int curd)
{
	tin[cur] = timer++;
	d[tin[cur]] = curd;
	for (auto t : gr[cur]) go(t, curd + 1);
	tout[cur] = timer - 1;
}

int main()
{
	scanf("%d%d", &n, &nq);
	//n = 50000;
	//nq = 50000;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		//a[i] = abs((int)rng() % 5);
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x;
		scanf("%d", &x);
		//x = abs((int)rng() % (i + 1)) + 1;
		gr[x - 1].pb(i + 1);
	}
	go(0, 0);
	for (int i = 0; i < n; i++) b[tin[i]] = a[i];
	for (int i = 0; i < n; i++) when[i] = 0;
	for (int q = 0; q < nq; q++)
	{
		int x;
		scanf("%d", &x);
		//x = abs((int)rng() % n) + 1;
		//x = 1;
		x--;
		int cnt = 0;
		ll sumd = 0;
		for (int i = tin[x]; i <= tout[x]; i++) if (when[i] <= q)
		{
			when[i] = q + b[i];
			cnt++;
			sumd += d[i];
		}
		printf("%lld %d\n", sumd - (ll)cnt * d[tin[x]], cnt);
	}
    return 0;
}