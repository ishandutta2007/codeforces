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

const int MOD = 1000000007;

const int maxn = 100005;

bool was[maxn];
int a[maxn];
int ans[maxn];
int n, q;
ll sum;
vector<int> gr[maxn];
vector<int> order;
int wh[maxn];

void toorder(int cur)
{
	if (was[cur]) return;
	was[cur] = true;
	for (auto t : gr[cur]) toorder(t);
	order.pb(cur);
}

inline void upd(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int main()
{
	scanf("%d%d%lld", &n, &q, &sum);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[b].pb(a);
	}
	for (int i =0 ; i < n; i++) if (!was[i]) toorder(i);
	for (int i = 0; i < n; i++) wh[order[i]] = i;
	for (int i = 0; i < n; i++) if (!gr[i].empty())
	{
		if (wh[gr[i][0]] > wh[i])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	for (auto t : order)
	{
		if (!gr[t].empty())
		{
			sum -= a[gr[t][0]];
			a[t] += a[gr[t][0]];
		}
	}
	//for (int i =0 ; i < n; i++) cout << a[i] << ' ';
	//cout << sum << endl;
	if (sum < 0)
	{
		cout << 0 << endl;
		return 0;
	}
	ans[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i]; j <= sum; j++) upd(ans[j], ans[j - a[i]]);
	}
	cout << ans[sum] << endl;
	
    return 0;
}