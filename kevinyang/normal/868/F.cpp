#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<int>arr(100005);
vector<int>freq(100005);
int cur = 0;
vector<vector<int>>dp(21,vector<int>(100005,(int)1e18));
int lv = 1; int rv = 0;
void f(int t, int l, int r, int lx, int rx){
	//[l,r] and [lx,rx)
	//lx, rx are the left and right bound of the dp values we are calculating
	//l,r are the left and right bound of best old index of dp[t-1];
	if(rx<=lx)return;
	int m = (lx+rx)/2;
	int idx = 0;
	int ans = (int)1e18;
	while(rv<m){
		rv++;
		cur+=freq[arr[rv]];
		freq[arr[rv]]++;
	}
	while(lv>min(m,r+1)+1){
		lv--;
		cur+=freq[arr[lv]];
		freq[arr[lv]]++;
	}
	while(lv<=min(m,r+1)){
		freq[arr[lv]]--;
		cur-=freq[arr[lv]];
		lv++;
	}
	while(rv>m){
		freq[arr[rv]]--;
		cur-=freq[arr[rv]];
		rv--;
	}
	for(int i = min(m,r+1); i>l; i--){
		cur+=freq[arr[i]];
		freq[arr[i]]++;
		if(cur+dp[t-1][i-1]<ans){
			ans = cur+dp[t-1][i-1];
			idx = i-1;
		}
		lv--;
	}
	dp[t][m] = ans;
	if(lx+1==rx)return;
	f(t,l,idx,lx,m);
	f(t,idx,r,m,rx);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	dp[0][0] = 0;
	cin >> n >> k;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=k; i++){
		f(i,0,n-1,1,n+1);
	}
	cout << dp[k][n] << "\n";
	return 0;
}