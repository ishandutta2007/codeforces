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
int n,m;
char s[N],t[N];
int pre[N],suf[N];
void MAIN(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1,j=1;i<=m;++i,++j){
    	while(s[j]!=t[i]) ++j;
    	pre[i]=j;
	}
	for(int i=m,j=n;i>=1;--i,--j){
		while(s[j]!=t[i]) --j;
		suf[i]=j;
	}
	int ans=0;
	for(int i=1;i<m;++i){
		ans=max(ans,suf[i+1]-pre[i]);
	}
	printf("%d\n",ans);
    return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}