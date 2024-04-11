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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

int N,M;
int A[101010],B[101010],C[101010],TC[101010];
vector<pair<int,int>> E[101010];
vector<int> V[101010];
vector<int> T;
int did[101010];

void dfs(int cur) {
	int n0=0,n1=0;
	if(did[cur]) return;
	did[cur]=1;
	FORR(r,E[cur]) if(did[r.first]) {
		if(C[r.second]) n1++;
		else n0++;
	}
	if(n0&&n1) {
		T.push_back(-1);
		return;
	}
	if(n1) {
		T.push_back(cur);
		FORR(r,E[cur]) C[r.second]^=1;
	}
	FORR(r,E[cur]) dfs(r.first);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>s;
		A[i]--;
		B[i]--;
		TC[i]=(s=="B");
		
		E[A[i]].push_back({B[i],i});
		E[B[i]].push_back({A[i],i});
		uf(A[i],B[i]);
	}
	
	vector<int> R[2];
	FOR(i,2) {
		FOR(x,N) if(uf[x]==x) V[x].clear(), V[x].push_back(-1);
		FOR(j,2) {
			FOR(x,M) C[x]=TC[x]^i;
			ZERO(did);
			
			FOR(x,N) if(uf[x]==x) {
				T.clear();
				if(j==0) {
					T.push_back(x);
					FORR(r,E[x]) C[r.second]^=1;
				}
				dfs(x);
				//FORR(r,T) _P("<%d>",r);
				if(count(ALL(T),-1)==0 && (T.size()<V[x].size() || (V[x].size()&&V[x][0]==-1))) V[x]=T;//,_P("!%d:",T.size());
				//_P("%d %d %d %d\n",i,j,x);
			}
		}
		FOR(x,N) if(uf[x]==x) {
			if(V[x].size() && V[x][0]==-1) {
				R[i].clear();
				FOR(x,101010) R[i].push_back(1);
				break;
			}
			else {
				//_P("aa\n");
				if(R[i].size()<V[x].size()) swap(R[i],V[x]);
				FORR(r,V[x]) R[i].push_back(r);
			}
		}
	}
	if(R[0].size()>R[1].size()) swap(R[0],R[1]);
	if(R[0].size()>N) _P("-1\n");
	else {
		sort(ALL(R[0]));
		_P("%d\n",R[0].size());
		FORR(r,R[0]) _P("%d ",r+1);
		_P("\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}