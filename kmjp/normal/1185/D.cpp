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
map<ll,int> M;
ll B[202020];
ll L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N<=3) {
		cout<<1<<endl;
		return;
	}
	
	FOR(i,N) {
		cin>>B[i];
		M[B[i]]=i+1;
	}
	sort(B,B+N);
	
	L[0]=L[1]=1;
	for(i=2;i<N;i++) if(L[i-1] && (B[i]-B[i-1])==(B[i-1]-B[i-2])) L[i]=1;
	R[N-1]=R[N-2]=1;
	for(i=N-3;i>=0;i--) if(R[i+1] && B[i+1]-B[i]==B[i+2]-B[i+1]) R[i]=1;
	
	if(R[1]) return _P("%d\n",M[B[0]]);
	if(L[N-2]) return _P("%d\n",M[B[N-1]]);
	if(R[2]&&B[0]+B[3]==B[2]*2) return _P("%d\n",M[B[1]]);
	if(L[N-3]&&B[N-1]+B[N-4]==B[N-3]*2) return _P("%d\n",M[B[N-2]]);
	for(i=2;i<N-2;i++) if(L[i-1]&&R[i+1]) {
		if(B[i-1]-B[i-2]==B[i+1]-B[i-1] && B[i+1]-B[i-1]==B[i+2]-B[i+1]) return _P("%d\n",M[B[i]]);
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}