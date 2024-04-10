#include <cstdio>

int t;
long long n,p1,p2;
void get(long long x){
	long long cnt=0,v=(x-1)/3;
	while((1ll<<(cnt))<=x)cnt+=2;
//	printf("%d\n",cnt);
	cnt-=2;
	p1=cnt;
	p2=v-(((1ll<<(cnt))-1)/3)+1;
}
long long get1(){
	return (1ll<<(p1))+p2-1;
}
long long get2(long long a,long long b){
//	printf("%lld %lld\n",a,b);
	if(a==0)return 0;
	else{
		long long c=b,d=0;
		while(c>(1ll<<(a-2)))c-=1ll<<(a-2),++d;
		if(d<=1)return get2(a-2,c);
		else if(d==2)return get2(a-2,c)+(1ll<<(a-2));
		else return get2(a-2,c)+(1ll<<(a-2))+(1ll<<a);
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%lld",&n);
		get(n);
		if(n%3==1)printf("%lld\n",get1());
		else if(n%3==2)printf("%lld\n",(get1()<<1ll)-get2(p1,p2));
		else printf("%lld\n",get1()^((get1()<<1ll)-get2(p1,p2)));
	}
}