#include<bits/stdc++.h>

using namespace std;
#define LL long long
const int N=3e5+10;
const LL INF=1e18;
int P;
int add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
int n,m;
LL K;
LL a[N];
int it1[N],it2[N];
vector<int> L[N];
vector<int> R[N];
struct edge{
	int l,r;
}e[N];
int tp=0;
int ans[N];
int fa[N];
int q[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void MAIN(){
	scanf("%d%d%d",&n,&m,&K);
	LL s=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		s+=a[i];
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].l,&e[i].r);
		R[e[i].l].push_back(i);
		R[e[i].r].push_back(i);
	}
	if(s<(LL)(n-1)*K){
		puts("NO");
		return;
	}
	for(int i=1;i<=n;++i) {
		fa[i]=i;
		L[i].push_back(i);
	}
	int u,v,w,l,r,id,x,y;
	for(int i=1;i<=n;++i){
		u=find(i);
		while(a[u]>=K){
			v=0;
			while(it1[u]<L[u].size()){
				v=L[u][it1[u]];
				if(it2[v]<R[v].size()) {
					x=v;
					v=R[x][it2[x]];
					it2[x]++;
					y=e[v].l^e[v].r^x;
					break;
				}
				else{
					v=0;
					++it1[u];
					continue;
				}
			}
			if(v==0) break;
			x=find(x);y=find(y);
			if(x==y) continue;
			if(L[x].size()<L[y].size()){
				swap(x,y);
			}
			a[x]+=a[y];
			fa[y]=x;
			for(int j=0;j<L[y].size();++j){
				L[x].push_back(L[y][j]);
			}
			ans[++tp]=v;
			a[x]-=K;
			u=x;
		}
	}
	for(int i=1;i<=m;++i){
		x=find(e[i].l);
		y=find(e[i].r);
		if(x==y) continue;
		else{
			ans[++tp]=i;
			fa[x]=y;
		}
	}
	puts("YES");
	for(int i=1;i<=tp;++i){
		printf("%d\n",ans[i]);
	}
	return;
}

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/**/