#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, lim;
int dp[55][55][2][205];
int bino[55][55];

int f(int x1, int y1, int x2, int y2, int p, int q){
	if(~dp[x1][y1][p][q]) return dp[x1][y1][p][q];
	if(q == 0) return p == 1 && x1 == 0 && y1 == 0;
	if(p == 0){
		int ret = 0;
		for(int j=0; j<=x1; j++){
			for(int k=0; k<=y1; k++){
				if(j == 0 && k == 0) continue;
				if(j + 2 * k <= lim / 50){
					ret += 1ll * f(x1 - j, y1 - k, x2 + j, y2 + k, 1, q-1) * (1ll * bino[x1][j] * bino[y1][k] % mod) % mod;
					ret %= mod;
				}
			}
		}
		return dp[x1][y1][p][q] = ret;
	}
	if(p == 1){
		int ret = 0;
		for(int j=0; j<=x2; j++){
			for(int k=0; k<=y2; k++){
				if(j == 0 && k == 0) continue;
				if(j + 2 * k <= lim / 50){
					ret += 1ll * f(x1 + j, y1 + k, x2 - j, y2 - k, 0, q-1) * (1ll * bino[x2][j] * bino[y2][k] % mod) % mod;
					ret %= mod;
				}
			}
		}
		return dp[x1][y1][p][q] = ret;
	}
}

int main(){
	cin >> n >> lim;
	memset(dp, -1, sizeof(dp));
	int c1 = 0, c2 = 0;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		if(t == 50) c1++;
		else c2++;
	}
	for(int i=0; i<=n; i++){
		bino[i][0] = 1;
		for(int j=1; j<=i; j++){
			bino[i][j] = (bino[i-1][j] + bino[i-1][j-1]) % mod;
		}
	}
	for(int i=0; i<=4*n; i++){
		if(f(c1, c2, 0, 0, 0, i)){
			cout << i << endl <<  f(c1, c2, 0, 0, 0, i);
			return 0;
		}
	}
	cout << -1 << endl << 0;
}