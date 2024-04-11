#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<vector<int>> X(100001), Y(100001);
	for(int t, x, y, i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> t;
			X[t].push_back(i);
			Y[t].push_back(j);
		}
	}
	auto c = [&](vector<vector<int>> a) {
		ll ans = 0;
		for(auto v : a) {
		sort(all(v));
			for(int i = 0; i < v.size(); i++) {
				ans += v[i]*1ll*i;
				ans += -v[i]*1ll*(v.size()-1-i);
			}
		}
		return ans;
	};
	cout << c(X)+c(Y) << endl;
}