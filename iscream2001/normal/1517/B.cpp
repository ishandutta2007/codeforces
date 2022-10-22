#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL P=998244353;
const int INF=2e9;

const int N=1e5+10;
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
int n,m;
LL b[110][110];
bool vis[110][110];
void MAIN(){
	scanf("%d%d",&n,&m);
	LL ans=0,x;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%lld",&b[i][j]);
			vis[i][j]=0;
		}
	}
	LL mx=INF;
	int f;
	for(int k=1;k<=m;++k){
		mx=INF;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(vis[i][j]==0)mx=min(mx,b[i][j]);
			}
		}
		f=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(vis[i][j]==0&&b[i][j]==mx&&f==0){
					swap(b[i][j],b[i][k]);
					vis[i][k]=1;
					f=1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%lld ",b[i][j]);
		}
		puts("");
	}
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}