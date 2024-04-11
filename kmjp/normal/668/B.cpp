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

int N,Q;
int R[1010100];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int p0=0;
	int p1=1;
	scanf("%d%d",&N,&Q);
	while(Q--) {
		scanf("%d",&x);
		if(x==1) {
			scanf("%d",&y);
			p0+=y+N;
			while(p0>=N) p0-=N;
			p1+=y+N;
			while(p1>=N) p1-=N;
		}
		else {
			p0^=1;
			p1^=1;
		}
	}
	
	FOR(i,N/2) {
		R[p0] = 1+i*2;
		R[p1] = 2+i*2;
		p0+=2;
		p1+=2;
		while(p0>=N) p0-=N;
		while(p1>=N) p1-=N;
	}
	
	FOR(i,N) _P("%d%s",R[i],(i==N-1)?"\n":" ");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}