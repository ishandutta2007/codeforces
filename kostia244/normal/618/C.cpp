#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
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
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <pi> vvi;
typedef __V< __V <pi>> vvpi;
int x, y, ans = 1, a1;
int n;
__V<pair<pi, int>> a;
int main() {
//	doin();
	cin >> n;
	while(n--) cin >> x >> y, a.pb({{x, y}, ans++});
	sort(all(a));
	ans = 2;
	//
	while(1) {
		if((a[0].xx-a[1].xx)*(a[1].yy-a[ans].yy) != (a[1].xx-a[ans].xx)*(a[0].yy-a[1].yy))
			break;
		ans++;
	}
	cout << a[0].second << " " << a[1].second << " " << a[ans].second << " ";
}