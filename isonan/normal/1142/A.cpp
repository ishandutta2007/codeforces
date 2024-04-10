#include <cstdio>
#include <algorithm>
using namespace std;

long long n,k,a,b,x=100000000000ll,y=0;
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
long long abs(long long x){
	return x<0?-x:x;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
	for(int dis=0;dis<n;dis++){
		long long s=(a-b)+dis*k,req=(n*k)/gcd(n*k,s);
		if(req>0)x=min(x,req),y=max(y,req);
		s=(a+b)+dis*k,req=(n*k)/gcd(n*k,s);
		if(req>0)x=min(x,req),y=max(y,req);
		s=(b-a)+dis*k,req=(n*k)/gcd(n*k,s);
		if(req>0)x=min(x,req),y=max(y,req);
		s=(-a-b)+dis*k,req=(n*k)/gcd(n*k,s);
		if(req>0)x=min(x,req),y=max(y,req);
	}
	printf("%I64d %I64d\n",x,y);
}