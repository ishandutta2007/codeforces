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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	x=1;
	while(1) {
		int n6=x/6;
		int n2=x/2-n6;
		int n3=x/3-n6;
		
		int N2=max(0,N-n2);
		int M2=max(0,M-n3);
		if(N2+M2<=n6) {
			cout<<x<<endl;
			break;
		}
		x++;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}