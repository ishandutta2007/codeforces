#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
using namespace std;
using ll = int64_t;
const int maxn = 1<<25, mod = 1e9 + 7, B = 23000, R = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, z, x, y;
	cin >> n;
	map<array<int, 2>, vector<array<int, 2>>> xym;
	for(int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		xym[{x, y}].push_back({z, i+1});
	}
	vector<array<int, 2>> lo, ops;
	map<int, vector<array<int, 2>>> xm;
	for(auto &[C, v] : xym) {
		auto [x, y] = C;
		sort(all(v));
		for(int i = 0; i+1 < v.size(); i+=2) {
			ops.push_back({v[i][1], v[i+1][1]});
		}
		if(v.size()&1) {
			xm[x].push_back({y, v.back()[1]});
		}
	}
	for(auto &i : xm) {
		sort(all(i.second));
		for(int j = 0; j+1 < i.second.size(); j+=2) {
			ops.push_back({i.second[j][1], i.second[j+1][1]});
		}
		if(i.second.size()&1) lo.push_back({i.first, i.second.back()[1]});
	}
	sort(all(lo));
	for(int i = 1; i < lo.size(); i+=2) {
		ops.push_back({lo[i-1][1], lo[i][1]});
	}
	for(auto i : ops) cout << i[0] << " " << i[1] << '\n';
}