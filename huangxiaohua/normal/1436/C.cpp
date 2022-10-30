#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll ksm(ll k,ll p){
	ll res=1;
	while(p){
		if(p&1){res=res*k%M;
		}k=k*k%M;p>>=1;
	}return res;
}

int n,m,i,j,t,x,pos,da,xiao,l,r,mid;
ll res=1,jc[1050]={1};
int main(){
	scanf("%d%d%d",&n,&x,&pos);
	l=0;r=n;
	while(l<r){
		mid=(l+r)/2;
		//printf("%d %d %d %d\n",l,r,mid,pos);
		if(mid<pos){xiao++;l=mid+1;}
		if(mid>pos){da++;r=mid;}
		if(mid==pos){l=mid+1;}
	}
	//printf("%d %d\n",xiao,da);
	/*for(i=1;i<=1000;i++){
		jc[i]=jc[i-1]*i%M;
	}*/
	for(i=1;i<=xiao;i++){
		res=res*(x-i)%M;
	}
	for(i=1;i<=da;i++){
		res=res*(n-x+1-i)%M;
	}
	for(i=1;i<=n-xiao-da-1;i++){
		res=res*i%M;
	}
	printf("%lld\n",res);
}