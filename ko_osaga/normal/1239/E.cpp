#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())

int n, a[55];
bitset<1250005> dp[26][26];

void solve(int i){
	int sum0 = accumulate(a, a + i, 0);
	int num0 = i;
	int num1 = 1;
	for(int i=0; i<26; i++){
		for(int j=0; j<26; j++){
			dp[i][j] = 0;
		}
	}
	dp[num0][num1][sum0] = 1;
	for(int i=num0; i<=n; i++){
		for(int j=num1; j<=n; j++){
			if(i == num0 && j == num1) continue;
			dp[i][j] = 
				(dp[i-1][j] << a[i + j - 1]) | dp[i][j - 1];
		}
	}
}

int main(){
	cin >> n;
	for(int i=0; i<2*n; i++){
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	int tot = accumulate(a, a + 2 * n, 0);
	int ret = 1e9;
	int arg0 = -1;
	int arg1 = -1;
	for(int i=1; i<n+1; i++){
		solve(i);
		for(int j=0; j<1250005; j++){
			if(dp[n][n][j]){
				int sum0 = j + a[i];
				int sum1 = tot - j + a[0];
				if(ret > max(sum0, sum1)){
					ret = max(sum0, sum1);
					arg0 = i;
					arg1 = j;
				}
			}
		}
	}
	vector<int> l, r;
	for(int i=0; i<arg0; i++) l.push_back(a[i]);
	r.push_back(a[arg0]);
	solve(arg0);
	int px = n, py = n, pz = arg1;
	while(sz(l) < n || sz(r) < n){
		if(px > arg0 && pz >= a[px + py - 1] && dp[px - 1][py][pz - a[px + py - 1]]){
			l.push_back(a[px + py - 1]);
			pz -= a[px + py - 1];
			px--;
		}
		else{
			r.push_back(a[px + py - 1]);
			py--;
		}
	}
	sort(l.begin(), l.end());
	sort(r.rbegin(), r.rend());
	for(auto &i : l) cout << i << " ";
	cout << endl;
	for(auto &i : r) cout << i << " ";
	cout << endl;
}