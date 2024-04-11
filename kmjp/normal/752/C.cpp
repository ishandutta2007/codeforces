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
string S;
int ret=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	int mask=0;
	cin>>N>>S;
	FORR(c,S) {
		if(c=='R') {
			if(mask&1) ret++,mask=0;
			mask |= 2;
		}
		if(c=='L') {
			if(mask&2) ret++,mask=0;
			mask |= 1;
		}
		if(c=='U') {
			if(mask&4) ret++,mask=0;
			mask |= 8;
		}
		if(c=='D') {
			if(mask&8) ret++,mask=0;
			mask |= 4;
		}
	}
	cout<<ret+(mask>0)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}