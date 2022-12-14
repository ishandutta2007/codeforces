#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int t,l,dp1[N],dp2[N],dp3[N],cnt,ans,i;
char ch[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",ch+1);l=strlen(ch+1);
		ans=1e8;
		
		dp1[0]=dp2[0]=dp3[0]=-1e8;
		for(i=1;i<=l;++i){
			dp1[i]=dp1[i-1];
			dp2[i]=dp2[i-1];
			dp3[i]=dp3[i-1];
			if(ch[i]=='1')dp1[i]=i,ans=min(ans,i-min(dp2[i],dp3[i])+1);
			else if(ch[i]=='2')dp2[i]=i,ans=min(ans,i-min(dp1[i],dp3[i])+1);
			else if(ch[i]=='3')dp3[i]=i,ans=min(ans,i-min(dp1[i],dp2[i])+1);
		}
		if(ans>l)cout<<"0\n";
		else cout<<ans<<"\n";
	}
	return 0;
}