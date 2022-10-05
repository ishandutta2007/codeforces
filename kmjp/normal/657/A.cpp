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

int N,D,H;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>H;
	if(D>2*H) return _P("-1\n");
	
	if(N>2 && D==1) return _P("-1\n");
	if(D==H) {
		if(D+1==H) {
			FOR(i,N-1) _P("%d %d\n",i+1,i+2);
		}
		else {
			x=2;
			FOR(i,H) {
				_P("%d %d\n",x-1,x);
				x++;
			}
			for(;x<=N;x++) _P("2 %d\n",x);
		}
	}
	else {
		x=2;
		FOR(i,H) {
			_P("%d %d\n",x-1,x);
			x++;
		}
		FOR(i,D-H) {
			if(i==0) _P("%d %d\n",1,x);
			else _P("%d %d\n",x-1,x);
			x++;
		}
		for(;x<=N;x++) _P("1 %d\n",x);
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}