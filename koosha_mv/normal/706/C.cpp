#include<bits/stdc++.h>
using namespace std;
long long  n,f[100009],dp1[100009],dp2[100009],inf=1e15,ans;string s1,s2,gs1,gs2;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>f[i];
	dp1[0]=0,dp2[0]=f[0];
	for(int i=0;i<n;i++){
		cin>>s1;
		s2=s1; reverse(s2.begin(),s2.end());
		if(i!=0){
			dp1[i]=inf,dp2[i]=inf;
			if(s1>=gs1) dp1[i]=dp1[i-1];
			if(s1>=gs2) dp1[i]=min(dp1[i],dp2[i-1]);
			if(s2>=gs1)	dp2[i]=dp1[i-1]+f[i];
			if(s2>=gs2) dp2[i]=min(dp2[i],dp2[i-1]+f[i]);
		}
		gs1=s1,gs2=s2;
	}
	if(min(dp1[n-1],dp2[n-1])==1000000000000000) cout<<-1;
	else cout<<min(dp1[n-1],dp2[n-1]);
}