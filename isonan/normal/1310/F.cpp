#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#define ull unsigned long long

//std::map<std::pair<ull,ull>,ull>Mul;
ull ans[64][64],a,b;
ull dmul(ull a,ull b);
ull getmul(ull a,ull b){
	if(a==1||b==1)return a*b;
//	printf("getmul %llu %llu\n",a,b);
	ull n=0,p=0;
	while(n<5&&(1ull<<(1ull<<(n+1ull)))<=std::max(a,b))++n;
	n=(1ull<<(1ull<<n));
	if(a>=n&&b>=n)p=dmul(n*3ull/2ull,getmul(a/n,b/n));
	else if(a>=n)p=getmul(a/n,b)*n;
	else p=getmul(a,b/n)*n;
	return p;
}
ull dmul(ull a,ull b){
	ull p=0;
	for(;a;a-=a&-a)
		for(ull c=b;c;c-=c&-c)
			p^=getmul(a&-a,c&-c);
	return p;
}
ull mul(ull a,ull b){
	ull p=0;
	for(int i=0;i<64;i++)
		if((a&(1ull<<(ull)i)))
			for(int j=0;j<64;j++)
				if((b&(1ull<<(ull)j)))
					p^=ans[i][j];
	return p;
}
struct CRT{
	ull prod,val;
};
ull qsm(ull a,ull b){
	ull ans=1ull;
	while(b){
		if(b&1ull)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1ull;
	}
	return ans;
}
ull ksc(ull x, ull y, ull mod){
    return ( x * y - (ull) ( (long double) x / mod*y )*mod + mod ) % mod;     
}
ull rqsm(ull a,ull b,ull p){
	ull ans=1ull;
	while(b){
		if(b&1ull)ans=ksc(ans,a,p);
		a=ksc(a,a,p);
		b>>=1ull;
	}
	return ans;
}
CRT merge(CRT a,CRT b){
//	printf("%llu %llu %llu\n",b.prod,b.val,-1ull);
	if(a.val==-1ull||b.val==-1ull)return (CRT){a.prod*b.prod,-1ull};
	ull k1=ksc((b.val+b.prod-a.val%b.prod)%b.prod,rqsm(a.prod,b.prod-2,b.prod),b.prod);
	return (CRT){a.prod*b.prod,k1*a.prod+a.val};
}
CRT solve(ull p){
	ull bl=(ull)sqrt(p);
//	printf("%llu %llu\n",p,bl);
	ull a=qsm(::a,(-1ull)/p),
		b=qsm(::b,(-1ull)/p);
	std::set<ull>set;
	ull Mul=a,now=1;
	for(int i=0;i<bl;i++){
//		printf("%llu\n",now);
		set.insert(now);
		now=mul(now,Mul);
	}
	Mul=qsm(now,-2ull);
	now=1;
	for(int i=0;i<=bl+1;i++){
		if(set.count(mul(now,b))){
			now=qsm(now,-2ull);
			for(int j=0;j<bl;j++){
//				printf("%llu %llu\n",now,j);
				if(now==b)return (CRT){p,i*bl+j};
				now=mul(now,a);
			}
		}
		now=mul(now,Mul);
	}
	return (CRT){p,-1ull};
}
int T;
int main(){
	for(int i=0;i<64;i++)
		for(int j=0;j<64;j++)
			ans[i][j]=getmul(1ull<<(ull)i,1ull<<(ull)j);
//	for(;;){
//		ull a,b;
//		scanf("%llu%llu",&a,&b);
//		printf("%llu\n",qsm(a,b));
//	}
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%llu%llu",&a,&b);
		CRT ans=(CRT){1,0};
		ans=merge(ans,solve(3));
		ans=merge(ans,solve(5));
		ans=merge(ans,solve(17));
		ans=merge(ans,solve(257));
		ans=merge(ans,solve(641));
		ans=merge(ans,solve(65537));
		ans=merge(ans,solve(6700417));
		if(qsm(a,ans.val)!=b)puts("-1");
		else printf("%llu\n",ans.val);
	}
}