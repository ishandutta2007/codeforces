#include <bits/stdc++.h>
#include<map>
using namespace std;
typedef long long ll;
ll a[200009][2],dp1[200009],dp2[200009],dp3[200009];
int main(){
	ll x,y,gx=-1e12,gy=0,n;cin>>n;
	for(int j=1;j<n+1;j++){
		cin>>a[j][0]>>a[j][1];
	}
	a[n+1][0]=1e12;a[0][0]=-1e9;
	for(int i=1;i<n+1;i++){
		if(a[i][0]+a[i][1]<a[i+1][0])
			dp3[i]=max(dp3[i-1],max(dp2[i-1],dp1[i-1]))+1;
		dp2[i]=max(dp3[i-1],max(dp2[i-1],dp1[i-1]));
		if(a[i][0]-a[i][1]>a[i-1][0]+a[i-1][1])
			dp1[i]=dp3[i-1]+1;
		if(a[i][0]-a[i][1]>a[i-1][0])
			dp1[i]=max(dp1[i-1]+1,max(dp1[i],dp2[i-1]+1));
		//cout<<dp1[i]<<" "<<dp2[i]<<" "<<dp3[i]<<endl;
		
	}
	cout<<max(dp1[n],max(dp2[n],dp3[n]));
}