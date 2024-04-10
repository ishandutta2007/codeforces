#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
const int N=3e5+10;
const LL P=998244353;
const LL INF=1e10;
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}

void init(){
	return;
}
int n,m;
LL f[605];
LL e[605][605];
LL d[605];
bool vis[605];
void sol(int x){
	for(int i=0;i<n;++i) {
		d[i]=INF;vis[i]=0;
	}
	d[x]=0;
	int z;LL y;
	for(int i=0;i<n;++i){
		z=0;y=INF;
		for(int j=0;j<n;++j){
			if(d[j]<y&&vis[j]==0){
				z=j;y=d[j];
			}
		}
		vis[z]=1;
		for(int j=0;j<n;++j){
			f[(j+y)%n]=e[z][j];
		}
		for(int j=0;j<n-1;++j){
			f[j+1]=min(f[j+1],f[j]+1);
		}
		f[0]=min(f[0],f[n-1]+1);
		for(int j=0;j<n-1;++j){
			f[j+1]=min(f[j+1],f[j]+1);
		}
		f[0]=min(f[0],f[n-1]+1);
		for(int j=0;j<n;++j){
			d[j]=min(d[j],d[z]+f[j]);
		}
	}
	for(int i=0;i<n;++i){
		printf("%lld",d[i]);
		if(i==n-1) puts("");
		else putchar(' ');
	}
	return;
}
void MAIN(){
	int u,v;LL w;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			e[i][j]=INF;
		}
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&u,&v,&w);
		e[u][v]=min(e[u][v],w);
	}
	for(int i=0;i<n;++i) sol(i);
	return;
}
int main(){
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}