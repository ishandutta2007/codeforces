#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int n;
vector<int> f[maxn], a;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	a.resize(n+1);
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		f[n-t].push_back(i);
	}
	int cs = 1;
	for(int i = 1; i <= n; i++) {
		if(f[i].size()%i) return cout << "Impossible\n", 0;
		int cc = 0;
		for(auto j : f[i]) {
			a[j] = cs;
			if(++cc == i) cc = 0, cs++;
		}
	}
	cout << "Possible\n";
	for(int i = 0; i < n; i++) cout << a[i] << " "; cout << '\n';
}