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
int n;
int a[510];
int b[510][510];
void dfs(int x,int y,int z,int w){
	b[x][y]=w;
	if(z==1) return;
	--z;
	if(y-1>=1&&b[x][y-1]==0) dfs(x,y-1,z,w);
	else dfs(x+1,y,z,w);
}
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			b[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		dfs(i,i,a[i],a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			printf("%d ",b[i][j]);
		}
		puts("");
	}
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}