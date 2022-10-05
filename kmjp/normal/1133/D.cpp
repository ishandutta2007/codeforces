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
map<pair<int,int>,int> M;
int Z,Z2;

int A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) {
		if(B[i]==0) {
			Z++;
			if(A[i]==0) Z2++;
		}
		else if(A[i]) {
			if(A[i]<0) A[i]=-A[i],B[i]=-B[i];
			int g=__gcd(abs(A[i]),abs(B[i]));
			A[i]/=g;
			B[i]/=g;
			M[{A[i],B[i]}]++;
		}
	}
	
	int ma=Z;
	FORR(m,M) ma=max(ma,Z2+m.second);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}