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

const int maxn = 100005;

int a[maxn];
int cnt[maxn];
int n;

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	int totcnt = 0;
	for (int i = 0; i < n - 1; i++) if (a[i] == a[i + 1])
	{
		cnt[a[i]] += 2;
		totcnt++;
	}
	cnt[a[0]]++;
	cnt[a[n - 1]]++;
	int blocks = totcnt + 1;
	auto wh = max_element(cnt + 1, cnt + n + 1);
	int mx = *wh;
	int val = wh - cnt;
	int canadd = 0;
	for (int i = 0; i < n - 1; i++) if (a[i] != a[i + 1] && a[i] != val && a[i + 1] != val)
	{
		canadd++;
	}
	if (blocks + canadd < mx - 1)
	{
		printf("-1\n");
	} else
	{
		blocks = max(blocks, mx - 1);
		printf("%d\n", blocks - 1);
	}	
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}