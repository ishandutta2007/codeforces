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
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pair2<int>> a(n);
	for (int i =0 ; i < n; i++) scanf("%d%d", &a[i].fi, &a[i].se);
	for (int i =0 ; i < n; i++)
	{
		bool ok = true;
		for (int j = 0; j < n; j++) ok &= (abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se)) <= k;
		if (ok)
		{
			printf("1\n");
			return;
		}
	}
	printf("-1\n");
	
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