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

int N,Q,F,D;
int A[1010101];
int V[1010101];
int ret[1202020];
vector<pair<int,int>> query[1010101];
vector<pair<int,int>> E[1010101];
set<int> S[1201010],As;

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
UF<500000> uf,uf2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>F>>D;
	F--;
	MINUS(V);
	set<int> As;
	FOR(i,N) {
		cin>>A[i];
		V[A[i]]=i;
		As.insert(A[i]);
		S[i].insert(i);
	}
	FOR(i,Q) {
		cin>>x>>y;
		query[y].push_back({x-1,i});
	}
	
	while(1) {
		FOR(i,N) if(S[i].size()==N) break;
		if(i<N) break;
		vector<vector<int>> cand;
		FOR(i,N) if(S[i].size()) {
			FORR(s,S[i]) As.erase(A[s]);
			int mi=1<<30;
			int tar=0;
			FORR(s,S[i]) {
				auto it=As.lower_bound(A[s]+D);
				if(it!=As.end()&&*it-(A[s]+D)<mi) mi=*it-(A[s]+D),x=s,tar=V[*it];
				if(it!=As.begin()&&(A[s]+D)-*prev(it)<mi) mi=(A[s]+D)-*prev(it),x=s,tar=V[*prev(it)];
				
				it=As.lower_bound(A[s]-D);
				if(it!=As.end()&&*it-(A[s]-D)<mi) mi=*it-(A[s]-D),x=s,tar=V[*it];
				if(it!=As.begin()&&(A[s]-D)-*prev(it)<mi) mi=(A[s]-D)-*prev(it),x=s,tar=V[*prev(it)];
			}
			cand.push_back({min(x,tar),max(x,tar),mi});
			FORR(s,S[i]) As.insert(A[s]);
		}
		FORR(c,cand) {
			x=uf[c[0]];
			y=uf[c[1]];
			if(x!=y) {
				k=uf(x,y);
				l=x+y-k;
				E[c[2]].push_back({c[0],c[1]});
				if(S[k].size()<S[l].size()) swap(S[k],S[l]);
				FORR(s,S[l]) S[k].insert(s);
				S[l].clear();
			}
		}
		
	}
	
	FOR(i,1010001) {
		FORR2(x,y,E[i]) uf2(x,y);
		FORR2(v,t,query[i]) ret[t]=uf2[F]==uf2[v];
	}
	
	
	FOR(i,Q) {
		if(ret[i]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}