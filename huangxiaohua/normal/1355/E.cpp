#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[100500],x,y,z,l,r,md1,md2,f1,f2,res=5e18;

ll get(ll k){
	ll xx=0,yy=0,zz=0,res,res2;
	for(int i=1;i<=n;i++){
		if(a[i]<k){xx+=k-a[i];}
		else{yy+=a[i]-k;}
	}
	res=xx*x+yy*y;
	zz=min(xx,yy);
	res2=zz*z;xx-=zz;yy-=zz;
	res2+=xx*x+yy*y;
	return min(res,res2);
}

int main(){
	scanf("%d%lld%lld%lld",&n,&x,&y,&z);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	l=0;r=1e9;
	while(l<=r){
		md1=l+(r-l)/3;
		md2=l+(r-l)*2/3;
		f1=get(md1);f2=get(md2);
		if(f1<=f2){
			res=min(res,f1);r=md2-1;
		}
		else{
			res=min(res,f2);l=md1+1;
		}
	}
	for(i=l-50;i<=l+50;i++){
		if(i<0){continue;}
		res=min(res,get(i));
	}
	printf("%lld",res);
}