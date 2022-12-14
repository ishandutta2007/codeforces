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
#define N 140032 //\0//r n ////
char s[N],t[N];
int n,m,T,i,j;
//\n//_//
int main()
{
	T=read();
	while(T--){
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(i=m;i;--i)if(t[i]==49)break;
		for(j=n;j;--j)if(s[j]==49){
			if(n-j+1 < m-i+1)continue;
			cout<<(n-j+1)-(m-i+1)<<endl;
			break;
		}
	}
}