#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, a[105], m, b[22];
char str[22][5]; 
int dp[22][1<<20];

int f(int pos, int msk){
	if(pos == m) return 0;
	if(~dp[pos][msk]) return dp[pos][msk];
	if(*str[pos] == 'p'){
		int ret = f(pos + 1, msk);
		for(int j=0; j<n; j++){
			if((msk >> j) % 2 == 0){
				if(b[pos] == 1) ret = max(ret, f(pos + 1, msk ^ (1<<j)) + a[j]);
				else ret = min(ret, f(pos + 1, msk ^ (1<<j)) - a[j]);
			}
		}
		return dp[pos][msk] = ret;
	}
	if(b[pos] == 1){
		int ret = f(pos + 1, msk);
		for(int j=0; j<n; j++){
			if((msk >> j) % 2 == 0){
				ret = max(ret, f(pos + 1, msk ^ (1<<j)));
			}
		}
		return dp[pos][msk] = ret;
	}
	else{
		int ret = f(pos + 1, msk);
		for(int j=0; j<n; j++){
			if((msk >> j) % 2 == 0){
				ret = min(ret, f(pos + 1, msk ^ (1<<j)));
			}
		}
		return dp[pos][msk] = ret;
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
	cin >> m;
	n = min(n, m);
	for(int i=0; i<m; i++){
		cin >> str[i] >> b[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0);
}