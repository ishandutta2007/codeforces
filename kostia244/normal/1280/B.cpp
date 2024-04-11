#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
int get(vector<vi> &mat, int x, int y, int x1, int y1) {
	int ans = mat[x1][y1];
	if(x) ans -= mat[x-1][y1];
	if(y) ans -= mat[x1][y-1];
	if(x&&y) ans += mat[x-1][y-1];
	return ans;
}
int can(vector<vi> &mat) {
	int n = mat.size();
	int m = mat[0].size();
	vector<vi> pref;
	pref.resize(n, vi(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			pref[i][j] = mat[i][j];
			if(i) pref[i][j] += pref[i-1][j];
			if(j) pref[i][j] += pref[i][j-1];
			if(i&&j) pref[i][j] -= pref[i-1][j-1];
		}
	}
	ll ans = 55;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j]) continue;
			ll t = 0;
			if(i&&get(pref, 0, 0, i-1, m-1)) t++;
			if(i!=n-1&&get(pref, i+1, 0, n-1, m-1)) t++;
			if(j&&get(pref, i, 0, i, j)) t++;
			if(j!=m-1&&get(pref, i, j, i, m-1)) t++;
//			cout << i << " " << j << " " << t << "\n";
			ans = min(ans, t);
		}
	}
//	cout << "======\n";
	return ans;
}
void solve() {
	ll n, m;
	vector<vi> mat, m2;
	cin >> n >> m;
	mat.resize(n, vi(m));
	m2.resize(m, vi(n));
	char c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c;
			mat[i][j] = (c=='P');
			m2[j][i] = mat[i][j];
		}
	}
	ll t = min(can(mat), can(m2));
	if(t>4) {cout<<"MORTAL\n";return;}
	cout <<t << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}