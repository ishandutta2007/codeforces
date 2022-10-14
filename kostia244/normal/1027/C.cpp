#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<21;
const int mod = 998244353, inv2 = (mod+1)/2, rt = 733596141;
using ld = long double;
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	pair<ld, int> r = {1e18, 1<<30};
	vi b;
	for(int i = 0; i < a.size(); i++) {
		if((!i||a[i-1]!=a[i])&&(i+1==n||a[i]!=a[i+1])) continue;
		b.pb(a[i]);
	}
	a = b;
	for(int i = 0; i + 3 < a.size(); i++) {
		if(a[i] == a[i+1] && a[i+2] == a[i+3]) {
			r = min(r, {(ld)(a[i]+a[i+2])*(a[i]+a[i+2])/(ld)(a[i]*a[i+2]), i});
		}
	}
	//cout << r.first << " " << r.second << '\n';
	cout << a[r.second] << " " << a[r.second+2] << ' ';
	cout << a[r.second] << " " << a[r.second+2] << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
// 20998782977