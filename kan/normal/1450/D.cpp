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

char answer[maxn];
int n;
int a[maxn];


void solve()
{
	scanf("%d", &n);
	set<int> was;
	int minmulti = n + 1;
	for (int i =0 ; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (was.count(a[i])) minmulti = min(minmulti, a[i]);
		was.insert(a[i]);
	}
	int ans = 0;
	int l = 0;
	int r = n - 1;
	while (ans + 1 < minmulti)
	{
		if (!was.count(ans + 1)) break;
		if (a[l] == ans + 1) l++;
		else if (a[r] == ans + 1) r--;
		else break;
		ans++;
	}
	if (was.count(ans + 1)) ans++;
	for (int i = 1; i <= n; i++) answer[i - 1] = '0';
	for (int i = 1; i <= ans; i++) answer[n - i] = '1';
	if (minmulti == n + 1) answer[0] = '1';
	answer[n] = 0;
	printf("%s\n", answer);
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