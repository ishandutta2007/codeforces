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
const int inf = 1e9;

int a[maxn], b[maxn];
int n , k;
queue<int> q;
bool inq[maxn];

void tryadd(int x)
{
	if (x < 0 || x >= n - 1) return;
	if (inq[x]) return;
	if (min(a[x], a[x + 1]) == 0 && max(a[x], a[x + 1]) == 1)
	{
		q.push(x);
		inq[x] = true;
		return;
	}
	if (x >= n - 2) return;
	int mx = max({a[x], a[x + 1], a[x + 2]});
	int mn = min({a[x], a[x + 1], a[x + 2]});
	int md = a[x] + a[x + 1] + a[x + 2] - mn - mx;
	if (mn == mx) return;
	if (md == -1) return;
	if (md == 0)
	{
		if (mx != 0 || mn != 0)
		{
			q.push(x);
			inq[x] = true;
			return;
		}
	} else
	{
		if (mn == -1)
		{
			q.push(x);
			inq[x] = true;
			return;
		}
	}
}

bool trymake(int x)
{
	if (min(a[x], a[x + 1]) == 0 && max(a[x], a[x + 1]) == 1)
	{
		a[x] = 0;
		a[x + 1] = 0;
		return true;
	}
	if (x >= n - 2) return false;
	int mx = max({a[x], a[x + 1], a[x + 2]});
	int mn = min({a[x], a[x + 1], a[x + 2]});
	int md = a[x] + a[x + 1] + a[x + 2] - mn - mx;
	if (mn == mx) return false;
	if (md == -1) return false;
	if (md == 0)
	{
		if (mx != 0 || mn != 0)
		{
			a[x] = a[x + 1] = a[x + 2] = 0;
			return true;
		}
	} else
	{
		if (mn == -1)
		{
			a[x] = a[x + 1] = a[x + 2] = 1;
			return true;
		}
	}
	return false;
}

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < k) a[i] = -1;
		else if (a[i] == k) a[i] = 0;
		else if (a[i] > k) a[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
		if (a[i] == 0) b[i] = 1;
	}
	for (int i = 0; i < n; i++) inq[i] = false;
	for (int i = 0; i < n; i++) tryadd(i);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		if (trymake(cur))
		{
			for (int j = cur - 2; j <= cur + 2; j++) tryadd(j);
		}
	}
	bool found = (*min_element(a, a + n) == 0 && *max_element(a, a + n) == 0);
	printf("%s\n", (found ? "yes" : "no"));
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