#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,K;

ll from[71],to[71];
ll F[75][75];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(i,K) from[i]=-1LL<<60;
	from[0]=0;
	FOR(r,H) {
		FOR(x,71) FOR(y,71) F[x][y]=-1LL<<60;
		F[0][0]=0;
		FOR(x,W) {
			int v;
			cin>>v;
			for(i=70;i>=0;i--) for(j=70;j>=0;j--) F[i+1][(j+v)%K]=max(F[i+1][(j+v)%K],F[i][j]+v);
		}
		
		FOR(x,71) to[x]=-1LL<<60;
		FOR(x,K) FOR(y,K) FOR(i,W/2+1) {
			to[(x+y)%K]=max(to[(x+y)%K],from[x]+F[i][y]);
		}
		
		swap(from,to);
	}
	cout<<from[0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}