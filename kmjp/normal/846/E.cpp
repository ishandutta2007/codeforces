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
ll B[101010],A[101010];
int X[101010],K[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>A[i], B[i]-=A[i];
	for(i=1;i<N;i++) {
		cin>>X[i]>>K[i];
		X[i]--;
	}
	
	// go up
	for(i=N-1;i>0;i--) {
		if(B[i]>0) {
			B[X[i]]+=B[i];
		}
		if(B[i]<0) {
			if(B[i]<-1LL<<60) return _P("NO\n");
			if(B[i]*K[i]/K[i]!=B[i]) return _P("NO\n");
			if(B[X[i]]+B[i]*K[i]>B[X[i]]) return _P("NO\n");
			B[X[i]]+=B[i]*K[i];
		}
		B[i]=0;
	}
	if(B[0]<0) return _P("NO\n");
	
	_P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}