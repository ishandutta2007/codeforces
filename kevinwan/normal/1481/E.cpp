#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 1e6+10;
const ll mod = 1e9+7;

int a[mn];
int fn[mn],ln[mn],bes[mn],num[mn],dp[mn];
int cdp[mn];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	int ch=0;
	int ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(fn[a[i]]==0)fn[a[i]]=i;
		num[i]=num[ln[a[i]]]+1;
		ln[a[i]]=i;
	}
	memset(cdp,0x3f,sizeof(cdp));
	for(int i=1;i<=n;i++){
		cdp[a[i]]=min(cdp[a[i]],dp[i-1]-i+num[i]);
		bes[i]=i-num[i]+cdp[a[i]];
		dp[i]=0x3f3f3f3f;
		int f=fn[a[i]];
		if(i==ln[a[i]])dp[i]=i-num[i]+dp[f-1]-f+num[f];
		dp[i]=min(dp[i],dp[i-1]+1);
		ans=min(ans,bes[i]+n-i);
		//cerr<<bes[i]<<" "<<dp[i]<<endl;
	}
	printf("%d\n",ans);
}