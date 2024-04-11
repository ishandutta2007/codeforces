#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5050, mod = 1e9 + 7;
int n, fid[maxn][maxn];
string s;

int dp[maxn][maxn], run[maxn][maxn], val[maxn];
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int can(int i, int j) {
	if(j >= n) return 0;
	int x = i+fid[i][j];
	int y = j+fid[i][j];
	if(x>=j||y>=n) return 1;
	return s[y] > s[x];
}
int mindp() {
	memset(dp, 0x3f, sizeof dp);
	memset(run, 0x3f, sizeof run);
	memset(val, 0x3f, sizeof val);
	for(int i = 1; i <= n; i++) dp[0][i] = 1;
	//cout << can(1, 3) << " " << fid[1][3] << endl;
	for(int i = 0; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			run[i][j] = min(run[i][j], run[i][j-1]);
			dp[i][j] = min(dp[i][j], run[i][j]);
			//cout << i << " " << j << " = " << dp[i][j] << '\n';
			if(j == n) continue;
			if(s[j] == '0') {
				dp[i][j] = 1<<30;
				continue;
			}
			int nxt = j + (j-i) + 1 - can(i, j);
			if(nxt > n) continue;
			//cout << ":: " << nxt << endl;
			run[j][nxt] = min(run[j][nxt], dp[i][j]+1);
		}
	}
	int ans = mod+1, cr = 0;
	for(int j = 1, i = n; i--; j=(j+j)%mod) {
		if(s[i] == '1') {
			(cr += j)%=mod;
			int z = 1<<30;
			for(int j = 0;  j < i; j++) {
				if((!(i-j>(n-i))&&can(j, i))||((i-j<(n-i)))) {
					z = min(z, dp[j][i]);
					//cout << i << " " << j << endl;
				}
			}
			//cout << i << " " << z << " " << cr << endl;
			if(z <= mod) {
			if(n-i < 15)
				ans = min(ans, z + cr + 1);
			else {
				if(ans >= mod)
				ans = (z+cr+1)%mod;
				break;
			}
			}
		}
		//cout << i << " " << (ans >= mod) << endl;
		if(i == 0 && ans >= mod) ans = (cr+1)%mod;
	}
	return ans;
}
int countdp() {
	memset(dp, 0, sizeof dp);
	memset(run, 0, sizeof run);
	for(int i = 1; i <= n; i++) dp[0][i] = 1;
	//cout << can(1, 3) << " " << fid[1][3] << endl;
	for(int i = 0; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			add(run[i][j], run[i][j-1]);
			add(dp[i][j], run[i][j]);
			if(j == n) continue;
			if(s[j] == '0') {
				dp[i][j] = 0;
				continue;
			}
			int nxt = j + (j-i) + 1 - can(i, j);
			if(nxt > n) continue;
			add(run[j][nxt], dp[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) add(ans, dp[i][n]);//, cout << i << " " << n << " _ " << dp[i][n] << endl;
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	n = s.size();
	memset(dp, 0, sizeof dp);
	for(int i = n; i--;)
		for(int j = i+1; j--;) {
			if(s[i] != s[j]) fid[i][j] = 0;
			else fid[i][j] = fid[i+1][j+1]+1;
			fid[j][i] = fid[i][j];
			//cout << i << " " << j << "  " << fid[i][j] << endl;
		}
	cout << countdp() << endl;
	cout << mindp() << endl;
}