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

int N,Q;
int ID[505050];
int A[505050];
int T,P,X;

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
priority_queue<pair<int,int>> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	int ON=N;
	FOR(i,N) {
		scanf("%d",&A[i]);
		ID[i]=i;
		C.push({-A[i],i});
	}
	scanf("%d",&Q);
	FOR(i,Q) {
		scanf("%d",&T);
		if(T==1) {
			scanf("%d%d",&P,&X);
			ID[P-1]=N;
			A[N]=X;
			C.push({-A[N],N});
			N++;
		}
		else {
			scanf("%d",&X);
			while(C.size() && -C.top().first<X) {
				x=C.top().second;
				C.pop();
				uf(x,N);
			}
			A[uf[N]]=X;
			C.push({-A[uf[N]],uf[N]});
			N++;
		}
	}
	
	FOR(i,ON) _P("%d ",A[uf[ID[i]]]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}