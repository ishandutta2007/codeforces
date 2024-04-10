#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m;
ll ax,ay,bx,by,x[105],y[105],sx,sy,t,res,sum;

ll dis(int a,int b){
	return llabs(x[a]-x[b])+llabs(y[a]-y[b]);
}

ll chkr(int x,int y,ll sum){
	ll res=1;
	if(sum>t){return 0;}
	int i,j,k;
	for(i=x+1;i<=y;i++){
		sum+=dis(i,i-1);
		if(sum>t){return res;}res++;
	}
	if(!x){return res;}
	sum+=dis(y,x-1);
	if(sum>t){return res;}
	res++;
	for(i=x-2;i>=0;i--){
		sum+=dis(i,i+1);
		if(sum>t){return res;}res++;
	}
	return res;
}

ll chkl(int x,int y,ll sum){
	ll res=1;
	if(sum>t){return 0;}
	int i,j,k;
	for(i=x-1;i>=y;i--){
		sum+=dis(i,i+1);
		if(sum>t){return res;}res++;
	}
	if(x==n){return res;}
	sum+=dis(y,x+1);
	if(sum>t){return res;}
	res++;
	for(i=x+2;i<=y;i++){
		sum+=dis(i,i-1);
		if(sum>t){return res;}res++;
	}
	return res;
}

int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&sx,&sy,&t);
	for(i=1;;i++){
		x[i]=x[i-1]*ax+bx;
		y[i]=y[i-1]*ay+by;
		if(x[i]>=3e16||y[i]>=3e16){n=i-1;break;}
	}
	for(i=0;i<=n;i++){
		sum=0;
		for(j=i;j<=n;j++){
			res=max(res,chkr(i,j,llabs(sx-x[i])+llabs(sy-y[i])));
		}
		for(j=i;j>=0;j--){
			res=max(res,chkl(i,j,llabs(sx-x[i])+llabs(sy-y[i])));
		}	
	}
	printf("%lld",res);
}