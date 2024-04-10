#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,L;
int A[101010];
int B[101010];


double hoge(double t,int* A) {
	double cur=0;
	double sp=1;
	int i;
	FOR(i,N) {
		double nex=A[i]-cur;
		double tim=nex/sp;
		if(t<tim) {
			cur+=sp*t;
			return cur;
		}
		t -= nex/sp;
		cur=A[i];
		sp+=1.0;
	}
	
	cur+=sp*t;
	return cur;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L;
		FOR(i,N) {
			cin>>A[i];
			B[N-1-i]=L-A[i];
		}
		double l=0,r=1e9;
		FOR(i,100) {
			double M=(l+r)/2;
			double a=hoge(M,A);
			double b=hoge(M,B);
			if(a+b<L) l=M;
			else r=M;
		}
		_P("%.12lf\n",l);
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}