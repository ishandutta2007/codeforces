#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,B,Q;
pair<int,int> P[10101];

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 40000;
	vector<edge> E[MV];
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};
MaxFlow_Ford<int> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B>>Q;
	FOR(i,Q) cin>>P[i].first>>P[i].second;
	P[Q].first=P[Q].second=0;
	P[Q+1].first=B;
	P[Q+1].second=N;
	Q+=2;
	sort(P,P+Q);
	
	FOR(i,5) mf.add_edge(0,10+i,N/5);
	
	for(i=1;i<=B;i++) mf.add_edge(10+i%5,100+i,1);
	for(i=1;i<Q;i++) {
		for(x=P[i-1].first+1;x<=P[i].first;x++) mf.add_edge(100+x,10200+i,1);
		if(P[i].second<P[i-1].second) return _P("unfair\n");
		mf.add_edge(10200+i,20400,P[i].second-P[i-1].second);
	}
	if(mf.maxflow(0,20400)==N) cout<<"fair"<<endl;
	else cout<<"unfair"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}