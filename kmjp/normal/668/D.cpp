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

int N;
int A[1010101];
int T[1010101];
int V[1010101];
vector<int> E[1010101];
int R[1010101];

template<class V> class BIT_var {
public:
	int ME;
	vector<V> bit;
	void init(int count) {
		ME=1;
		while((1<<ME)<=count*2) ME++;
		bit.clear();
		bit.resize(1<<ME);
	}
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d%d%d",&A[i],&T[i],&V[i]);
	vector<int> VM;
	FOR(i,N) VM.push_back(V[i]);
	sort(ALL(VM));
	VM.erase(unique(ALL(VM)),VM.end());
	FOR(i,N) {
		V[i]=lower_bound(ALL(VM),V[i])-VM.begin();
		E[V[i]].push_back(i);
	}
	FOR(i,1010000) if(E[i].size()) {
		vector<int> TM;
		FORR(r,E[i]) TM.push_back(T[r]);
		sort(ALL(TM));
		TM.erase(unique(ALL(TM)),TM.end());
		FORR(r,E[i]) T[r]=lower_bound(ALL(TM),T[r])-TM.begin();
		
		BIT_var<int> bit;
		bit.init(E[i].size());
		FORR(x,E[i]) {
			if(A[x]==1) bit.add(T[x],1);
			if(A[x]==2) bit.add(T[x],-1);
			if(A[x]==3) R[x]=bit(T[x]);
		}
	}
	FOR(i,N) if(A[i]==3) _P("%d\n",R[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}