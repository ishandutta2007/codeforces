#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int U[505050],V[505050],T[505050];

vector<vector<int>> E;

int id;
int L[2][505050],R[2][505050],D[2][505050];
pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	R.second.push_back(v1.second);
	R.second.push_back(v2.second);
	return R;
}

template<class V,int NV> class SegTree_3 {
public:
	vector<V> ma,mi,rev;
	SegTree_3(){
		int i;
		ma.resize(NV*2,-1<<20);
		mi.resize(NV*2,1<<20);
		rev.resize(NV*2,0);
	};
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			rev[k]^=1;
			swap(ma[k],mi[k]);
			ma[k]=-ma[k];
			mi[k]=-mi[k];
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			mi[k]=min(mi[k*2],mi[k*2+1]);
			if(rev[k]) {
				swap(ma[k],mi[k]);
				ma[k]=-ma[k];
				mi[k]=-mi[k];
			}
		}
	}
	void build() {
		int i;
		for(i=NV-1;i>=1;i--) {
			ma[i]=max(ma[2*i],ma[2*i+1]);
			mi[i]=min(mi[2*i],mi[2*i+1]);
		}
	}
};
SegTree_3<int,1<<19> st[2];

void dfs(int cur,int pre,int cid,int d) {
	D[cid][cur]=d;
	L[cid][cur]=id++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,cid,d+1);
	R[cid][cur]=id;
	st[cid].ma[(1<<19)+L[cid][cur]]=st[cid].mi[(1<<19)+L[cid][cur]]=d;
}


void solve() {
	int i,j,k,l,x,y; string s;
	
	
	scanf("%d",&N);
	E.resize(N);
	FOR(i,N-1) {
		scanf("%d%d%d",&U[i],&V[i],&T[i]);
		U[i]--;
		V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	auto d=diameter(E);
	int root[2]={d.second[0],d.second[1]};
	FOR(i,2) {
		id=0;
		dfs(root[i],root[i],i,0);
		st[i].build();
		FOR(j,N-1) {
			if(T[j]) {
				if(D[i][U[j]]>D[i][V[j]]) st[i].update(L[i][U[j]],R[i][U[j]],1);
				else st[i].update(L[i][V[j]],R[i][V[j]],1);
			}
		}
	}
	
	scanf("%d",&M);
	while(M--) {
		scanf("%d",&x);
		x--;
		int ma=0;
		FOR(i,2) {
			if(D[i][U[x]]>D[i][V[x]]) st[i].update(L[i][U[x]],R[i][U[x]],1);
			else st[i].update(L[i][V[x]],R[i][V[x]],1);
			ma=max(ma,st[i].ma[1]);
		}
		
		cout<<ma<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}