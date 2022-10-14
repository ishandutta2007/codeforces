#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 5050, mod =998244353;
int dp[2][maxn];
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);	
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	for(int i = 0, j = 0; i < n; i++) {
		while(2*a[j] <= a[i]) j++;
		b[i] = j - (2*a[j] <= a[i]);
	}
	for(int i = 0, j = 0; i < n; i++) {
		while(j < n && a[j] < 2*a[i]) j++;
		c[i] = j;
	}
	a.push_back(1<<30);
	//for(int i = 0; i < n; i++) cout << a[i] << " " << b[i] << " " << a[c[i]] << endl;
	dp[1][0] = 1;
	for(int it = 1; it < n; it++) {
		int i = it&1;
		for(int j = 0; j < n; j++) {
			if(j) add(dp[i][j], dp[i][j-1]);
		}
		memset(dp[i^1], 0, sizeof dp[i^1]);
		for(int j = 0; j < n; j++) {
			//if(dp[i][j]) cout << it << " " << a[j] << " - " << dp[i][j] << endl;
			//else continue;
			if(b[j] - max(it-1, 0) > 0) {
				int t = dp[i][j]*1ll*(b[j]-max(it-1, 0))%mod;
				add(dp[i^1][j], t);
				add(dp[i^1][j+1], mod-t);
				//cout << j << " x " << j << endl;
			}
			//cout << a[c[it]] << " ; " << a[n-1] << endl;
			add(dp[i^1][c[j]], dp[i][j]);
		}
			
	}
	for(int j = 0; j < n; j++) {
		if(j) add(dp[n&1][j], dp[n&1][j-1]);
	}
	cout << dp[n&1][n-1] << '\n';
	return 0;
}