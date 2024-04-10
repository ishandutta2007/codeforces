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

const int maxn = 300005;

bool lok[maxn], rok[maxn];
int a[maxn];
int n;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%s\n", (a[0] < a[n - 1] ? "YES" : "NO"));
	return;
	for (int i = 0; i < n; i++) lok[i] = rok[i] = false;
	int curmin = -1;
	int ttmin = n + 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < ttmin)
		{
			ttmin = a[i];
		}
		if (a[i] > curmin)
		{
			lok[i] = true;
			curmin = ttmin;
		}
	}
	int curmax = n + 1;
	int ttmax = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] > ttmax)
		{
			ttmax = a[i];
		}
		if (a[i] < curmax)
		{
			rok[i] = true;
			curmax = ttmax;
		}
	}
	for (int i =0; i < n; i++) if (lok[i] && rok[i])
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
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