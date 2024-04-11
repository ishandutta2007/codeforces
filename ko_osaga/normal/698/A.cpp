#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, a[105];

int dp[105][3];

int f(int x, int y){
	if(x == n) return 0;
	if(~dp[x][y]) return dp[x][y];
	int ret = f(x+1, 2) + 1;
	if(a[x] % 2 == 1 && y != 0){
		ret = min(ret, f(x+1, 0));
	}
	if(a[x] >= 2 && y != 1){
		ret = min(ret, f(x+1, 1));
	}
	return dp[x][y] = ret;

}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0, 2);
}