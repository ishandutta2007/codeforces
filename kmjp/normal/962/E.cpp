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
ll C[202020];
int T[202020];


ll hoge(int LL,int RR) {
	vector<ll> cand[2];
	cand[0].push_back(C[LL]);
	cand[1].push_back(C[LL]);
	int i;
	for(i=LL+1;i<RR;i++) cand[T[i]].push_back(C[i]);
	cand[0].push_back(C[RR]);
	cand[1].push_back(C[RR]);
	
	ll ma[2]={};
	FOR(i,cand[0].size()-1) ma[0]=max(ma[0],cand[0][i+1]-cand[0][i]);
	FOR(i,cand[1].size()-1) ma[1]=max(ma[1],cand[1][i+1]-cand[1][i]);
	return min(2*(C[RR]-C[LL]), 3*(C[RR]-C[LL])-ma[0]-ma[1]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	FOR(i,N) {
		cin>>C[i]>>s;
		if(s=="R") T[i]=0;
		if(s=="B") T[i]=1;
		if(s=="P") V.push_back(i);
	}
	
	if(V.empty()) {
		ll L[2]={1LL<<30,1LL<<30};
		ll R[2]={-1LL<<30,-1LL<<30};
		
		FOR(i,N) {
			L[T[i]]=min(L[T[i]],C[i]);
			R[T[i]]=max(R[T[i]],C[i]);
		}
		ll ret=max(0LL,R[0]-L[0])+max(0LL,R[1]-L[1]);
		cout<<ret<<endl;
		return;
	}
	
	ll ret=0;
	ll L[2]={C[V[0]],C[V[0]]};
	FOR(i,V[0]) L[T[i]]=min(L[T[i]],C[i]);
	ret+=(C[V[0]]-L[0])+(C[V[0]]-L[1]);
	ll R[2]={C[V.back()],C[V.back()]};
	for(i=V.back()+1;i<N;i++) R[T[i]]=max(R[T[i]],C[i]);
	ret+=(R[0]-C[V.back()])+(R[1]-C[V.back()]);
	
	FOR(i,V.size()-1) ret+=hoge(V[i],V[i+1]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}