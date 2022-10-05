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

int T,H,W;
ll A[101][101];
ll D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) FOR(x,W) {
			cin>>A[y][x];
			A[y][x]-=y+x;
		}
		
		ll ret=1LL<<60;
		FOR(i,H) FOR(j,W) {
			ll C=A[i][j];
			FOR(y,H) FOR(x,W) D[y][x]=1LL<<60;
			D[0][0]=0;
			FOR(y,H) FOR(x,W) {
				if(C>A[y][x]) {
					D[y][x]=1LL<<60;
					continue;
				}
				D[y][x]+=A[y][x]-C;
				if(y+1<H) D[y+1][x]=min(D[y+1][x],D[y][x]);
				if(x+1<W) D[y][x+1]=min(D[y][x+1],D[y][x]);
			}
			ret=min(ret,D[H-1][W-1]);
			
		}
		cout<<ret<<endl;
		
	}
		
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}