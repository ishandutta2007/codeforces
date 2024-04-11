#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 50000;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
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
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

int N;
MaxFlow_dinic<int> mf;
string S[1010][2];
map<string,int> M;

int val(string S) {
	return (S[0]-'A')*26*26+(S[1]-'A')*26+(S[2]-'A');
}

void solve() {
	int i,j,k,l,r,x,y; string s,t;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>s>>t;
		S[i][0]=s.substr(0,3);
		S[i][1]=s.substr(0,2)+t.substr(0,1);
		M[S[i][0]]++;
	}
	FOR(i,N) {
		mf.add_edge(0,10+i,1);
		mf.add_edge(10+i,3000+i,1);
		mf.add_edge(3000+i,4000+val(S[i][1]),1);
		if(M[S[i][0]]==1) {
			mf.add_edge(10+i,2000+i,1);
			mf.add_edge(2000+i,4000+val(S[i][0]),1);
		}
	}
	FOR(i,26*26*26) mf.add_edge(4000+i,1,1);
	if(mf.maxflow(0,1)!=N) return _P("NO\n");
	cout<<"YES"<<endl;
	FOR(i,N) {
		if(mf.E[3000+i][0].cap) cout<<S[i][1]<<endl;
		else cout<<S[i][0]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}