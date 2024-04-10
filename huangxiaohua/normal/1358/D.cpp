#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL sb[1000555],i,j,n,x,a[200555][5],ans,tmp=0,mx=0;
 
int main(){
	for(i=1;i<=1000000;i++){
		sb[i]=i*(i+1)/2;
	}
	scanf("%lld%lld",&n,&x);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i][0]);
	}
	i=n;
	while(tmp<x){
		a[n][1]+=sb[a[i][0]];
		tmp+=a[i][0];
		if(tmp>=x){break;}
		i--;
		if(i<1){i=n;}
	}
	a[n][3]=i;
	a[n][2]=tmp;
	a[n][1]-=sb[tmp-x];
	mx=a[n][1];
	//printf("%lld %lld %lld %lld \n",mx,a[n][1],a[n][2],a[n][3]);
	for(i=n-1;i>=1;i--){
		tmp=a[i+1][2]-a[i+1][0];
		a[i][1]=a[i+1][1]-sb[a[i+1][0]]+sb[a[i+1][2]-x];j=a[i+1][3];
		if(tmp<x){for(j=a[i+1][3]-1;tmp<x;j--){
			if(j<1){j=n;}
			a[i][1]+=sb[a[j][0]];
			tmp+=a[j][0];
			if(tmp>=x){break;}
			if(j<1){j=n;}
		}
		}
		
		if(j==0){j=n;}
			a[i][3]=j;
			a[i][2]=tmp;
			a[i][1]-=sb[tmp-x];
			mx=max(mx,a[i][1]);
			//printf("%lld %lld %lld %lld \n",mx,a[i][1],a[i][2],a[i][3]);
	}
	printf("%lld",mx);
	return 0;
}