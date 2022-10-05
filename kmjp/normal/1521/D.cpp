#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
vector<int> E[101010];
vector<int> TE[101010];
template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 101010;
	int NV;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		int i;
		FOR(i,NV) lev[i]=-1;
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to,int NV) {
		V fl=0,tf;
		this->NV=NV;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			for(int i=0;i<NV;i++) itr[i]=0;
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};
MaxFlow_dinic<int> mf;
int C[101010];
int vis[101010];

void dfs(int cur,int pre,int id) {
	C[cur]=id;
	if(id==0) {
		mf.add_edge(N,cur,2);
		if(pre!=-1) mf.add_edge(cur,pre,1);
	}
	else {
		mf.add_edge(cur,N+1,2);
		if(pre!=-1) mf.add_edge(pre,cur,1);
	}
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,id^1);
}

int dfs2(int cur,int pre) {
	vis[cur]=1;
	FORR(e,TE[cur]) if(e!=pre) {
		return dfs2(e,cur);
	}
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>N;
		FOR(i,N) E[i].clear(),TE[i].clear(),vis[i]=0;
		FOR(i,N+2) mf.E[i].clear(), E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,-1,0);
		
		x=mf.maxflow(N,N+1,N+2);
		vector<pair<int,int>> del,add;
		FOR(i,N) if(C[i]==0) {
			FORR(e,mf.E[i]) if(e.to<N) {
				if(e.cap==1) del.push_back({i+1,e.to+1});
				else {
					TE[i].push_back(e.to);
					TE[e.to].push_back(i);
				}
			}
		}
		int tar=-1;
		FOR(i,N) if(vis[i]==0&&TE[i].size()<=1) {
			if(tar!=-1) add.push_back({tar+1,i+1});
			tar=dfs2(i,i);
		}
		
		cout<<add.size()<<endl;
		FOR(i,add.size()) cout<<del[i].first<<" "<<del[i].second<<" "<<add[i].first<<" "<<add[i].second<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}