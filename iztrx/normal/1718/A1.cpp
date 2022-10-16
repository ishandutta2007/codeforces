#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define py cout<<"YES"
#define pn cout<<"NO"
int n,T,i,j,k,a[N],ans,s[N],dp[N],f[N];
map<int,int>p;
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n;++i)cin>>a[i],s[i]=a[i],a[i]^=a[i-1];
		p.clear();p[a[0]]=0;
		for(i=1;i<=n;++i){
			dp[i]=dp[i-1]+(s[i]!=0);
			if(a[i]==0||p[a[i]])dp[i]=min(dp[i],dp[p[a[i]]]+(i-p[a[i]]-1));
			p[a[i]]=i;
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}