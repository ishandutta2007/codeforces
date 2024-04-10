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

int n, W, s1, s2;

int main()
{
	scanf("%d%d%d%d", &n, &W, &s1, &s2);
	bool canbefore = true;
	ld mintafter = (ld)W / s2;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		// x / s1 < y / s2
		if ((ll)x * s2 < (ll)y * s1)
		{
			canbefore = false;
		}
		mintafter = max(mintafter, (ld)x / s1 + (ld)(W - y) / s2);
	}
	if (canbefore) mintafter = (ld)W / s2;
	cout.precision(20);
	cout << mintafter << endl;
    return 0;
}