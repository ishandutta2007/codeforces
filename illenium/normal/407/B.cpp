#include<cstdio>
#include<iostream>
#define MOD 1000000007
using namespace std;

int n,p[1005];
long long f[1005];

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) p[i]=read();
    f[1]=0;
    for(int i=2;i<=n+1;i++) f[i]=(2*f[i-1]-f[p[i-1]]+2)%MOD;
    f[n+1]=(f[n+1]+MOD)%MOD;
    printf("%d\n",f[n+1]);
    return 0;
}