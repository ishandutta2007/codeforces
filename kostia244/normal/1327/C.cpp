//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using ld = long double;
const int maxn = 2e6 + 55, mod = 1000000007, i2 = (mod+1)/2;
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if(n*m==1) {
		cout << 0;return;}
	vector<pi> a(k), b(k);
	for(auto &i : a) cin >> i.first >> i.second;
	for(auto &i : b) cin >> i.first >> i.second;
	string ans = "";
	for(int i = 1; i < n; i++) ans += 'U';
	for(int i = 1; i < m; i++) ans += 'L';
	for(int i = 0; i < n; i++) {
		for(int j = 0; j+1 < m; j++) {
			ans += (i&1)?"L":"R";
		}
		if(i+1<n)
			ans += "D";
	}
	cout<<ans.size() << '\n'<< ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while(t--) solve();
}