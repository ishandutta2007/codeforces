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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N;
int L[202020],R[202020];
int ret[202020];
int E[606060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	vector<int> MP;
	MP.push_back(-1<<30);
	MP.push_back(1<<30);
	FOR(i,N) {
		cin>>L[i]>>R[i];
		MP.push_back(L[i]-1);
		MP.push_back(L[i]);
		MP.push_back(R[i]);
	}
	
	sort(ALL(MP));
	MP.erase(unique(ALL(MP)),MP.end());
	MINUS(E);
	FOR(i,N) {
		L[i]=lower_bound(ALL(MP),L[i])-MP.begin();
		R[i]=lower_bound(ALL(MP),R[i])-MP.begin();
		E[R[i]]=i;
	}
	FOR(i,606000) if(E[i]>=0) {
		x=E[i];
		ret[x]=bt(R[x])-bt(L[x]-1);
		bt.add(L[x],1);
	}
	FOR(i,N) _P("%d\n"	,ret[i]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}