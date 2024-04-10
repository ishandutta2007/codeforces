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

int T;
int N;
string S;
ll L[202020],R[202020],U[202020],D[202020],X[202020],Y[202020];
ll PL[202020],PR[202020],PU[202020],PD[202020],PX[202020],PY[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,N) {
			X[i+1]=X[i];
			Y[i+1]=Y[i];
			if(S[i]=='D') X[i+1]++;
			if(S[i]=='A') X[i+1]--;
			if(S[i]=='W') Y[i+1]++;
			if(S[i]=='S') Y[i+1]--;
			
			L[i+1]=min(L[i],X[i+1]);
			R[i+1]=max(R[i],X[i+1]);
			D[i+1]=min(D[i],Y[i+1]);
			U[i+1]=max(U[i],Y[i+1]);
		}
		PL[N]=PR[N]=X[N];
		PU[N]=PD[N]=Y[N];
		for(i=N-1;i>=0;i--) {
			PL[i]=min(PL[i+1],X[i]);
			PR[i]=max(PR[i+1],X[i]);
			PD[i]=min(PD[i+1],Y[i]);
			PU[i]=max(PU[i+1],Y[i]);
		}
		ll ret=1LL<<60;
		for(i=0;i<=N;i++) {
			ret=min(ret,(max(R[i]-X[i],PR[i]-X[i]+0)-min(L[i]-X[i],PL[i]-X[i]+0)+1)*(max(U[i]-Y[i],PU[i]-Y[i]+0)-min(D[i]-Y[i],PD[i]-Y[i]+0)+1));
			ret=min(ret,(max(R[i]-X[i],PR[i]-X[i]+1)-min(L[i]-X[i],PL[i]-X[i]+1)+1)*(max(U[i]-Y[i],PU[i]-Y[i]+0)-min(D[i]-Y[i],PD[i]-Y[i]+0)+1));
			ret=min(ret,(max(R[i]-X[i],PR[i]-X[i]-1)-min(L[i]-X[i],PL[i]-X[i]-1)+1)*(max(U[i]-Y[i],PU[i]-Y[i]+0)-min(D[i]-Y[i],PD[i]-Y[i]+0)+1));
			ret=min(ret,(max(R[i]-X[i],PR[i]-X[i]+0)-min(L[i]-X[i],PL[i]-X[i]+0)+1)*(max(U[i]-Y[i],PU[i]-Y[i]+1)-min(D[i]-Y[i],PD[i]-Y[i]+1)+1));
			ret=min(ret,(max(R[i]-X[i],PR[i]-X[i]+0)-min(L[i]-X[i],PL[i]-X[i]+0)+1)*(max(U[i]-Y[i],PU[i]-Y[i]-1)-min(D[i]-Y[i],PD[i]-Y[i]-1)+1));
		}
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}