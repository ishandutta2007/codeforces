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
	int n;
	cin >> n;
	vi fr(n+1, 1);
	int g = -1, b = 0;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		int o = 0;
		for(int  k, j = 0; j < t; j++) {
			cin >> k;
			if(!o) {
				if(fr[k]) fr[k] = 0, o = 1;
			}
		}
		if(o==0) g = i+1;
	}
	for(int i = 1; i <= n; i++) if(fr[i]) b = i;
	if(g==-1) cout << "OPTIMAL\n";
	else cout << "IMPROVE\n" << g << " " << b << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	//t = 1;
	while(t--) solve();
}