#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>red(201);
vector<int>green(201);
vector<int>blue(201);
vector<vector<vector<int>>>dp(201,vector<vector<int>>(201,vector<int>(201)));
int f(int i, int j, int k){
	if(i+j+k<=1)return 0;
	if(dp[i][j][k])return dp[i][j][k];
	int ret = 0;
	if(i>0&&j>0)ret = max(ret,f(i-1,j-1,k)+red[i]*green[j]);
	if(i>0&&k>0)ret = max(ret,f(i-1,j,k-1)+red[i]*blue[k]);
	if(j>0&&k>0)ret = max(ret,f(i,j-1,k-1)+green[j]*blue[k]);
	dp[i][j][k] = ret;
	return ret;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int r,g,b;
	cin >> r >> g >> b;
	for(int i = 1; i<=r; i++){
		cin >> red[i];
	}
	for(int i = 1; i<=g; i++){
		cin >> green[i];
	}
	for(int i = 1; i<=b; i++){
		cin >> blue[i];
	}
	sort(red.begin(),red.begin()+r+1);
	sort(green.begin(),green.begin()+g+1);
	sort(blue.begin(),blue.begin()+b+1);
	cout << f(r,g,b) << "\n";
	return 0;
}