#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[3][30];
int p3[30];
map<pair<int,int>,pair<int,ll> > M[2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	p3[0]=1;
	FOR(i,N) p3[i+1]=p3[i]*3;
	FOR(i,N) cin>>A[0][i]>>A[1][i]>>A[2][i];
	
	for(ll mask=0;mask<p3[min(N,13)];mask++) {
		int t[3]={},tm=mask;
		FOR(i,min(N,13)) {
			x=tm%3, tm/=3;
			if(x==0) t[0]+=A[0][i],t[1]+=A[1][i];
			if(x==1) t[0]+=A[0][i],t[2]+=A[2][i];
			if(x==2) t[1]+=A[1][i],t[2]+=A[2][i];
		}
		M[0][{t[0]-t[1],t[0]-t[2]}]=max(M[0][{t[0]-t[1],t[0]-t[2]}], {t[0]+(1LL<<29),mask});
	}
	for(ll mask=0;mask<p3[max(0,N-13)];mask++) {
		int t[3]={},tm=mask;
		FOR(i,max(0,N-13)) {
			x=tm%3, tm/=3;
			if(x==0) t[0]+=A[0][13+i],t[1]+=A[1][13+i];
			if(x==1) t[0]+=A[0][13+i],t[2]+=A[2][13+i];
			if(x==2) t[1]+=A[1][13+i],t[2]+=A[2][13+i];
		}
		M[1][{t[1]-t[0],t[2]-t[0]}]=max(M[1][{t[1]-t[0],t[2]-t[0]}], {t[0]+(1LL<<29),mask*p3[13]});
	}
	
	ll co=-1LL<<40;
	ll best=-1;
	FORR(r,M[1]) if(M[0].count(r.first) && r.second.first+M[0][r.first].first>co) {
		co=r.second.first+M[0][r.first].first;
		best = r.second.second+M[0][r.first].second;
	}
	
	if(best==-1) _P("Impossible\n");
	else {
		FOR(i,N) {
			x=best%3;
			best/=3;
			if(x==0) _P("LM\n");
			if(x==1) _P("LW\n");
			if(x==2) _P("MW\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}