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

const ll treesize = 1LL << 60;

ll get(ll cl, ll cr, ll l, ll r)
{
	if (l > cr || r < cl) return 0;
	if (cl >= l && cr <= r)
	{
		if (cl == cr) return cl;
		if (cr - cl == 1) return cl ^ cr;
		return 0;
	}
	ll cm = (cl + cr) / 2;
	return get(cl, cm, l, r) ^ get(cm + 1, cr, l, r);
}

int main()
{
	int n;
	scanf("%d", &n);
	ll answer = 0;
	for (int i =0 ; i < n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		b = a + b - 1;
		answer ^= get(0, treesize - 1, a, b);
	}
	if (answer == 0) printf("bolik\n");
	else printf("tolik\n");
    return 0;
}