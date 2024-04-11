#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000000
#define ALL(s) s.begin(),s.end()
#define SZ(x) int((x).size())
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb push_back
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int n,m;
const int N=1005;
char s[N][N];
int ata[N],sz[N];
bool isequal(int x,int y){
	for(int i=1;i<=n;i++)
		if(s[i][x]!=s[i][y])
			return 0;
	return 1;
}
vector<int>adj[N],g[N];
bool issubset(int x,int y){
	for(int i=1;i<=n;i++){
		if(s[i][x]=='1')
			continue;
		if(s[i][y]=='1')
			return 0;
	}
	return 1;
}
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;int f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, int cap){
	   // cout<<s<<" "<<t<<endl;
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	int dinic_dfs(int u, int f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				int df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	int max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		int result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(int delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};
int tap(int x){
    if(ata[x]==x)
        return x;
    return ata[x]=tap(ata[x]);
}
int val[N];
void merge(int x,int y){
    if((x=tap(x))==(y=tap(y)))
        return;
    if(sz[x]<sz[y])
        swap(x,y);
    ata[y]=x;
    sz[x]+=sz[y];
}
map<int,int>pm;
int cur;
int get_id(int x){
    if(pm.find(x)!=pm.end())
        return pm[x];
    return pm[x]=++cur;
}
int main(){
	//freopen("file.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	vector<int>vers;
	for(int i=1;i<=m;i++)ata[i]=i,sz[i]=1;
	for(int j=1;j<=m;j++){
		bool found=false;
		for(int k=1;k<j;k++)
			if(isequal(k,j)){
			    found=true;
			    merge(k,j);
				break;
			}
		if(found)
			continue;
		vers.pb(j);
	}
	int v=vers.size();
	Dinic nt(2*m+2);
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++){
			if(i==j)
				continue;
			int a=vers[i],b=vers[j];
			if(issubset(a,b)){
			    //cout<<a<<"$"<<b<<endl;
				nt.add_edge(a,b+m,1);
			}
		}
	int source=0,sink=2*m+1;
	for(int i=0;i<v;i++){
		nt.add_edge(source,vers[i],1);
		nt.add_edge(vers[i]+m,sink,1);
	}
	int k = v-nt.max_flow(source,sink);
	printf("%d\n",k);
	for(int i=0;i<v;i++){
	    int u=vers[i];
		fore(i,0,SZ(nt.g[u])){
		    //cout<<u<<" "<<nt.g[u][i].to<<" "<<nt.g[u][i].f<<endl;
			if(nt.g[u][i].f>0){
			    merge(nt.g[u][i].to-m,u);
			}
		}
	}
	for(int i=1;i<=m;i++){
	    int id = get_id(tap(i));
	    g[id].pb(i);
	    printf("%d ",id);
	}
	puts("");
	for(int j=1;j<=m;j++){
	    val[j]=INF;
	    for(int i=1;i<=n;i++)
	        val[j]-=(s[i][j]=='1');
	    printf("%d ",val[j]);
	}
	puts("");
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=k;j++){
	        int my_val=1;
	        for(auto doc: g[j]){
	            if(s[i][doc]=='0')
	                continue;
	            umax(my_val,val[doc]);
	        }
	        printf("%d ",my_val);
	    }
	    puts("");
	}
	return 0;
}