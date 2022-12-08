#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int hed[N],cnt,nxt[N],to[N];
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}

vector<int> e[N];
int dfn[N],num,dep[N];
bool lf[N];
int fa[N];
inline void dfs(int x,int pre){
	dfn[x]=++num;
	dep[x]=dep[pre]+1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(dfn[v])continue;
		dfs(v,x);
		e[x].push_back(v);
		fa[v]=x;
	}
	if(e[x].size()==0)lf[x]=1;
}
int n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
//		cout<<dep[i]<<" "<<(double)n/(double)k<<endl;
		if(dep[i]>=((double)n/(double)k)){
			puts("PATH");
			printf("%d\n",dep[i]);
			int t=i;
			while(t){
				printf("%d ",t);
				t=fa[t];
			}puts("");
			return 0;
		}
	}
	puts("CYCLES");
	int CNT=0;
	for(int x=1;x<=n;x++)if(lf[x]&&CNT<k){
		int lf1=0,lf2=0;++CNT;
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(v==fa[x])continue;
			if(!lf1)lf1=v;
			else lf2=v;
			if(lf1&&lf2)break;
		}
		int dep1=dep[lf1],dep2=dep[lf2];
		if(dep1<dep2)swap(lf1,lf2),swap(dep1,dep2);//dep1>dep2
		if((dep[x]-dep1+1)%3){
			printf("%d\n",dep[x]-dep1+1);
			int t=x;
			while(t!=lf1){
				printf("%d ",t);
				t=fa[t];
			}printf("%d\n",t);
		}else if((dep[x]-dep2+1)%3){
			printf("%d\n",dep[x]-dep2+1);
			int t=x;
			while(t!=lf2){
				printf("%d ",t);
				t=fa[t];
			}printf("%d\n",t);
		}else{
			printf("%d\n",2+dep1-dep2);
			int t=lf1;
			while(t!=lf2){
				printf("%d ",t);
				t=fa[t];
			}printf("%d\n",t);
			printf("%d\n",x);
		}
	}
}