#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,X,Y,x,y,a[6],p;
int main()
{
	n=read(); X=read(); Y=read();
	for(int i=1;i<=n;++i){
		x=read(); y=read();
		if(y<Y)++a[1];
		if(y>Y)++a[2];
		if(x<X)++a[3];
		if(x>X)++a[4];
	} 
	p=1;
	for(int i=2;i<=4;++i)if(a[i]>a[p])p=i;
	printf("%d\n",a[p]);
	if(p==1){
		printf("%d %d\n",X,Y-1);return 0;
	}
	if(p==2){
		printf("%d %d\n",X,Y+1);return 0;
	}
	if(p==3){
		printf("%d %d\n",X-1,Y);return 0;
	}
	if(p==4){
		printf("%d %d\n",X+1,Y);return 0;
	}
}