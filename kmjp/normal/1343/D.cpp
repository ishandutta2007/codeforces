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
int N,K;
int A[202020];
int B[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		FOR(i,2*K+2) B[i]=0;
		FOR(i,N/2) {
			int cur=A[i]+A[N-1-i];
			int mi=min(A[i],A[N-1-i])+1;
			int ma=max(A[i],A[N-1-i])+K;
			B[0]+=2;
			B[mi]--;
			B[cur]--;
			B[cur+1]++;
			B[ma+1]++;
		}
		int mi=1<<20;
		for(i=1;i<=2*K;i++) {
			B[i]+=B[i-1];
			mi=min(mi,B[i]);
		}
		
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}