#include<bits/stdc++.h>
#define ri register int
using namespace std;
int a,b,sum,ans=0;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	cin>>a>>b;
	sum=a+b;
	for(ri f=1,t,mnp,mxp,l=1,r;l<=sum;l=r+1,f=1){
		t=sum/l,r=sum/t;
		if((a+t)/(t+1)>a/t||(b+t)/(t+1)>b/t)continue;
		mnp=(a+t)/(t+1)+(b+t)/(t+1),mxp=a/t+b/t;
		mnp=max(mnp,l),mxp=min(mxp,r);
		ans+=mxp-mnp+1;
	}
	cout<<ans;
	return 0;
}