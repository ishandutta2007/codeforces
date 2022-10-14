#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int m, a[63], dp[62][62*64/2][36];

int mat[66][66];

void recover(vector<array<int, 2>> deg, int st = 0) {
	sort(deg.begin()+st, deg.end());
	if(st+1 == deg.size()) {
		assert(!deg[st][0]);
		return;
	}
	int i = st+1;
	int cur = deg[st][1];
	while(deg[st][0]) {
		mat[cur][deg[i][1]] = 1;
		deg[st][0]--;
		i++;
	}
	while(i < deg.size()) {
		mat[deg[i][1]][cur] = 1, deg[i][0]--;
		i++;
	}
	recover(deg, st+1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> m;
	for(int i = 0; i < m; i++) cin >> a[i];
	sort(a, a+m);
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	for(int n = 0; n <= 61; n++) {
		if(n > a[m-1] && dp[n][n*(n-1)/2][m] >= 0) {
			cout << n << endl;
			int deg = n*(n-1)/2, i = m;
			vector<array<int, 2>> degs;
			while(n) {
				i = dp[n][deg][i];
				degs.push_back({a[i], --n});
				deg -= a[i];
			}
			reverse(all(degs));
			recover(degs, 0);
			for(int i = 0; i < degs.size(); i++, cout << '\n')
				for(int j = 0; j < degs.size(); j++)
					cout << mat[i][j];
			exit(0);
		}
		for(int ds = n*(n-1)/2; ds < 62*62/2; ds++) {
			for(int i = 0; i <= m; i++) if(dp[n][ds][i] >= 0) {
				if(i == m) continue;
				dp[n+1][ds+a[i]][i] = i;
				dp[n+1][ds+a[i]][i+1] = i;
			}
		}
	}
	
}