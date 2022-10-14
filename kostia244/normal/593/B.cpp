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
ld X, X1, k, b;
int n;
__V<pair<ld, ld>> a;
int main() {
	doin();
	cin >> n >> X >> X1;
	while (n--) {
		cin >> k >> b;
		a.pb({k, b});
	}
	sort(all(a), [](const pair<ld, ld>& a, const pair<ld, ld>& b) {
		return (a.first*X1+a.second) < (b.first*X1+b.second) || (fabs((a.first*X1+a.second) - (b.first*X1+b.second)) <= 1e-9 && b.first < a.first);
	});
	for(int i = 1; i < a.size(); i++) {
		if(fabs(a[i-1].first-a[i].first) <= 1e-9) continue;
		k = (a[i].second-a[i-1].second)/(a[i-1].first-a[i].first);
		if(k-X >= 1e-9 && X1-k >= 1e-9 )
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
}