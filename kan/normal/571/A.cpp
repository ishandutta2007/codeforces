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

ll sum(ll a, ll b)
{
	return (b - a + 1) * (a + b) / 2;
}

inline ll cnt(ll suml, ll sumr, ll xl, ll xr, ll yl, ll yr)
{
//	cout << "cnt " << suml << ' ' << sumr << ' ' << xl << ' ' << xr << ' ' << yl << ' ' << yr << endl;
	if (suml > sumr || xl > xr || yl > yr) return 0;
	if (xr - xl < yr - yl)
	{
		swap(xl, yl);
		swap(xr, yr);
	}
	ll ans = 0;
	{
		ll b = max((ll)0, suml - xl - yl);
		ll e = min(yr - yl - 1, sumr - xl - yl);
		if (e >= b) ans += sum(b + 1, e + 1);
	}
	{
		ll b = max((ll)0, xr + yr - sumr);
		ll e = min(yr - yl - 1, xr + yr - suml);
		if (e >= b) ans += sum(b + 1, e + 1);
	}
	{
		ll b = max(yr - yl, suml - xl - yl);
		ll e = min(xr - xl, sumr - xl - yl);
		if (e >= b) ans += (e - b + 1) * (yr - yl + 1);
	}
//	cout << ans << endl;
	return ans;
}

int main () {
	int a, b, c, l;
	scanf("%d%d%d%d", &a, &b, &c, &l);
	ll answer = 0;
	for (int i = 0; i <= l; i++) answer += cnt(a + i + 1, b + c + l - i, b, a + i, c, a + i);
	for (int i = 0; i <= l; i++) answer += cnt(b + i + 1, a + c + l - i, a, b + i - 1, c, b + i);
	for (int i = 0; i <= l; i++) answer += cnt(c + i + 1, a + b + l - i, a, c + i - 1, b, c + i - 1);
	cout << answer << endl;
//	cout << cnt(4, 6, 0, 4, 0, 3) << endl;
    re 0;
}