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
ll T;
ll A[202020];
int X[202020];
ll L[202020],R[202020],C[202020];
int S[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) cin>>A[i];
	A[N]=2*1000000000000000000LL;
	
	FOR(i,N) {
		cin>>X[i];
		if(X[i]<i+1) {
			cout<<"No"<<endl;
			return;
		}
		if(i&&X[i]<X[i-1]) {
			cout<<"No"<<endl;
			return;
		}
		int D=X[i]-(i+1);
		if(i) S[i]+=S[i-1];
		S[i]++;
		S[i+D]--;
		if(X[i]!=N) R[i+D]=A[i+D+1]+T-1;
		
		if(S[i]) {
			L[i]=max(A[i+1]+T,L[i-1]+1);
		}
		else {
			L[i]=max(A[i]+T,L[i-1]+1);
		}
		if(R[i] && L[i]>R[i]) return _P("No\n");
	}
	
	
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<L[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}