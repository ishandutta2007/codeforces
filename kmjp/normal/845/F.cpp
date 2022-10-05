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
string S[255];
ll from[2][2][1<<16];
ll to[2][2][1<<16];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	if(H>W) {
		string T[255];
		FOR(y,W) T[y]=string(H,'.');
		FOR(y,W) FOR(x,H) T[y][x]=S[x][y];
		FOR(y,H) S[y]=T[y];
		swap(H,W);
	}
	
	from[0][0][0]=1;
	FOR(x,W) {
		FOR(y,H) {
			ZERO(to);
			if(y==0) {
				FOR(i,2) for(int mask=0;mask<1<<H;mask++) {
					(from[i][0][mask]+=from[i][1][mask])%=mo;
					from[i][1][mask]=0;
				}
			}
			
			FOR(i,2) FOR(j,2) for(int mask=0;mask<1<<H;mask++) {
				
				if(S[y][x]=='x') {
					(to[i][0][mask&((~0)^(1<<y))]+=from[i][j][mask])%=mo;
				}
				else {
					// put
					(to[i][1][mask|(1<<y)] += from[i][j][mask])%=mo;
					// not put
					if(j||(mask&(1<<y))) {
						(to[i][j][mask] += from[i][j][mask])%=mo;
					}
					else {
						if(i==0) (to[i+1][j][mask] += from[i][j][mask])%=mo;
					}
				}
			}
			swap(from,to);
		}
	}
	
	ll ret=0;
	FOR(i,2) FOR(j,2) for(int mask=0;mask<1<<H;mask++) ret+=from[i][j][mask];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}