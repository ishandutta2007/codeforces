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

int hoi(int y) {
	if(y%400==0) return 366;
	if(y%4==0 && y%100!=0) return 366;
	return 365;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int cd=hoi(N);
	x=cd%7;
	for(i=N+1;;i++) {
		y=hoi(i);
		if(y==cd && x==0) return _P("%d\n",i);
		x=(x+y)%7;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}