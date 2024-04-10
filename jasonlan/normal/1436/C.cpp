#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=101000,mod=1e9+7;
int n,x,pos;
int qpow(int a,int k){
	int res=1;
	while(k){
		if(k&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		k>>=1;
	}
	return res;
}
int pr(int a){
	int res=1;
	for(register int i=1;i<=a;++i)
		res=1ll*res*i%mod;
	return res;
}
int C(int a,int b){
	if(b>a||b<0)return 0;
	return 1ll*pr(a)*qpow(pr(b),mod-2)%mod*qpow(pr(a-b),mod-2)%mod;
}
int main(){
	scanf("%d%d%d",&n,&x,&pos);
	int l=0,r=n,mid,lcnt=0,rcnt=0;
	while(l<r){
		mid=(l+r)>>1;
		if(mid<=pos){
			if(mid!=pos)++lcnt;
			l=mid+1;
		}
		else ++rcnt,r=mid;
	}
	printf("%lld\n",1ll*C(x-1,lcnt)*C(n-x,rcnt)%mod*pr(n-lcnt-rcnt-1)%mod*pr(lcnt)%mod*pr(rcnt)%mod);
	return 0;
}