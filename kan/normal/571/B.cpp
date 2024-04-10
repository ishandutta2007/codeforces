#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

const ll inf = 1e18;

const int maxn = 300005;
const int maxk = 5005;

ll ans[maxk][maxk];
int n, k;
int a[maxn];


inline void upd(ll &a, ll b)
{
	a = min(a, b);
}

int main () {
	scanf("%d%d", &n, &k);
	for (int i =0 ; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int m = n % k;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= m; j++) ans[i][j] = inf;
	}
	ans[0][0] = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			int wh = i * (n / k) + j;
			int wh2 = wh + (n / k) - 1;
			upd(ans[i + 1][j], ans[i][j] + a[wh2] - a[wh]);
			if (wh2 + 1 < n) upd(ans[i + 1][j + 1], ans[i][j] + a[wh2 + 1] - a[wh]);
		}
	}
	cout << ans[k][m] << endl;
    re 0;
}