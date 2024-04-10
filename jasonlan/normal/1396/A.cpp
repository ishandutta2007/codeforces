#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxm=101000;
ll n,p[maxm],val;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
ll moder(ll x){
	x=((-x)%(n-1)+n-1)%(n-1);
	return x;
}
ll moder2(ll x){
	x=(x%n+n)%n;
	return x;
}
int main(){
	n=read();
	for(register int i=0;i<n;++i)
		p[i]=read();
	if(n==1)
		printf("1 1\n0\n1 1\n0\n");
	else if(n&1){
		printf("1 %lld\n",n);
		for(register int i=0;i<n;++i){
			if(i)putchar(' ');
			else{
				putchar('0');continue;
			}
			val=n*moder(p[i]);
			printf("%lld",val);
			p[i]+=val;
		}
		putchar('\n');
		printf("2 %lld\n",n);
		for(register int i=1;i<n;++i){
			if(i>1)putchar(' ');
			printf("%lld",-p[i]);
		}
		putchar('\n');
	}
	else{
		printf("2 %lld\n",n);
		for(register int i=1;i<n;++i){
			if(i>1)putchar(' ');
			val=(n-1)*moder2(p[i]);
			printf("%lld",val);
			p[i]+=val;
		}
		putchar('\n');
		printf("1 %lld\n",n);
		for(register int i=0;i<n;++i){
			if(i)putchar(' ');
			else{
				putchar('0');continue;
			}
			printf("%lld",-p[i]);
		}
		putchar('\n');
	}
	printf("1 1\n%lld",-p[0]);
	return 0;
}