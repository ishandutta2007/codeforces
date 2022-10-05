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

int N,M;
int S[101010];
int A[101010],D[101010];
int U[101010],V[101010];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 551100;
	vector<edge> E[MV];
	int itr[MV],lev[MV],mincut[MV]; //1source
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
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) break;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
		//
		ZERO(mincut);
		queue<int> Q;
		mincut[from]=1;
		Q.push(from);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(e.cap>0&&mincut[e.to]==0) mincut[e.to]=1, Q.push(e.to);
		}
		return fl;
	}
};
MaxFlow_dinic<ll> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>S[i];
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		D[U[i]]++;
		D[V[i]]++;
		
		mf.add_edge(300000,i,1);
		mf.add_edge(i,100000+U[i],1);
		mf.add_edge(i,100000+V[i],1);
	}
	int sum=M;
	FOR(i,N) if(S[i]) {
		if((A[i]+D[i])%2||abs(A[i])>D[i]) {
			cout<<"NO"<<endl;
			return;
		}
		x=(A[i]+D[i])/2;
		mf.add_edge(100000+i,300002,x);
		sum-=x;
	}
	if(sum<0) {
		cout<<"NO"<<endl;
		return;
	}
	mf.add_edge(300001,300002,sum);
	FOR(i,N) if(S[i]==0) mf.add_edge(100000+i,300001,M);
	x=mf.maxflow(300000,300002);
	if(x!=M) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		FOR(i,M) {
			FORR(e,mf.E[i]) if(e.to<=200000&&e.cap==1) cout<<e.to-99999<<" ";
			FORR(e,mf.E[i]) if(e.to<=200000&&e.cap==0) cout<<e.to-99999<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}