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

int T;
int N,M;
int A[202020];
int P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		FOR(i,N) scanf("%d",&A[i]);
		scanf("%d",&M);
		FOR(i,N+1) P[i]=0;
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			P[y]=max(P[y],x);
		}
		for(i=N-1;i>=1;i--) P[i]=max(P[i],P[i+1]);
		int cur=0,turn=0;
		while(cur<N) {
			turn++;
			int ma=0;
			for(x=0;cur+x<N;x++) {
				ma=max(ma,A[cur+x]);
				if(P[x+1]<ma) break;
			}
			if(x==0) {
				turn=-1;
				break;
			}
			cur+=x;
		}
		_P("%d\n",turn);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}