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

const int maxn = 200005;
const int MOD = 998244353;

int a[maxn], b[maxn], wh[maxn];
int used[maxn];
set<int> all;

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
		wh[a[i]] = i;
	}
	for (int i = 0; i < n; i++) used[i] = -1;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &b[i]);
		b[i]--;
		b[i] = wh[b[i]];
		used[b[i]] = i;
	}
	all.clear();
	for (int i = 0; i < n; i++) all.insert(i);
	all.insert(-1);
	all.insert(n);
	int answer = 1;
	for (int i =0 ; i < k; i++)
	{
		auto it = all.find(b[i]);
		auto nxt = next(it);
		auto prv = prev(it);
		int ok = 0;
		if (*nxt != n && used[*nxt] < i)
		{
			ok++;
			it = nxt;
		}
		if (*prv != -1 && used[*prv] < i)
		{
			ok++;
			it = prv;
		}
		if (ok == 0)
		{
			printf("%d\n", 0);
			return;
		}
		all.erase(it);
		answer = (answer * ok) % MOD;
	}
	printf("%d\n", answer);
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