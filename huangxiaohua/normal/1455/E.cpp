#pragma optimize(3)
#pragma optimize(2)
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int i,j,k,n,t,x[5],y[5],xx[5],yy[5],xxx[5],yyy[5];
ll res;
 
ll jl(ll a,ll b,ll c,ll d){
	return abs(a-c)+abs(b-d);
}
 
ll get(int a,int b,int c,int d,int e,int f,int g,int h){
	int sb[4]={1,2,3,4},i,j;
	ll res=1e13;
	res=min(res,jl(x[sb[1]],y[sb[1]],a,b)+jl(x[sb[2]],y[sb[2]],c,d)+jl(x[sb[3]],y[sb[3]],e,f)+jl(x[sb[0]],y[sb[0]],g,h));
	for(i=1;i<=23;i++){
		next_permutation(sb,sb+4);
		res=min(res,jl(x[sb[1]],y[sb[1]],a,b)+jl(x[sb[2]],y[sb[2]],c,d)+jl(x[sb[3]],y[sb[3]],e,f)+jl(x[sb[0]],y[sb[0]],g,h));
	}
	return res;
}
 
ll chky(int a,int b){
	int len=abs(y[b]-y[a]);
	ll res=1e13;
	res=min(res,get(x[a],y[a],x[a]-len,y[a],x[a],y[a]-len,x[a]-len,y[a]-len));
	res=min(res,get(x[a],y[a],x[a]+len,y[a],x[a],y[a]+len,x[a]+len,y[a]+len));
	res=min(res,get(x[a],y[a],x[a]-len,y[a],x[a],y[a]+len,x[a]-len,y[a]+len));
	res=min(res,get(x[a],y[a],x[a]+len,y[a],x[a],y[a]-len,x[a]+len,y[a]-len));
	return res;
}
 
ll chkx(int a,int b){
	
	int len=abs(x[b]-x[a]);
	//printf("%d %d %d\n",x[a],y[a],len);
	ll res=1e13;
	res=min(res,get(x[a],y[a],x[a]-len,y[a],x[a],y[a]-len,x[a]-len,y[a]-len));
	res=min(res,get(x[a],y[a],x[a]+len,y[a],x[a],y[a]+len,x[a]+len,y[a]+len));
	res=min(res,get(x[a],y[a],x[a]-len,y[a],x[a],y[a]+len,x[a]-len,y[a]+len));
	res=min(res,get(x[a],y[a],x[a]+len,y[a],x[a],y[a]-len,x[a]+len,y[a]-len));
	return res;
}
 
int main(){
	scanf("%d",&t);
	while(t--){
		res=1e13;
		for(i=1;i<=4;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(i=1;i<=4;i++){
			for(j=1;j<=4;j++){
				x[0]=x[i];y[0]=y[j];
				for(k=1;k<=4;k++){
					if(i==k||j==k){continue;}
					res=min(res,chkx(0,k));
					res=min(res,chky(0,k));
				}
			}
		}
		printf("%lld\n",res);
	}
}