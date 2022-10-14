#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vec = pair<ll, ll>;
ll dot(vec a, vec b) {
	return a.first*b.first + b.second*a.second;
}
ll cross(vec a, vec b) {
	return a.first*b.second - b.first*a.second;
}

int n;
vector<pair<vec, int>> v;
int main() {
	int x, y;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y;
		v.push_back({vec{x, y}, i});
	}
	stable_sort(v.begin(), v.end(), [](const pair<vec, int> &a, const pair<vec, int> &b) {
		int qa = a.first < vec{0, 0};
		int qb = b.first < vec{0, 0};
		if(qa!=qb) return qa<qb;
		return cross(a.first, b.first) < 0;
	});
	v.push_back(v[0]);
	pair<long double, pair<int, int>> ans = {-1, {0, 0}};
	for(int i = 1; i < v.size(); i++) {
		ll v1 = v[i].first.first*v[i].first.first + v[i].first.second*v[i].first.second,
		 v2 = v[i-1].first.first*v[i-1].first.first + v[i-1].first.second*v[i-1].first.second;
		int i1 = v[i].second, i2 = v[i-1].second;
		long double t = dot(v[i].first, v[i-1].first), _cos = (t/(long double)(v1))*(t/(long double)(v2));
		if(dot(v[i].first, v[i-1].first)<1e-12) _cos = -_cos;
		ans = max(ans, {_cos, {i1, i2}});
	}
	cout << ans.second.first << " " << ans.second.second << "\n";
}