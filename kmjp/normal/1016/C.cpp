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
ll A[303030],B[303030];
ll SA[303030],LA[303030],RA[303030];
ll SB[303030],LB[303030],RB[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) cin>>B[i+1];
	
	FOR(i,N) {
		SA[i+1]=SA[i]+A[i+1];
		LA[i+1]=LA[i]+A[i+1]*(i+1);
		SB[i+1]=SB[i]+B[i+1];
		LB[i+1]=LB[i]+B[i+1]*(i+1);
	}
	for(i=N;i>=0;i--) {
		RA[i]=RA[i+1]+A[i]*(N+1-i);
		RB[i]=RB[i+1]+B[i]*(N+1-i);
	}
	
	ll ret;
	ll cur=0;
	int nex=0;
	ret=LA[N]-SA[N]+RB[1]+SB[N]*(N-1);
	for(i=1;i<=N;i++) {
		ll tmp;
		if(i%2) {
			cur+=nex++*A[i];
			cur+=nex++*B[i];
			tmp=cur;
			tmp+=(LB[N]-LB[i])+(SB[N]-SB[i])*(i-1);
			x=nex+(N-i);
			tmp+=RA[i+1]+(SA[N]-SA[i])*(x-1);
		}
		else {
			cur+=nex++*B[i];
			cur+=nex++*A[i];
			tmp=cur;
			tmp+=(LA[N]-LA[i])+(SA[N]-SA[i])*(i-1);
			x=nex+(N-i);
			tmp+=RB[i+1]+(SB[N]-SB[i])*(x-1);
		}
		ret=max(ret,tmp);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}