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

int N,X1,Y1,X2,Y2;
ll X[2020],Y[2020];
ll R1[2020],R2[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X1>>Y1>>X2>>Y2;
	
	set<ll> cand;
	cand.insert(0);
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		R1[i]=(X[i]-X1)*(X[i]-X1)+(Y[i]-Y1)*(Y[i]-Y1);
		R2[i]=(X[i]-X2)*(X[i]-X2)+(Y[i]-Y2)*(Y[i]-Y2);
		cand.insert(R1[i]);
	}
	
	ll mi=1LL<<62;
	FORR(r,cand) {
		ll ma=0;
		FOR(i,N) if(R1[i]>r) ma=max(ma,R2[i]);
		mi=min(mi,r+ma);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}