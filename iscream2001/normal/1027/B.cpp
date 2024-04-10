#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long 
using namespace std;
LL n;
int q;
int main(){
	LL x,y,a,b,c,d;
	scanf("%I64d%d",&n,&q);
	b=n*n;d=(b+1)/2;
	while(q--){
		scanf("%I64d%I64d",&x,&y);
		a=x+y;b=(x-1)*n+y;
		if(a&1){
			if(n%2==0) ++b;
			c=b/2+d;
			printf("%I64d\n",c);
		}
		else{
			c=(b+1)/2;
			printf("%I64d\n",c);
		}
	}
	return 0;
}