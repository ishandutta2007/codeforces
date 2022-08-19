#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 998244353;
const int MAXN = 2005;

vector<int> a;
lint d1[MAXN][MAXN][11];

lint f(int x, int y, int m){
	if(x == a.size()) return (y == 0 && m == 0);
	if(~d1[x][y][m]) return d1[x][y][m];
	lint ans1 = f(x + 1, y, (m + a[x]) % 11);
	lint ans2 = (y ? f(x + 1, y - 1, (m + 11 - a[x]) % 11) : 0);
	return d1[x][y][m] = (ans1 + ans2) % mod;
}

lint g(int x, int y, int c, int d, int m){
	if(x + y == a.size()) return (m == 0);
	if(~d1[x][y][m]) return d1[x][y][m];
	lint ans1 = (c ? g(x + 1, y, c, d, (m + a[x+y]) % 11) * (x + c) : 0);
	lint ans2 = (d ? g(x, y + 1, c, d, (m + 11 - a[x+y]) % 11) * (y + d) : 0);
	return d1[x][y][m] = (ans1 + ans2) % mod;
}

vector<lint> solve1(vector<int> v){
	a = v;
	lint ans = 1;
	for(int i=0; i<v.size()/2; i++){
		ans *= i + 1;
		ans %= mod;
	}
	for(int i=0; i<v.size() - (v.size() / 2); i++){
		ans *= i + 1;
		ans %= mod;
	}
	vector<lint> vv;
	for(int i=0; i<11; i++) vv.push_back(f(0, v.size() / 2, (11 - i) % 11) * ans % mod);
	return vv;
}


vector<lint> solve2(vector<int> v, int x, int y){
	a = v;
	vector<lint> ans;
	for(int i=0; i<11; i++){
		ans.push_back(g(0, 0, x, y, (11 - i) % 11));
	}
	return ans;
}

int zarisu(int x){
	int cnt = 0;
	while(x){
		x /= 10;
		cnt++;
	}return cnt;
}

int main(){
	int t, n, a[MAXN];
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++) cin >> a[i];
		vector<int> l, r;
		for(int i=0; i<n; i++){
			int x = a[i] % 11;
			int z = zarisu(a[i]) % 2;
			if(z == 0) r.push_back(x);
			else l.push_back(x);
		}
		for(int i=0; i<=n+2; i++){
			for(int j=0; j<=n+2; j++){
				memset(d1[i][j], -1, sizeof(d1[i][j]));
			}
		}
		auto x = solve1(l);
		for(int i=0; i<=n+2; i++){
			for(int j=0; j<=n+2; j++){
				memset(d1[i][j], -1, sizeof(d1[i][j]));
			}
		}
		auto y = solve2(r, (l.size() + 2) / 2, (l.size() + 1) / 2);
		lint ans = 0;
		for(int i=0; i<11; i++){
			ans += x[i] * y[(11 - i) % 11] % mod;
		}
		cout << ans % mod << endl;
	}
}