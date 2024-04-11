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
int A[1010101];
int nex[1010101];
int pos[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&A[i]);
	
	FOR(i,1010001) pos[i]=N;
	for(i=N-1;i>=0;i--) {
		nex[i]=pos[A[i]];
		pos[A[i]]=i;
	}
	
	ll tot=0;
	ll sum=0;
	FOR(i,1010000) sum+=N-pos[i];
	
	FOR(i,N) {
		tot+=sum-1;
		sum-=nex[i]-i;
	}
	double pat=1.0*N*(N-1)/2.0;
	_P("%.12lf\n",(tot*2+N)/(1.0*N*N));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}