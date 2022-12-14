#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;
#define yxl {puts("NO");return 0;}
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 300005
int a,b,c,d,st[N],fl,t;
int main()
{
	a=read(); b=read(); c=read(); d=read();
	if(a+c<b+d) {
		fl=1;
		swap(a,d);
		swap(b,c);
	}
	if(a+c-b-d>1)yxl
	
	if(a+c==b+d){
		if(c<d)yxl
		while(d){
			st[++t]=3; --d;
			st[++t]=2; --c;
		}
		while(b){
			st[++t]=1; --b;
			if(c)st[++t]=2,--c;else if(a)st[++t]=0,--a;
		}
		puts("YES");
		for(int i=1;i<=t;++i)printf("%d ",st[i]);
		return 0;
	}
	
	while(d){
		st[++t]=2; --c;
		st[++t]=3; --d;
	}
	
	if(t){
		st[++t]=2; --c;
	} else {
		if(c)st[++t]=2,--c;else if(a)st[++t]=0,--a;
	}
	if(c<0)yxl
	while(b){
		st[++t]=1; --b;
		if(c)st[++t]=2,--c;else if(a)st[++t]=0,--a;
	}
	if(fl)for(int i=1;i<=t;++i)st[i]=3-st[i];
	puts("YES");
	for(int i=1;i<=t;++i)printf("%d ",st[i]);
}
// 2 4  4 4