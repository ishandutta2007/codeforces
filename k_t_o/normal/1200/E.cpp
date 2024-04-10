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

#define N 2199993

int n,op,j,tt,nx[N];
char s[N],g[N];

int main()
{
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1); op=strlen(s+1);
		if(i==1){
			for(int i=1;i<=op;++i)g[++tt]=s[i];
			continue;
		}
		j=0;
		for(int i=2;i<=op;++i){
			while(s[j+1]!=s[i]&&j)j=nx[j];
			if(s[j+1]==s[i])++j;
			nx[i]=j;
		}
		
		j=0;
		for(int i=max(1,tt-op+1);i<=tt;++i){
			while(g[i]!=s[j+1]&&j)j=nx[j];
			if(g[i]==s[j+1])++j;
		}
		
		for(int i=j+1;i<=op;++i)g[++tt]=s[i];
	} 
//	g[++tt]='\0';  // g[0]    \0??  //n                 //r
	cout<<g+1;
}