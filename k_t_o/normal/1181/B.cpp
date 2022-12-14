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
#define N 100095
int cc,dd,f,l,fl,a[N],b[N],c[N],a0[N],b0[N],c0[N];
char s[N];  
int main()
{
	l=read();
	scanf("%s",s+1);
	if(l%2){
		cc=l/2+1;
		dd=l/2+2;
	}else {
		cc=l/2+1;  
		dd=l/2+1;
	}
	while(cc>1&&s[cc]==48)--cc;
	while(dd<=l&&s[dd]==48)++dd;
	if(cc>1){
		for(int i=cc-1;i;--i)a[cc-i]=s[i]-48;
		for(int i=l;i>=cc;--i)b[l-i+1]=s[i]-48;
		for(int i=1;i<=l;++i)c[i]=a[i]+b[i];
		for(int i=1;i<=l;++i)if(c[i]>9){
			c[i]-=10; ++c[i+1];
		}
	}
	if(dd<=l){
		for(int i=dd-1;i;--i)a0[dd-i]=s[i]-48;
		for(int i=l;i>=dd;--i)b0[l-i+1]=s[i]-48;
		for(int i=1;i<=l;++i)c0[i]=a0[i]+b0[i];
		for(int i=1;i<=l;++i)if(c0[i]>9){
			c0[i]-=10; ++c0[i+1];
		}
	}
	if(cc==1){
		f=l;while(!c0[f])--f;
		for(int i=f;i;--i)printf("%d",c0[i]);
		exit(0);
	}
	if(dd>l){
		f=l;while(!c[f])--f;
		for(int i=f;i;--i)printf("%d",c[i]);
		exit(0);
	}
	fl=1;
	for(int i=l;i;--i){
		if(c[i]>c0[i])break;
		if(c[i]<c0[i]){
			fl=0;
			break;
		}
	}
	if(fl){
		f=l;while(!c0[f])--f;
		for(int i=f;i;--i)printf("%d",c0[i]);
		exit(0);
	}
	f=l;while(!c[f])--f;
	for(int i=f;i;--i)printf("%d",c[i]);
}