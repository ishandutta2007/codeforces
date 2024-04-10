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

void solve()
{
	ll d, m;
	scanf("%lld%lld", &d, &m);
	ll curans = 0;
	for (ll p2 = 1; p2 <= d; p2 *= 2)
	{
		ll cnt = min(d, 2 * p2 - 1) - p2 + 1;
		ll endshere = (curans + 1) * cnt;
		curans += endshere;
		curans %= m;
	}
	printf("%lld\n", curans);
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