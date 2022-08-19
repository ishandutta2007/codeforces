#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 105;
const lint inf = 1e17;

int a[MAXN], n;
int dp[MAXN][MAXN][MAXN][2];

int f(int x, int y, int z, int prv){
	if(x == n) return 0;
	if(~dp[x][y][z][prv]) return dp[x][y][z][prv];
	if(a[x]){
		int ans = f(x + 1, y, z, a[x] % 2);
		if(prv != a[x] % 2) ans++;
		return dp[x][y][z][prv] = ans;
	}
	else{
		int ans = 1e9;
		if(y) ans = min(ans, f(x + 1, y - 1, z, 1) + (prv != 1));
		if(z) ans = min(ans, f(x + 1, y, z - 1, 0) + (prv != 0));
		return dp[x][y][z][prv] = ans;
	}
}

int main(){
	cin >> n;
	int odcnt = 0;
	int evcnt = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i]){
			if(a[i] % 2) odcnt--;
			else evcnt--;
		}
		if((i + 1) % 2) odcnt++;
		else evcnt++;
	}
	memset(dp, -1, sizeof(dp));
	cout << min(f(0, odcnt, evcnt, 0), f(0, odcnt, evcnt, 1)) << endl; 
}