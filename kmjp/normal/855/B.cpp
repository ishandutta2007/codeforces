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
ll P,Q,R;
ll A[101010];
ll Lmi[101010];
ll Lma[101010];
ll Rmi[101010];
ll Rma[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q>>R;
	
	FOR(i,N) cin>>A[i+1];
	
	Lmi[0]=Rmi[N+1]=1LL<<30;
	Lma[0]=Rma[N+1]=-1LL<<30;
	for(i=1;i<=N;i++) {
		Lmi[i]=min(Lmi[i-1],A[i]);
		Lma[i]=max(Lma[i-1],A[i]);
	}
	for(i=N;i>=1;i--) {
		Rmi[i]=min(Rmi[i+1],A[i]);
		Rma[i]=max(Rma[i+1],A[i]);
	}
	ll ret=-1LL<<62;
	for(i=1;i<=N;i++) ret=max(ret,Q*A[i]+max(P*Lmi[i],P*Lma[i])+max(R*Rmi[i],R*Rma[i]));
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}