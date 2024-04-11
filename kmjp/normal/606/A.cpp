#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A,B,C,X,Y,Z;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	cin>>X>>Y>>Z;
	int more=max(0,(A-X)/2)+max(0,(B-Y)/2)+max(0,(C-Z)/2);
	int low=max(0,X-A)+max(0,Y-B)+max(0,Z-C);
	if(more>=low) _P("Yes\n");
	else _P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}