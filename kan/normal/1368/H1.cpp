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

const int inf = 5 * maxn;

int dp[maxn][2];
int al[maxn], ar[maxn], au[maxn], ad[maxn];
char sl[maxn], sr[maxn], su[maxn], sd[maxn];
int n, m, nq;
int answer;

void add(int m, int *s, int *dp)
{
	for (int i = 0; i < m; i++)
	{
		dp[0] += s[i];
		dp[1] += (1 - s[i]);
	}
}

inline void toint(int n, char *s, int *a)
{
	for (int i = 0; i < n; i++) a[i] = (s[i] == 'R' ? 0 : 1);
}

void solve(int n, int m, int *sup, int *sdown, int *sleft, int *sright)
{
	for (int i =0 ; i <= n; i++) dp[i][0] = dp[i][1] = inf;
	dp[0][0] = 0;
	dp[0][1] = 0;
	add(m, sleft, dp[0]);
	for (int i = 0; i < n; i++)
	{
		dp[i + 1][0] = min(dp[i][0], dp[i][1] + m) + sup[i] + sdown[i];
		dp[i + 1][1] = min(dp[i][1], dp[i][0] + m) + (1 - sup[i]) + (1 - sdown[i]);
	}
	add(m, sright, dp[n]);
	answer = min(answer, dp[n][0]);
	answer = min(answer, dp[n][1]);
}

int main()
{
	int nq;
	scanf("%d%d%d", &n, &m, &nq);
	scanf("%s", sl);
	scanf("%s", sr);
	scanf("%s", su);
	scanf("%s", sd);
	toint(n, sl, al);
	toint(n, sr, ar);
	toint(m, su, au);
	toint(m, sd, ad);
	answer = inf;
	solve(n, m, al, ar, au, ad);
	solve(m, n, au, ad, al, ar);
	cout << answer << endl;
    return 0;
}