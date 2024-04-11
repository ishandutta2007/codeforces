#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
}

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef map<int, int> mii;
typedef __V<ll> vi;
typedef __V<pi> vpi;
typedef __V<pi> vvi;
typedef __V<__V<pi>> vvpi;

int n, m = 0, ans = 0, t;
vi v;

int main() {
	doin();
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		m = max(m, t);
		if(i >= m)
			ans++;
	}
	cout << ans;
}