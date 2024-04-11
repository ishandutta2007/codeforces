#include<bits/stdc++.h>
using namespace std;

#define INF int(1e9)
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db; 
typedef pair<int,int> pii;

const int maxn=205;
const int maxm=4005;
int n,m,p,s,t,ss,tt;

namespace Flow{
	int tot,S,T,V;
	int head[maxn],nxt[maxm*2],to[maxm*2],cap[maxm*2],cost[maxm*2];
	int dist[maxn],parv[maxn],pare[maxn];
	bool in[maxn];
	queue<int>q;
	void init(){
		tot=0;
		memset(head,-1,sizeof(head));
	}
	void addedge(int u,int v,int c,int co){
		nxt[tot]=head[u];to[tot]=v;cap[tot]=c;cost[tot]=co;head[u]=tot++;
		nxt[tot]=head[v];to[tot]=u;cap[tot]=0;cost[tot]=-co;head[v]=tot++;
	}
	int flow(){
		rep(i,V)in[i]=false,dist[i]=INF;
		dist[S]=0;
		in[S]=true;
		q.push(S);
		while(!q.empty()){
			int x=q.front();q.pop();
			in[x]=false;
			for(int i=head[x];~i;i=nxt[i]){
				if(cap[i]&&dist[to[i]]>dist[x]+cost[i]){
					dist[to[i]]=dist[x]+cost[i];
					parv[to[i]]=x;
					pare[to[i]]=i;
					if(!in[to[i]]){
						in[to[i]]=true;
						q.push(to[i]);
					}
				}
			}
		}
		if(dist[T]==INF)return -INF;
		int res=0;
		for(int i=T;i!=S;i=parv[i]){
			res+=cost[pare[i]];
			cap[pare[i]]--;
			cap[pare[i]^1]++;
		}
		return res;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	s = 1, t = n;
	Flow::init();
	ss=0;tt=n+1;
	Flow::S=n+2;Flow::T=Flow::S+1;Flow::V=Flow::T+1;
	Flow::addedge(Flow::S,tt,INF,0);
	Flow::addedge(t,Flow::T,INF,0);
	Flow::addedge(ss,s,INF,0);
	Flow::addedge(Flow::S,s,INF,0);
	REP(i,m){
		int u,v,d,c;
		scanf("%d%d%d",&u,&v,&d);
		Flow::addedge(u,v,1,d);
	}
	REP(i,n)Flow::addedge(i,tt,INF,0);
	vector<int> data;
	for(;;){
		int f=Flow::flow();
		if(f==-INF)break;
		data.push_back(f);
	}
	int q; scanf("%d",&q);
	while(q--){
		int p; scanf("%d",&p);
		ll s = 0;
		int c = 0;
		db ans = 1e18;
		for(int i=0; i<data.size(); i++){
			s += data[i];
			c ++;
		db cur=db(s+p)/db(c);
		if(cur<ans)ans=cur;
		else break;	
		}
	  printf("%.10lf\n",ans);
	}
	return 0;
}