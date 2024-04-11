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

ll D,N;
int M;
pair<ll,ll> P[202020];
pair<int,int> Q[202020];
int nex[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>N>>M;
	FOR(i,M) cin>>P[i].first>>P[i].second;
	P[M].first=P[M].second=0;
	P[M+1].first=D;
	P[M].second=0;
	M+=2;
	sort(P,P+M);
	
	set<int> S;
	FOR(i,M) Q[i]={P[i].second,-i};
	sort(Q,Q+M);
	FOR(i,M) {
		x=-Q[i].second;
		if(x<M-1) nex[x]=*S.lower_bound(x);
		S.insert(x);
	}
	
	
	ll F=0,ret=0;
	FOR(i,M) {
		if(i) {
			F-=P[i].first-P[i-1].first;
			if(F<0) return _P("-1\n");
		}
		if(i==M-1) break;
		ll d=min(N,P[nex[i]].first-P[i].first);
		if(F<d) {
			ret+=(d-F)*P[i].second;
			F=d;
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}