#include<bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,a[N],k,i,flag,dp1[N],dp2[N],c[N],exi;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;flag=exi=0;
		for(i=0;i<=n+2;++i)dp1[i]=dp2[i]=0;
		for(i=1;i<=n;++i)cin>>a[i];
		if(n==1){
			if(a[1]==k)cout<<"yes\n";
			else cout<<"no\n";
			continue;
		}
		for(i=1;i<=n;++i){
			if(a[i]==k)exi=1;
			if(a[i]<k)c[i]=1;
			else c[i]=-1;
		}
		for(i=1;i<=n;++i)dp1[i]=min(dp1[i-1],0)+c[i];
		for(i=n;i;--i)dp2[i]=min(dp2[i+1],0)+c[i];
//		for(i=1;i<=n;++i)cout<<dp1[i]<<" "<<dp2[i]<<"\n";
		for(i=2;i<n;++i){
			if(a[i]>=k){
				if(dp1[i-1]<=0||dp2[i+1]<=0){
					flag=1;
				}
			}
		}
		if(a[1]>=k)if(dp2[2]<=0)flag=1;
		if(a[n]>=k)if(dp1[n-1]<=0)flag=1;
		if(flag&&exi)cout<<"yes\n";
		else cout<<"no\n";
	}
}