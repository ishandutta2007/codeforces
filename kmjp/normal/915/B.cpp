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

int N,P,L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>L>>R;
	
	if(L<=P && P<=R) {
		if(L>1 && R<N) {
			cout<<(2+(R-L)+min(R-P,P-L))<<endl;
		}
		else if(L>1) {
			cout<<(P-L)+1<<endl;
		}
		else if(R<N) {
			cout<<(R-P)+1<<endl;
		}
		else {
			cout<<0<<endl;
		}
	}
	else if(P<L) {
		if(R<N) cout<<R-P+2<<endl;
		else cout<<L-P+1<<endl;
	}
	else {
		if(L>1) cout<<P-L+2<<endl;
		else cout<<P-R+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}