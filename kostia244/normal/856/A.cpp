#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<11, maxa = 1e7 + 333, mod = 1e9 + 7, i2 = (mod+1)/2;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	vector<int> diff(1e6 + 3, 0);
	for(auto i : a)
		for(auto j : a)
			diff[abs(i-j)] = 1;
	int x = 1;
	while(true) {
		int ok = 1;
		for(int i = 1; i <= n; i++) if(diff[x*i]) ok = 0;
		if(ok) break;
		x++;
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) cout << x*i << ' '; cout << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}