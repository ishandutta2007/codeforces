#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 5050, mod = 1e9 + 7, i2 = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a, b;
		for(int t, i = 0; i < n; i++) cin >> t, ((t&1)?a:b).pb(t);
		if(a.size()&1) {
			int ok = 0;
			for(auto i : a)
				for(auto j : b)
					ok |= abs(i-j) == 1;//, cout << i << " " << j << " " << abs(i-j)<< '\n';
			cout << (ok?"YES\n":"NO\n");
		} else cout << "YES\n";
	}
	return 0;
}