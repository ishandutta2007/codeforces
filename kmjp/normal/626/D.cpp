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
int A[2020];
double D[5050];
double D2[10050];
double S[10050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(y,N) FOR(x,N) if(A[x]<A[y]) D[A[y]-A[x]]+=2.0/N/(N-1);
	
	FOR(i,5002) if(D[i]) {
		FOR(j,5002-i) if(D[j]) D2[i+j] += D[i]*D[j];
	}
	
	for(i=1;i<=10000;i++) S[i]=S[i-1]+D2[i];
	
	double ret=0;
	FOR(i,5002) if(D[i]) ret += D[i]*S[i-1];
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}