#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>

#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;
const int N = 100005;

ll c(ll n, ll m, int a) {
	return (n*m+a)/2;
}
 
ll c(ll x1, ll y1, ll x2, ll y2, int a) {
	return c(x2, y2, a)-c(x1-1, y2, a)-c(x2, y1-1, a)+c(x1-1, y1-1, a);
}
 
void solve() {
	ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll x5=max(x1, x3), y5=max(y1, y3), x6=min(x2, x4), y6=min(y2, y4);
	bool d=x5<=x6&&y5<=y6;
	ll a1=c(n, m, 1)-c(x1, y1, x2, y2, 1)-c(x3, y3, x4, y4, 1)+(x2-x1+1)*(y2-y1+1);
	if(d)
		a1+=c(x5, y5, x6, y6, 1)-(x6-x5+1)*(y6-y5+1);
	ll a2=c(n, m, 0)-c(x1, y1, x2, y2, 0)-c(x3, y3, x4, y4, 0)+(x4-x3+1)*(y4-y3+1);
	if(d)
		a2+=c(x5, y5, x6, y6, 0);
	cout << a1 << " " << a2 << "\n";

}
int main(){
    IOS;
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}