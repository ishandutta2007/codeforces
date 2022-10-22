#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=110+10;

ll a[mn];
ll dp[mn][mn],dp2[mn][mn][mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)for(int j=1;j<i;j++)a[i]=max(a[i],a[j]+a[i-j]);
	vector<ll>v(1);
	for(int i=0;i<n;i++){
		if(i&&s[i]!=s[i-1])v.push_back(0);
		v.back()++;
	}
	int m=n;
	n=v.size();
	memset(dp2,0xc0,sizeof(dp2));
	for(int i=0;i<n;i++)dp2[i][i][v[i]]=0;
    for(int d=0;d<n;d++){
    	for(int i=0;i+d<n;i++){
    		int j=i+d;
    		for(int k=i;k<j;k++)dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
    		if(!d)dp[i][j]=max(dp[i][j],a[v[i]]);
    		else if(d&1)dp[i][j]=max(dp[i][j],max(dp[i+1][j]+a[v[i]],dp[i][j-1]+a[v[j]]));
    		else{
    			for(int k=v[j];k<=m;k++){
    				for(int l=i;l<j;l+=2){
    					dp2[i][j][k]=max(dp2[i][j][k],dp2[i][l][k-v[j]]+dp[l+1][j-1]);
    				}
    			}
    			for(int k=0;k<=m;k++)dp[i][j]=max(dp[i][j],dp2[i][j][k]+a[k]);
    		}
    	}
    }
    printf("%lld",dp[0][n-1]);
}