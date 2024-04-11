#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 111, rt = 1<<10;
int n, m, mat[maxn][maxn];
vector<pair<string, int>> sol;
int row() {
	for(int i = 1; i <= n; i++) {
		int a = 0;
		for(int j = 1; j <= m; j++) {
			a += mat[i][j]>0;
		}
		if(a == m) {
			for(int j = 1; j <= m; j++) mat[i][j]--;
			sol.pb(pair<string, int>("row ", i));
			return 1;
		}
	}
	return 0;
}
int col() {
	for(int i = 1; i <= m; i++) {
		int a = 0;
		for(int j = 1; j <= n; j++) {
			a += mat[j][i]>0;
		}
		if(a == n) {
			for(int j = 1; j <= n; j++) mat[j][i]--;
			sol.pb(pair<string, int>("col ", i));
			return 1;
		}
	}
	return 0;
}
int sum() {
	int ans = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) ans += mat[i][j];
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> mat[i][j];
	while(sum()) {
		int ok = 0;
		if(n < m) {
			while(row()) ok++;
			while(col()) ok++;
		} else {
			while(col()) ok++;
			while(row()) ok++;
		}
		if(!ok) break;
	}
	if(sum()) return cout << -1, 0;
	cout << sol.size() << '\n';
	for(auto i : sol) cout << i.first << " " << i.second << '\n';
}