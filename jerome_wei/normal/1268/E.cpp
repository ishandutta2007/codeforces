#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int hed[N],to[N],nxt[N],cnt=1;
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
struct edge{
	int u,v,c;
	edge(int u=0,int v=0):u(u),v(v){}
}e[N];
int n,m,ccnt;
int dfn[N],num,pre[N];
typedef pair<int,int> pi;
vector<pi> dcc[N];
int mn[N],mx[N],chk[N];
inline void tarjan(int x){
	dfn[x]=++num;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			pre[v]=i;
			tarjan(v);
		}else{
			if(dfn[v]>dfn[x]){
				++ccnt;
				int nxt=v;
				e[i/2].c=ccnt;
				while(nxt!=x){
					e[pre[nxt]/2].c=ccnt;
					dcc[ccnt].push_back(pi(nxt,pre[nxt]/2));//this to next
					// cout << nxt << ":" << pre[nxt]/2 << " ";
					nxt=to[pre[nxt]^1];
				}
				dcc[ccnt].push_back(pi(nxt,i/2));
				// cout << nxt << ":" << i/2 << " ";
				// puts("");
			}
		}
	}
}

inline void q(vector<pi> &dcc,int id){
	int sz=dcc.size();
	int mn = 0,mx = 0;
	for(int i=1;i<sz;i++){
		if(dcc[i].second>dcc[mx].second)mx=i;
		if(dcc[i].second<dcc[mn].second)mn=i;
	}
	int F=1;
	int t=mn;
	while(t!=mx){
		int nxt=(t+1)%sz;
		F&=dcc[nxt].second>dcc[t].second;
		t=nxt;
	}
	t=mn;
	while(t!=mx){
		int nxt=(t-1+sz)%sz;
		F&=dcc[nxt].second>dcc[t].second;
		t=nxt;
	}
	// cout << dcc[mn].second << " " << dcc[mx].second << " " << F << endl;
	::mn[id]=dcc[mn].second,::mx[id]=dcc[mx].second,chk[id]=F;
}
int f[N],g[N];

int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		e[i].u=u,e[i].v=v; adde(u,v),adde(v,u);
	}
	tarjan(1);
	for(int i=1;i<=ccnt;i++){
		q(dcc[i],i);
	}
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=m;i;i--){
		int u=e[i].u,v=e[i].v;
		if(!e[i].c||mn[e[i].c]!=i||!chk[e[i].c]){
			f[u]=f[v]=g[i]=f[u]+f[v];
		}
		else{
			// cout << "?>" << endl;
			// cout << mx[e[i].c] << endl;
			f[u]=f[v]=g[i]=f[u]+f[v]-g[mx[e[i].c]];
		}
		// cout << g[i] << endl;
		// for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
	}
	for(int i=1;i<=n;i++)printf("%d ",f[i]-1);puts("");
}