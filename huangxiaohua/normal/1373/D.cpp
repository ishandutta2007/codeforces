#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,m,sb[200500],a[200500],b[200500],a1,b1,res,mxa,mxb,rres,ans;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);res=rres=mxa=mxb=0;
		a1=m/2;b1=(m-1)/2;
		for(i=1;i<=m;i++){
			scanf("%d",&sb[i]);
			if(i%2==1){res+=sb[i];}
		}
		for(i=1;i<=a1;i++){
			a[i]=sb[i*2]-sb[i*2-1];
		}
		for(i=1;i<=b1;i++){
			b[i]=sb[i*2]-sb[i*2+1];
		}ans=0;
		for(i=1;i<=a1;i++){
			//printf("a%d\n",a[i]);
			ans=max(ans+a[i],a[i]);
			mxa=max(ans,mxa);
		}ans=0;
		for(i=1;i<=b1;i++){
			//printf("b%d\n",b[i]);
			ans=max(ans+b[i],b[i]);
			mxb=max(ans,mxb);
		}
		rres=max(res+mxa,res);
		rres=max(res+mxb,rres);
		printf("%lld\n",rres);
	}
}