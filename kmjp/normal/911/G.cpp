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
ll B[101][3200];
int Q;
int L,R,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&	x);
		B[x][i>>6] |= 1LL<<(i&63);
	}
	scanf("%d",&Q);
	FOR(i,Q) {
		scanf("%d%d%d%d",&L,&R,&X,&Y);
		L--;
		if(X==Y) continue;
		while((L&63) && (L<R)) {
			B[Y][L>>6] |= B[X][L>>6] & (1LL<<(L&63));
			B[X][L>>6] ^= B[X][L>>6] & (1LL<<(L&63));
			L++;
		}
		while(L+64<=R) {
			B[Y][L>>6] |=B[X][L>>6];
			B[X][L>>6]=0;
			L+=64;
		}
		while(L<R) {
			B[Y][L>>6] |= B[X][L>>6] & (1LL<<(L&63));
			B[X][L>>6] ^= B[X][L>>6] & (1LL<<(L&63));
			L++;
		}
	}
	FOR(i,N) {
		FOR(x,101) if(B[x][i>>6] & (1LL<<(i&63))) break;
		_P("%d%c",x,(i==N-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}