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
ll A[5050];
ll S[5050];
ll dp1[5050];
int from1[5050];
ll dp2[5050];
int from2[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	FOR(i,N+1) dp1[i]=dp2[i]=-1LL<<60;
	FOR(x,N+1) FOR(y,x+1) if(dp1[x]<S[y]-(S[x]-S[y])) {
		dp1[x]=S[y]-(S[x]-S[y]);
		from1[x]=y;
	}
	FOR(x,N+1) FOR(y,x+1) if(dp2[x]<dp1[y]+(S[x]-S[y])) {
		dp2[x]=dp1[y]+(S[x]-S[y]);
		from2[x]=y;
	}
	ll ret=-1LL<<60;
	int from;
	FOR(x,N+1) if(ret<dp2[x]-(S[N]-S[x])) {
		ret=dp2[x]-(S[N]-S[x]);
		from=x;
	}
	cout<<from1[from2[from]]<<" "<<from2[from]<<" "<<from<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}