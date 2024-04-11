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

ll A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	if(A<=2) return _P("-1\n");
	if((A&(A-1))==0) {
		B=A*3/4;
		C=A*5/4;
	}
	else {
		x=0;
		while(A%2==0) x++, A/=2;
		B=(A*A-1)/2;
		C=B+1;
		while(x--) A*=2, B*=2, C*=2;
	}
	cout<<B<<" "<<C<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}