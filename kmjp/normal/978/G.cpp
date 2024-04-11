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
int S[101],D[101],C[101];
int NG[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>S[i]>>D[i]>>C[i];
		if(NG[D[i]]) return _P("-1\n");
		NG[D[i]]=M+1;
	}
	
	for(i=1;i<=N;i++) if(NG[i]==0) {
		int best=-1;
		FOR(j,M) if(C[j] && S[j]<=i && i<D[j]) {
			if(best==-1 || D[best]>D[j]) best=j;
		}
		if(best>=0) {
			NG[i]=best+1;
			C[best]--;
		}
	}
	FOR(i,M) if(C[i]) return _P("-1\n");
	FOR(i,N) cout<<NG[i+1]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}