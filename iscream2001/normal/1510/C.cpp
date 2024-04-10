#include <bits/stdc++.h>
using namespace std;
const int INF=1e4;
const int N=1e5+10;
void get_min(int &x,int y){
	if(x>y) x=y;
}
int n,m,cnt;
int vis[N];
int fa[N],F[N];
vector<int> R[N];
vector<int> used[N];
void dfs(int x){
	//cout<<x<<endl;
	int u,v;
	vis[x]=++cnt;
	for(int i=0;i<R[x].size();++i){
		if(R[x][i]==fa[x]) continue;
		u=R[x][i];
		if(vis[u]) {
			if(vis[u]<vis[x]){
				v=x;
				//cout<<u<<" "<<v<<" "<<fa[v]<<endl;
				while(v!=u){
					F[v]=0;
					v=fa[v];
				//	cout<<v<<endl;
				}
			}
			//cout<<u<<" "<<v<<endl
			continue;
		}
		fa[u]=F[u]=x;
		dfs(u);
	}
	return;
}
int ans;
int l[N],r[N];
int hhh[N],dep[N];
bool cmp(int x,int y){
	return dep[x]<dep[y];
}
void DP(int x,int RT){
	vis[x]=1;hhh[x]=x;
	for(int i=0;i<R[x].size();++i){
		if(vis[R[x][i]]) continue;
		dep[R[x][i]]=dep[x]+1;
		DP(R[x][i],RT);
		used[x].push_back(hhh[R[x][i]]);
	}
	if(used[x].size()==0) return;
	sort(used[x].begin(),used[x].end(),cmp);
	int L=0,R=used[x].size()-1;
	while(R>=2){
		++ans;
		l[ans]=used[x][R-1];
		r[ans]=used[x][R];
		R-=2;
	}
	if(R==0){
		hhh[x]=used[x][0];
	}
	else{
		if(dep[used[x][0]]-dep[x]>1||x==RT){
			++ans;
			l[ans]=used[x][R-1];
			r[ans]=used[x][R];
		}
		else{
			hhh[x]=used[x][1];
		}
	}
	return;
}
void MAIN(){
	int K;
	int x,y;cnt=0;
	for(int i=1;i<=n;++i) {
		vis[i]=0;
		fa[i]=F[i]=0;
		R[i].clear();
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&K);
		scanf("%d",&x);
		for(int j=2;j<=K;++j){
			scanf("%d",&y);
			R[x].push_back(y);
			R[y].push_back(x);
			swap(x,y);
		}
	}
	//cout<<"?"<<endl;
	dfs(1);
	//cout<<"?"<<endl;
	for(int i=1;i<=n;++i){
		R[i].clear();
		vis[i]=0;
		fa[i]=0;
		used[i].clear();
	}
	for(int i=1;i<=n;++i) if(F[i]){
		R[i].push_back(F[i]);
		R[F[i]].push_back(i);
	}
	ans=0;
	//cout<<"?"<<endl;
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			dep[i]=1;
			DP(i,i);
			if(dep[hhh[i]]-dep[i]>1){
				//cout<<hhh[i]<<endl;
				++ans;
				l[ans]=i;
				r[ans]=hhh[i];
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d %d\n",l[i],r[i]);
	}
	return;
}
int main(){
	int T=1;//scanf("%d",&T);
	//while(T--) MAIN();
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		MAIN();
	}
    return 0;
}