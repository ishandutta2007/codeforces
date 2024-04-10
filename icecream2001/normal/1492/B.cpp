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
int p[N],vis[N];
void MAIN(){
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;++i) {
    	scanf("%d",&p[i]);
    	if(p[i]>mx){
    		vis[i]=1;
    		mx=p[i];
		}
		else vis[i]=0;
	}
    for(int i=n;i>=1;--i){
    	if(vis[i]==1){
    		int j=i;
    		do{
    			printf("%d ",p[j]);
    			++j;
			}while(vis[j]==0&&j<=n);
		}
	}
	puts("");
    return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}