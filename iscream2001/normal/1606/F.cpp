#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+10;
int n,m;
vector<int> V[N];
int fa[N],siz[N],er[N];
int son[N];
int ans[N];
vector< pair<int,int> > q[N];
void dfs1(int x){
	siz[x]=1;er[x]=0;
	for(int i=0;i<V[x].size();++i){
		if(V[x][i]!=fa[x]){
			fa[V[x][i]]=x;
			dfs1(V[x][i]);
			siz[x]+=siz[V[x][i]];
			++er[x];
		}
	}
	return;
}
int lim[N];
int F[23][N],cha[23][N];
void dfs2(int x,int cs){
	int y;
	son[x]=0;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y==fa[x]) continue;
		if(siz[y]>siz[son[x]]){
			son[x]=y;
		}
	}
	if(!son[x]){
		lim[x]=0;
		F[cs][0]=1;
		for(int i=0;i<q[x].size();++i){
			ans[q[x][i].second]=0;
		}
		return;
	}
	dfs2(son[x],cs);
	int L=lim[son[x]];
	cha[cs][lim[son[x]]+1]++;
	
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y==fa[x]||y==son[x]) continue;
		dfs2(y,cs+1);
		//if(x==7) cout<<"??? "<<lim[y]<<" "<<L<<endl;
		while(L<lim[y]){
			//cout<<"! "<<x<<" "<<L<<" "<<js<<endl;
			++L;
			F[cs][L]=0;
		}
		for(int j=0;j<=lim[y];++j){
			F[cs][j]+=F[cs+1][j];
		}
		cha[cs][lim[y]+1]++;
	}
	//cout<<"now "<<x<<endl;
	int hhh=0;
	for(int j=0;j<=L;++j){
		hhh+=cha[cs][j];
		F[cs][j]+=hhh;
	}
	//for(int j=0;j<=L;++j) cout<<F[cs][j]<<" ";cout<<endl;
	for(int i=0;i<q[x].size();++i){
		//if(x==7) cout<<"? "<<q[x][i].first<<endl;
		if(q[x][i].first>L){
			ans[q[x][i].second]=er[x];
		}
		else{
			ans[q[x][i].second]=F[cs][q[x][i].first];
		}
	}
	if(er[x]>L){
		lim[x]=er[x];
		for(int j=L+1;j<=er[x];++j){
			F[cs][j]=er[x];
		}
	}
	else{
		lim[x]=L;
	}
	while(lim[x]>0&&F[cs][lim[x]]-lim[x]<1){
		lim[x]--;
	}
	for(int j=0;j<=lim[x];++j){
		F[cs][j]-=j;
		if(F[cs][j]<1) F[cs][j]=1;
	}
	cha[cs][lim[son[x]]+1]--;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y==fa[x]||y==son[x]) continue;
		cha[cs][lim[y]+1]--;
	}
	return;
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	dfs1(1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		q[u].push_back(make_pair(v,i));
	}
	dfs2(1,0);
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
    return 0;
}