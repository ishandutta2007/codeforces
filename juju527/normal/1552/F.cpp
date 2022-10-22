#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,mod=998244353;
int x[maxn],y[maxn],s[maxn];
int f[maxn];
int sum[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read(),s[i]=read();
	for(int i=1;i<=n;i++){
		int p=upper_bound(x+1,x+n+1,y[i])-x;
		sum[i]=add(sum[i-1]+add(sub(sum[i-1]-sum[p-1])+add(add(x[p]-y[i])+add(x[i+1]-x[i]))));
		if(s[i]==0)f[i]=add(f[i-1]+add(x[i]-x[i-1]));
		else f[i]=add(f[i-1]+add(sub(sum[i-1]-sum[p-1])+add(x[p]-y[i])+add(x[i]-x[i-1])));
	}
	printf("%d\n",add(f[n]+1));
    return 0;
}