#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
const int N=1e5+10;
const LL P=998244353;
void add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}

void init(){
	return;
}
int n;
vector<int> V[N];
int fa[N];
LL a[N][2];
LL f[N][2];
void dfs(int x){
	int y=0;
	f[x][0]=f[x][1]=0;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y!=fa[x]){
			fa[y]=x;
			dfs(y);
			f[x][0]+=max(abs(a[x][0]-a[y][0])+f[y][0],abs(a[x][0]-a[y][1])+f[y][1]);
			f[x][1]+=max(abs(a[x][1]-a[y][0])+f[y][0],abs(a[x][1]-a[y][1])+f[y][1]);
		}
	}
	return;
}
void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&a[i][0],&a[i][1]);
		V[i].clear();
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	dfs(1);
	printf("%lld\n",max(f[1][0],f[1][1]));
	return;
}
int main(){
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}