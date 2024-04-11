#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 16;

int n;
char str[MAXN][MAXN];

vector<lint> dp[1<<14][14];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> str[i];
	for(int i=1; i<(1<<n); i++){
		int pcnt = 0;
		for(int j=0; j<n; j++) if((i >> j) & 1) pcnt++;
		pcnt--;
		for(int j=0; j<n; j++){
			if((i >> j) & 1) dp[i][j].resize(1 << pcnt);
		}
	}
	for(int i=0; i<n; i++) dp[1<<i][i][0] = 1;
	for(int i=1; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			if((i >> j) & 1){
				for(int k=0; k<n; k++){
					if((i >> k) & 1) continue;
					int deg = str[j][k] & 1;
					for(int z = 0; z < sz(dp[i][j]); z++){
						dp[i | (1<<k)][k][2 * z + deg] += dp[i][j][z]; 
					}
				}
			}
		}
	}
	lint tmp[1 << 13] = {};
	for(int i=0; i<n; i++){
		for(int j=0; j<sz(dp[(1<<n)-1][i]); j++){
			tmp[j] += dp[(1<<n)-1][i][j];
		}
	}
	for(int i=0; i<(1<<(n-1)); i++) printf("%lld ", tmp[i]);
}