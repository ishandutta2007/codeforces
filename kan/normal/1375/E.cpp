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

const int maxn = 1005;

pair2<int> a[maxn], b[maxn];
vector<pair2<int>> answer;
int n;
vector<int> ans[maxn];
int lasti[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].fi);
		a[i].se = i;
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) a[i].se = lower_bound(b, b + n, a[i]) - b;
	for (int i = 0; i < n; i++) b[i] = a[i];
	
	for (int i = 0; i < n; i++)
	{
		vector<pair<pair2<int>, int>> chwith;
		for (int j = 0; j < i; j++) if (b[j] > b[i])
		{
			chwith.pb({b[j], j});
		}
		sort(all(chwith));
		for (auto t : chwith) ans[i].pb(t.se);
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (auto t : ans[i])
		{
			answer.pb({t, i});
			swap(a[i], a[t]);
		}
	}
	
	for (int i =0 ; i < n; i++) assert(a[i].se == i);
	printf("%d\n", (int)answer.size());
	for (auto t : answer) printf("%d %d\n", t.fi + 1, t.se + 1);
    return 0;
}