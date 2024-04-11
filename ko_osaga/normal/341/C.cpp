#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[2005];
int vis[2005];
int bino[2005][2005], fact[2005];
int dp[2005];

int main(){
	cin >> n;
	fact[0] = bino[0][0] = 1;
	for(int i=1; i<=n; i++){
		fact[i] = 1ll * fact[i-1] * i % mod;
		bino[i][0] = 1;
		for(int j=1; j<=i; j++){
			bino[i][j] = bino[i-1][j-1] + bino[i-1][j];
			bino[i][j] %= mod;
		}
	}
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] != -1) vis[a[i]] = 1;
	}
	int p1 = 0;
	for(int i=1; i<=n; i++){
		if(a[i] == -1){
			if(!vis[i]) p1++;
		}
	}
	int tot = count(a+1, a+n+1, -1);
	for(int i=p1; i>=0; i--){
		dp[i] = 1ll * bino[p1][i] * fact[tot - i] % mod;
		for(int j=i+1; j<=p1; j++){
			dp[i] += mod - 1ll * dp[j] * bino[j][i] % mod;
			dp[i] %= mod;
		}
	}
	cout << dp[0];
}