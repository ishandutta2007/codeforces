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

int N,C;
int A[202020],B[202020];
ll SA[202020],SB[202020];
ll T[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N-1) {
		cin>>A[i];
		SA[i+1]=SA[i]+A[i];
	}
	FOR(i,N-1) {
		cin>>B[i];
		SB[i+1]=SB[i]+B[i];
	}
	
	ll mia=0,mib=0;
	FOR(i,N) {
		T[i]=min(SA[i]+mia,SB[i]+mib+C);
		mia=min(mia,T[i]-SA[i]);
		mib=min(mib,T[i]-SB[i]);
		cout<<T[i]<<" ";
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}