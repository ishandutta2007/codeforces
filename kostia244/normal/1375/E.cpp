#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	vector<int> b;
	for(int i = 0; i < n; i++) b.pb(a[i] = 1010*a[i] + i);
	sort(all(b));
	vector<array<int, 2>> r;
	for(int i = n; i--;) {
		int x = 1;
		for(int j = 0; j < n; j++) if(a[j] == b[i]) x = j;
		vector<array<int, 2>> l;
		for(int j = 0; j < x; j++) if(a[j] > a[x]) l.pb({a[j], j});
		//cout << i << " " << l.size() << '\n';
		sort(all(l));
		for(auto [t, f] : l) {
			swap(a[f], a[x]);
			r.pb({f, x});
		}
	}
	cout << r.size() << '\n';
	for(auto &i : r) cout << i[0]+1 << " " << i[1]+1 << '\n';
	
	return 0;
}