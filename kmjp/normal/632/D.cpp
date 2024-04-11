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

int N,M;
int A[1010101];
int V[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]<=M) V[A[i]]++;
	}
	for(i=M;i>=1;i--) {
		for(j=i*2;j<=M;j+=i) V[j]+=V[i];
	}
	int ma=0,mai=0;
	for(i=M;i>=1;i--) if(V[i]>ma) ma=V[i],mai=i;
	
	if(ma==0) return _P("1 0\n");
	
	vector<int> VV;
	ll LCM=1;
	FOR(i,N) if(mai%A[i]==0) {
		VV.push_back(i+1);
		LCM=LCM*A[i]/__gcd((int)LCM,A[i]);
	}
	_P("%d %d\n",(int)LCM,VV.size());
	FOR(i,VV.size()) _P("%d%s",VV[i],(i==VV.size()-1)?"\n":" ");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}