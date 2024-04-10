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

int f[maxn];
int a[maxn];
vector<pair2<int>> all;
ll answer;
int n;

void addF(int x, int t)
{
	for (; x <= n; x |= (x + 1))
	{
		f[x] += t;
	}
}

int getF(int x)
{
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
	{
		ans += f[x];
	}
	return ans;
}

int get(int l, int r)
{
	if (r < l) return 0;
	return getF(r) - getF(l - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		all.pb({a[i], i});
	}
	sort(all(all));
	for (int i = 1; i <= n; i++) addF(i, 1);
	int cur = 0;
	ll answer = 0;
	for (int i = 1; i <= n; i++)
	{
		while (cur < (int)all.size() && all[cur].fi < i)
		{
			addF(all[cur].se, -1);
			cur++;
		}
		//cout << i << ' ' << get(1, min(i - 1, a[i])) << endl;
		answer += get(1, min(i - 1, a[i]));
	}
	cout << answer << endl;
    return 0;
}