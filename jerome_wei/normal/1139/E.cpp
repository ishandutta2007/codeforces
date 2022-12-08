#include<bits/stdc++.h>
using namespace std;
/*math*/
#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=2e6+5;
const int INF=0x3f3f3f3f;
int fl[N];
int out[N],in[N];
int TTT;
namespace graph{
    int hed[N],cnt=1,to[M],nxt[M],cap[M],flow[M],del[M];
    int S,T;
    int d[N];bool vis[N];
    void adde(int u,int v,int _cap){
//    	if(v<=20||(u<=10&&v==T))cout<<u<<" "<<v<<" "<<cnt+1<<"connectted"<<endl;
        ++cnt;to[cnt]=v,cap[cnt]=_cap,nxt[cnt]=hed[u],flow[cnt]=0;hed[u]=cnt;
        ++cnt;to[cnt]=u,cap[cnt]=0,nxt[cnt]=hed[v],flow[cnt]=0;hed[v]=cnt;
    	if(v == T)out[u] = cnt-1;
    	if(u == S)in[v] = cnt-1;
	}
    queue<int>Q;
    bool bfs(){
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        Q.push(S);vis[S]=1;
        while(!Q.empty()){
        //	if(TTT)cout<<Q.front()<<">>";
            int u=Q.front();Q.pop();
            for(int i=hed[u];i;i=nxt[i])if(!del[i]){
                int v=to[i];
        //        if(TTT)cout<<v<<",";
                if(!vis[v]&&cap[i]>flow[i]){
                    vis[v]=1,d[v]=d[u]+1;
                    Q.push(v);
                }
            }
        //    if(TTT)puts("");
        }
        return vis[T];
    }
    int dfs(int u,int F){
        if(u==T||!F)return F;
        int flownow=0;
        for(int i=hed[u];i;i=nxt[i])if(!del[i]){
            int v=to[i];if(d[v]!=d[u]+1)continue;
            int f=dfs(v,min(F,cap[i]-flow[i]));
            flownow+=f;
            F-=f;
            flow[i]+=f,flow[i^1]-=f;
            if(!F)break;
        }
        if(!flownow)d[u]=0;
        return flownow;
    }
    int fw=0;
    inline void deledge(int eid){
    	int v=to[eid],u=to[eid^1];
    	if(u>v)swap(u,v);
    	if(del[eid])return ;
		del[eid]=del[eid^1]=1;
    	if(flow[eid] != 0){
    		fw--;
			flow[in[u]] = flow[in[u]^1]=0;
    		flow[out[v]] = flow[out[v]^1]=0;
    	}
	} 
    int max_flow(){
        while(bfs()){
			fw+=dfs(S,INF);
        }
        return fw;
    }
}
using namespace graph;
int n,m,p[N],c[N];
int ans=4999;

int eid[N];
vector<int> edge[N];
int ccnt[5010][5010];
int edid[5010][5010];

inline void balance(){
	while(fw!=ans+1 && ans >= 0){
		int id=ans+1+m;
		bool t=0;
		for(size_t i=0;i<edge[id].size();i++){
			deledge(edge[id][i]);
			t=1;
		}
		if(t)max_flow();
		ans--;
	}
}

int main()
{
	cin >> n >> m;
	S=m+5000+3,T=m+5000+4;
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
		ccnt[c[i]][p[i]]++;
		if(ccnt[c[i]][p[i]]==1){
			adde(c[i],m + p[i]+1,1);
//			cout<<c[i]<<" "<<m+p[i]+1<<endl;
			edge[m+p[i]+1].push_back(cnt-1);
			edid[c[i]][p[i]] = cnt-1;
		}
	}
	for(int i=1;i<=m;i++){
		adde(S,i,1);
	}
	for(int j=0;j<5000;j++) adde(j+m+1,T,1);
	max_flow();
//	cout<<":??"<<fw<<endl;
	int Q;cin >> Q;
	balance();
//	cout<<":??"<<fw<<endl;

	while(Q--){
//		TTT=1;
		int x;scanf("%d",&x);
		ccnt[c[x]][p[x]]--;
		if(ccnt[c[x]][p[x]]==0){
			deledge(edid[c[x]][p[x]]);
		}
		max_flow();
		balance();
		printf("%d\n",ans+1);
	}
}