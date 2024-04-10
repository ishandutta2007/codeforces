#include <cassert>
#include <cstdio>
#include <cmath>
#define ll long long

long long n,m,a[10001],I,J;
int k;
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
void exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-(a/b)*y;
}
inline ll mul(ll x, ll y, ll mod)
{
    return ( x * y - (ll) ( (long double) x / mod*y )*mod + mod ) % mod;     
}
int main(){
	scanf("%lld%lld%d",&n,&m,&k);
	long long v=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",a+i);
		if(log(v)+log(a[i])-log(gcd(a[i],v))>log(n)+1){
			puts("NO");
			return 0;
		}
		long long x,y,_g=gcd(v,a[i]),P=v*(a[i]/_g);
		long long A=J,B=((1-i)%a[i]+a[i])%a[i];
		if((A-B)%_g){
			puts("NO");
			return 0;
		}
		exgcd(v,a[i],x,y);
		x=(x%P+P)%P;
//		printf("%d %d %d %d %d\n",A,B,x,v,a[i]);
		J=(J+mul(mul(x,v,P),(((B-A)/_g)%P+P)%P,P))%P;
		v=P;
	}
	if(!J)J+=v;
	if(v>n||J>m-k+1){
		puts("NO");
		return 0;
	}
//	for(int i=1;i<=k;i++)
//		assert((J+i-1)%a[i]==0);
//	printf("%lld %lld\n",v,J);
	for(int i=1;i<=k;i++)
		if(gcd(v,J+i-1)!=a[i]){
			puts("NO");
			return 0;
		}
	puts("YES");
}