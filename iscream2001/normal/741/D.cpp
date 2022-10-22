#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
const int E=400; 

int n,m;

int fa[N],c[N],siz[N],val[N],dep[N];

char s[5];

vector<int> V[N];

int ans[N];

int vis[(1<<22)+10];

int num;
int q[N],L[N],R[N];

void dfs1(int x){
//	cout<<x<<" "<<val[x]<<endl;
	q[++num]=x;
	L[x]=num;
	siz[x]=1;
	for(int i=0;i<V[x].size();++i){
		val[V[x][i]]=val[x]^(1<<c[V[x][i]]);
		dep[V[x][i]]=dep[x]+1;
		dfs1(V[x][i]);
		siz[x]+=siz[V[x][i]];
	}
	R[x]=num;
	return;
}

int son[N];

void dfs2(int x,int tp){
//	cout<<x<<" "<<tp<<endl;
	son[x]=0;
	for(int i=0;i<V[x].size();++i){
		if(siz[V[x][i]]>siz[son[x]]){
			son[x]=V[x][i];
		}
	}
	for(int i=0;i<V[x].size();++i){
		if(V[x][i]!=son[x]){
			dfs2(V[x][i],V[x][i]);
		}
	}
	if(son[x]) dfs2(son[x],tp);
	vis[val[x]]=max(vis[val[x]],dep[x]);
	ans[x]=vis[val[x]]-dep[x];
	for(int i=0;i<22;++i){
		ans[x]=max(ans[x],vis[val[x]^(1<<i)]-dep[x]);
	}
	//cout<<x<<" "<<ans[x]<<endl;
	for(int i=0;i<V[x].size();++i){
		int y=V[x][i];
		if(y!=son[x]){
			for(int j=L[y];j<=R[y];++j){
				if(vis[val[q[j]]])ans[x]=max(ans[x],vis[val[q[j]]]+dep[q[j]]-dep[x]-dep[x]);
				for(int k=0;k<22;++k){
					if(vis[val[q[j]]^(1<<k)])ans[x]=max(ans[x],vis[val[q[j]]^(1<<k)]+dep[q[j]]-dep[x]-dep[x]);
				}
			}
			for(int j=L[y];j<=R[y];++j){
				vis[val[q[j]]]=max(vis[val[q[j]]],dep[q[j]]);
			}
		}
	}
	for(int i=0;i<V[x].size();++i){
		ans[x]=max(ans[x],ans[V[x][i]]);
	}
	if(tp==x){
		for(int i=L[x];i<=R[x];++i){
			vis[val[q[i]]]=0;
		}
		//clear
	}
	return;
}

void MAIN(){
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d%s",&fa[i],s+1);
		V[fa[i]].push_back(i);
		c[i]=s[1]-'a';
	//	cout<<c[i]<<endl;
	}
	val[1]=0;dep[1]=1;
	num=0;
	dfs1(1);
//	cout<<"?"<<endl;
	dfs2(1,1);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	puts("");
	return;
}
int main(){
	int ttt=1;
	while(ttt--) MAIN();
    return 0;
}