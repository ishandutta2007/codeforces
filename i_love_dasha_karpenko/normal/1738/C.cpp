#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 107;
int dp[N][N][2];
bool calc(int cnt0,int cnt1,bool odd){
	if (cnt0<0 || cnt1<0){
		return 1;
	}
	if (cnt0==0 && cnt1==0){
		return odd==0;
	}
	if (dp[cnt0][cnt1][odd]!=-1){
		return dp[cnt0][cnt1][odd];
	}
	bool v1 = min(calc(cnt0-1,cnt1-1,odd),calc(cnt0-2,cnt1,odd));
	if (cnt0-1==0 && cnt1==0){
		v1 = odd==0;
	}
	if (cnt0==0){
		v1 = 0;
	}
	bool v2 = min(calc(cnt0-1,cnt1-1,1-odd),calc(cnt0,cnt1-2,1-odd));
	if (cnt1-1==0 && cnt0==0){
		v2 = (1-odd)==0;
	}
	if (cnt1==0){
		v2 = 0;
	}
	dp[cnt0][cnt1][odd] = max(v1,v2);
	return max(v1,v2);
}
void solve(){
	int n;
	cin>>n;
	int cnt[2] = {0,0};
	for(int i = 1;i<=n;i+=1){
		int val;
		cin>>val;
		val %= 2;
		if (val<0){
			val += 2;
		}
		cnt[val] += 1;
	}
	if (calc(cnt[0],cnt[1],0)==0){
		cout<<"Bob\n";
	}
	else{
		cout<<"Alice\n";
	}
}
signed main(){
	memset(dp,-1,sizeof(dp));
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	for(int tt = 1;tt<=t;tt+=1){
		solve();
	}
}