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

int H,W;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int L=1,R=W;
	while(L<R) {
		for(y=1;y<=H;y++) {
			_P("%d %d\n",y,L);
			_P("%d %d\n",H+1-y,R);
		}
		L++;
		R--;
	}
	
	if(L==R) {
		x=L;
		L=1,R=H;
		while(L<R) {
			_P("%d %d\n",L,x);
			_P("%d %d\n",R,x);
			L++;
			R--;
		}
		
		if(L==R) _P("%d %d\n",L,x);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}