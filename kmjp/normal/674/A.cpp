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
int T[5050];
int cnt[5050];
int ma=0;
int R[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i];
	
	FOR(x,N) {
		FOR(i,N+1) cnt[i]=0;
		int ma=0,id=0;
		for(y=x;y<N;y++) {
			r=T[y];
			cnt[r]++;
			if(cnt[r]>ma) ma=cnt[r],id=r;
			else if(cnt[r]==ma && r<id) id=r;
			R[id]++;
		}
	}
	
	FOR(i,N) _P("%d%s",R[i+1],(i==N-1)?"\n":" ");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}