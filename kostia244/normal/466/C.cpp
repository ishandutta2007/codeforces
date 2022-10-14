#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define pi pair<ll, ll>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef double ld;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <vi> vvi;
typedef __V <__V<pi>> vvpi;
int n, suff = 0, pref = 0;
ll ans;
map<int, int> cnt;
vi a;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	for(auto& i : a) cin >> i, suff += i;
	cnt[a[0]]++;
	suff -= a[0];
	pref += a[0];
	for(int i = 1; i+1 < n; i++) {
		suff -= a[i];
		pref += a[i];
		if(2*suff == pref)
			ans += cnt[suff];//, cout << i << " " <<  cnt[suff] << "\n";
		cnt[pref]++;
	}
	cout << ans;
}