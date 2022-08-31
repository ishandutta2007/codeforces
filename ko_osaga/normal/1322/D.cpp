#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 2015;

int n, m, a[MAXN];
int s[MAXN], c[MAXN*2];
int dp[MAXN][MAXN];
int ds[MAXN][MAXN];
int up[MAXN];

int upbit(int x, int y, int z){
	int ret = 0;
	for(int i=0; i<12; i++){
		if((x >> i) & 1){
			ret += c[z + i + 1];
		}
		else break;
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> s[i];
	for(int i=1; i<=n+m; i++) cin >> c[i];
	for(int i=0; i<MAXN; i++){
		fill(dp[i] + 1, dp[i] + MAXN, -1e9);
		fill(ds[i], ds[i] + MAXN, -1e9);
	}
	fill(up, up + MAXN, -1e9);
	int ret = 0;
	for(int i=n; i; i--){
		for(int j=0; j<=n; j++) dp[i][j] = max(dp[i][j], ds[a[i]][j]);
		dp[i][0] = max(dp[i][0], up[a[i]]);
		for(int j=n-1; j>=0; j--){
			dp[i][j + 1] = max(dp[i][j + 1], 
			dp[i][j] + upbit(j, 1, a[i]) + c[a[i]] - s[i]);
		}
		ret = max(ret, *max_element(dp[i], dp[i] + MAXN));
		for(int j=0; j<=n; j++){
			for(int l=0; l<12; l++){
				int pos = a[i] + l;
				ds[pos][j >> l] = max(ds[pos][j >> l], dp[i][j]);
			}
			up[a[i] + 12] = max(up[a[i] + 12], dp[i][j]);
			/*
			for(int k=1; k<i; k++){
				if(a[k] >= a[i]){
					int l = a[k] - a[i];
					dp[k][j >> l] = max(dp[k][j >> l], dp[i][j]);
				}
			}*/
		}
		for(int j=1; j<=n; j++) up[j] = max(up[j], up[j-1]);
	}
	cout << ret << endl;
}