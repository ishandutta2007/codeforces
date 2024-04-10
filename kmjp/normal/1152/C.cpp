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

ll A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	
	ll D=abs(A-B);
	ll mi=A*B;
	int ret=0;
	vector<int> C;
	for(x=1;x*x<=D;x++) if(D%x==0) C.push_back(x),C.push_back(D/x);
	FORR(c,C) {
		ll A2=(A+(c-1))/c*c;
		ll B2=(B+(c-1))/c*c;
		ll G=A2/__gcd(A2,B2)*B2;
		if(G<mi) {
			mi=G;
			ret=A2-A;
		}
	}
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}