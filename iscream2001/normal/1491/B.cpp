#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int n;
int a[110];
void MAIN(){
	int u,v;
    n=read();u=read();v=read();
    for(int i=1;i<=n;++i){
    	a[i]=read();
	}
	int ans=min(u,v)+v;
	for(int i=2;i<=n;++i){
		if(abs(a[i]-a[i-1])>1) ans=min(ans,0);
	}
	for(int i=2;i<=n;++i){
		if(abs(a[i]-a[i-1])==1) ans=min(ans,min(u,v));
	}
	printf("%d\n",ans);
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}