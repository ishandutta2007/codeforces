#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1010, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mat[maxn][maxn];
string ro[maxn], co[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	if(k == 1) {
		int a = 0, b = 0;
		for(int i = 0; i < 2*n-1; i++) {
			string s;
			cin >> s;
			a += count(all(s), 'E');
			b += s.size();
		}
		int ok = 4*a >= 3*b;
		cout << (ok?"YES\n":"NO\n");
		if(ok)
		for(int i = 1; i <= n; i++, cout << '\n')
			for(int j = 1; j <= m; j++)
				cout << "1 ";
		return 0;
	}
	for(int i = 0; i < 2*n-1; i++) {
		if(i%2 == 0) {
			cin >> ro[i/2];
		} else {
			string s;
			cin >> s;
			for(int j = 0; j < m; j++) co[j].push_back(s[j]);
		}
	}
	//for(int i = 0; i < m; i++) cout << co[i] << endl;
	int rev = 0;
	if(n > m) {
		swap(n, m);
		swap(ro, co);
		rev = 1;
	}
	//cout << rev << endl;
	for(int i = 0; i < n; i++) {
		int g = 0, b = 0;
		for(int j = 0; j < m; j++) {
			if(j == 0) mat[i][j] = 0;
			else mat[i][j] = mat[i][j-1] ^ (ro[i][j-1]=='N');
			if(i && (mat[i][j] == mat[i-1][j]) == (co[j][i-1]=='E')) g++;
			else b++;
			//if(j) cout << mat[i][j] << " -> " << mat[i][j-1] << " " << ro[i].size() << " " << j-1 << ro[i][j-1] << "\n";
		}
		//cout << endl;
		if(b > g) {
			for(int j = 0; j < m; j++) mat[i][j] ^= 1;
		}
	}
	cout << "YES\n";
	if(rev)
		for(int i = 0; i < m; i++, cout << '\n')
			for(int j = 0; j < n; j++)
				cout << 1+mat[j][i] << " ";
	else
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < m; j++)
				cout << 1+mat[i][j] << " ";
}