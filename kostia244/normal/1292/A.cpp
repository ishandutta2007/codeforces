//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 2e5 + 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, mat[2][maxn], ans = 0;
int get(int l) {
	if(l>n) return 0;
	return (0==mat[0][l]+mat[0][l-1])||(0==mat[1][l]+mat[1][l-1]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ans = n-1;
	int r, c;
	for(int i = 0; i < m; i++) {
		cin >> r >> c, r--;
		ans -= get(c);
		ans -= get(c+1);
		mat[r][c]^=1;
		ans += get(c);
		ans += get(c+1);
		cout << (ans==n-1?"Yes":"No") << "\n";
	}
}