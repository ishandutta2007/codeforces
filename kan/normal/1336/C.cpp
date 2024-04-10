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

const int MOD = 998244353;

const int maxn = 3005;

int ans[maxn][maxn];
char s[maxn], t[maxn];
int n, m;

inline void upd(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int main()
{
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	//reverse(t, t + m);
	reverse(s, s + n);
	//ans[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (n - i >= m) upd(ans[i][0], 1);
		for (int fr = 0; fr <= m && fr <= i; fr++)
		{
			int curans = ans[i][fr];
			//cout << i << ' ' << fr << ' ' << curans << endl;
			if (fr == m || t[fr] == s[i]) upd(ans[i + 1][min(fr + 1, m)], curans);
			int rem = n - i;
			int pl = fr + rem - 1;
			if (pl >= m || t[pl] == s[i]) upd(ans[i + 1][fr], curans);
		}
	}
	int answer = 0;
	for (int fr = 0; fr <= m; fr++) upd(answer, ans[n][fr]);
	printf("%d\n", answer);
    return 0;
}