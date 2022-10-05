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
int A[202020];
int B[202020];
int T[202020];
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i], B[i]=A[i];
	int ma=0;
	FOR(i,M) {
		cin>>x>>y;
		ma=max(ma,y);
		T[y]=i+1;
		R[y]=x;
	}
	sort(A,A+ma);
	x=0;
	y=ma-1;
	j=0;
	int t=0;
	for(i=N-1;i>=0;i--) {
		if(T[i+1]>t) j=R[i+1], t=T[i+1];
		if(t>0) {
			if(j==2) B[i]=A[x++];
			else B[i]=A[y--];
		}
	}
	FOR(i,N) _P("%d%s",B[i],(i==N-1)?"\n":" ");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}