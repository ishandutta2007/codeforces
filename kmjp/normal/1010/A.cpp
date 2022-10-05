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
double M;
int A[1010],B[1010],C[2010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	y=M;
	FOR(i,N) {
		cin>>x;
		C[(N-1-i)*2+1]=x;
	}
	FOR(i,N) {
		cin>>x;
		if(i==0) C[0]=x;
		else C[(N-1-i)*2+2]=x;
	}
	
	FOR(i,2*N) {
		if(C[i]==1) return _P("-1\n");
		M=M+M/(C[i]-1.0);
	}
	_P("%.12lf\n",M-y);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}