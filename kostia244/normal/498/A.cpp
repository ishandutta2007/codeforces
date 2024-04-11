#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define all(x) x.begin(), x.end()
#define mod 998244353ll
//using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}
//-1 -1 1 3 -1
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <pi> vvi;
typedef __V< __V <pi>> vvpi;
float X, Y, X1, Y1, a,b, c, xt, xx;
int ans = 0, n;
int main() {
	doin();
	cin >> X >> Y >> X1 >> Y1;
	cin >> n;
	while(n--) {
		cin >> a >> b >> c;
		ans += ((a*X+b*Y+c<0)^(a*X1+b*Y1+c<0));
	}
	cout << ans;
}