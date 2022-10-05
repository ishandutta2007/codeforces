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

int D,R,N;
int X,Y,L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>D>>N;
	D=R-D;
	int ret=0;
	FOR(i,N) {
		cin>>X>>Y>>L;
		
		if(R<L) continue;
		if(X*X+Y*Y<D*D+L*L+2*D*L) continue;
		if(X*X+Y*Y>R*R+L*L-2*L*R) continue;
		ret++;
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}