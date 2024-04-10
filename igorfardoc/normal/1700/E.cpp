#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vvi a;
vector<vector<bool>> bad;
vector<pair<int, int>> prob;
int ans = 0;

bool check(int i, int j) {
	if(a[i][j] == 1) return true;
	for(const auto[dx, dy] : mv) {
		int x = dx + i;
		int y = dy + j;
		if(x < 0 || y < 0 || x >= n || y >= m) continue;
		if(a[x][y] < a[i][j]) return true;
	}
	return false;
}

bool check(int i, int j, int x, int y) {
	swap(a[i][j], a[x][y]);
	if(!check(i, j) || !check(x, y)) {swap(a[i][j], a[x][y]); return false;}
	for(const auto& el : prob) {
		if(!check(el.first, el.second)) {swap(a[i][j], a[x][y]); return false;}
	}
	for(const auto[dx, dy] : mv) {
		int x1 = dx + i;
		int y1 = dy + j;
		if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
		if(!check(x1, y1)) {swap(a[i][j], a[x][y]); return false;}
	}
	for(const auto[dx, dy] : mv) {
		int x1 = dx + x;
		int y1 = dy + y;
		if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
		if(!check(x1, y1)) {swap(a[i][j], a[x][y]); return false;}
	}
	swap(a[i][j], a[x][y]);
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	a.assign(n, vi(m));
	bad.assign(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 1) continue;
			bool ok = false;
			for(const auto[dx, dy] : mv) {
				int x = dx + i;
				int y = dy + j;
				if(x < 0 || y < 0 || x >= n || y >= m) continue;
				if(a[x][y] < a[i][j]) {
					ok = true;
					break;
				}
			}
			if(!ok) {
				prob.push_back({i, j});
			}
		}
	}
	if(prob.size() == 0) {
		cout << 0;
		return 0;
	}
	if(prob.size() > 10) {
		cout << 2;
		return 0;
	}
	set<pair<int, int>> s;
	for(const auto& el : prob) {
		s.insert(el);
		for(const auto[dx, dy] : mv) {
			int x = dx + el.first;
			int y = dy + el.second;
			if(x < 0 || y < 0 || x >= n || y >= m) continue;
			s.insert({x, y});
		}
	}
	for(const auto& el : s) {
		bad[el.first][el.second] = true;
	}
	for(const auto& el : s) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(bad[i][j]) continue;
				if(check(i, j, el.first, el.second)) {++ans;}
			}
		}
	}
	vector<pair<int, int>> s1;
	for(const auto& el : s) {
		s1.push_back(el);
	}
	for(int i = 0; i < s1.size(); i++) {
		for(int j = i + 1; j < s1.size(); j++) {
			if(check(s1[i].first, s1[i].second, s1[j].first, s1[j].second)) ++ans;
		}
	}
	if(ans == 0) {
		cout << 2;
		return 0;
	}
	cout << 1 << ' ' << ans;

}