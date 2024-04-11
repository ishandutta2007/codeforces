#include<bits/stdc++.h>
#define comp loli
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int n;
array<ll, 30> empt;
pair<array<ll, 30>, array<ll, 30>> solve(vector<ll> f, ll b) {
	if(f.empty()) return {empt, empt};
	vector<ll> x[2];
	ll sv = 0, rv = 0;
	for(auto &i : f) {
		x[(i>>b)&1].push_back(i);
		if(((i>>b)&1) == 0) sv += x[1].size();
		else rv += x[0].size();
	}
	pair<array<ll, 30>, array<ll, 30>> ans = {empt, empt};
	ans.first[b] = sv;
	ans.second[b] = rv;
	if(b) {
		auto u = solve(x[0], b-1);
		auto v = solve(x[1], b-1);
		for(int i = 0; i < 30; i++) {
			ans.first[i] += u.first[i];
			ans.first[i] += v.first[i];
			ans.second[i] += u.second[i];
			ans.second[i] += v.second[i];
		}
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	fill(all(empt), 0);
	ll r = 0, v = 0;
	vector<ll> a(n);for(auto &i : a) cin >> i;
	auto t = solve(a, 29);
	for(int i = 30; i--;) {
		v += min(t.first[i], t.second[i]);
		if(t.second[i] < t.first[i]) r += 1<<i;
	}
	cout << v << " " << r << endl;
}