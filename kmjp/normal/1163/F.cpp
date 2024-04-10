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

int N,M,Q;
vector<pair<int,int>> E[202020];
int U[202020],V[202020],W[202020],mainpath[202020];
int inmp[202020];
ll D[202020][2];
int from[202020][2];
int frome[202020][2];
int id[202020][2];

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	SegTree_2(){val.resize(NV*2,1LL<<60);};
	
	V getval(int entry) {
		entry += NV;
		ll ret=val[entry];
		while(entry>1) entry>>=1, ret=min(ret,val[entry]);
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=min(val[k],v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--;
		V[i]--;
		E[U[i]].push_back({V[i],i});
		E[V[i]].push_back({U[i],i});
	}
	FOR(i,N) D[i][0]=D[i][1]=1LL<<60;
	D[0][0]=D[N-1][1]=0;
	priority_queue<pair<ll,int>> PQ;
	PQ.push({0,0});
	PQ.push({0,N+N-1});
	while(PQ.size()) {
		int cur=PQ.top().second%N;
		int id=PQ.top().second/N;
		ll co=-PQ.top().first;
		PQ.pop();
		if(D[cur][id]!=co) continue;
		FORR(e,E[cur]) {
			if(D[e.first][id]>co+W[e.second]) {
				from[e.first][id]=cur;
				frome[e.first][id]=e.second;
				D[e.first][id]=co+W[e.second];
				PQ.push({-D[e.first][id],id*N+e.first});
			}
		}
	}
	
	MINUS(inmp);
	vector<int> C;
	x=N-1;
	while(x) {
		C.push_back(x);
		mainpath[frome[x][0]]=1;
		x=from[x][0];
	}
	C.push_back(0);
	reverse(ALL(C));
	
	FOR(i,C.size()) {
		id[C[i]][0]=id[C[i]][1]=i;
		inmp[C[i]]=i;
	}
	vector<pair<ll,int>> cand;
	FOR(i,N) {
		if(inmp[i]==-1) id[i][0]=N+1;
		cand.push_back({D[i][0],i});
		cand.push_back({D[i][1],N+i});
	}
	sort(ALL(cand));
	FORR(c,cand) {
		x=c.second%N;
		y=c.second/N;
		FORR(e,E[x]) {
			if(mainpath[e.second]==0 && D[x][y]==D[e.first][y]+W[e.second]) {
				if(y==0) id[x][0]=min(id[x][0],id[e.first][0]);
				if(y==1) id[x][1]=max(id[x][1],id[e.first][1]);
			}
		}
	}
	/*
	FOR(i,N) {
		if(inmp[i]==-1) {
			if(id[i][0]<id[i][1]) st.update(id[i][0],id[i][1],D[i][0]+D[i][1]);
		}
		else {
			FORR(e,E[i]) if(mainpath[e.second]==0) {
				ll a=D[i][0]+D[e.first][1]+W[e.second];
				if(inmp[e.first]>inmp[i]) {
					st.update(id[i][0],id[e.first][0],a);
				}
				else {
					assert(a!=226920738);
					if(D[e.first][0]!=D[i][0]+W[e.second]) st.update(id[i][0],id[i][0]+1,a);
				}
			}
		}
	}
	*/
	FOR(i,M) if(mainpath[i]==0) {
		if(id[U[i]][0]<id[V[i]][1]) st.update(id[U[i]][0],id[V[i]][1],D[U[i]][0]+D[V[i]][1]+W[i]);
		if(id[V[i]][0]<id[U[i]][1]) st.update(id[V[i]][0],id[U[i]][1],D[V[i]][0]+D[U[i]][1]+W[i]);
	}
	
	while(Q--) {
		cin>>x>>y;
		x--;
		ll ret=D[N-1][0];
		if(y<=W[x]) {
			ret=min(ret,D[U[x]][0]+D[V[x]][1]+y);
			ret=min(ret,D[U[x]][1]+D[V[x]][0]+y);
		}
		else if(mainpath[x]) {
			ret=min(D[N-1][0]+(y-W[x]), st.getval(min(id[U[x]][0],id[V[x]][0])));
		}
		cout<<ret<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}