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

int N,X;
string S;
int nex[102][2];
int add[102][2];

ll pat[101][101][101];
ll padd[101][101][101];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>X>>S;
	
	FOR(i,N) {
		FOR(j,2) {
			if(S[i]=='0'+j) {
				nex[i][j]=i+1;
				if(i+1!=N) continue;
				add[i][j]=1;
			}
			string T=S.substr(0,i)+(char)('0'+j);
			for(x=i;x>=0;x--) {
				if(T.substr(T.size()-x)==S.substr(0,x)) {
					nex[i][j]=x;
					break;
				}
			}
		}
	}
	
	FOR(i,N) {
		// F[0]
		pat[0][i][i]++;
		pat[0][i][nex[i][0]]++;
		padd[0][i][nex[i][0]]+=add[i][0];
		// F[1]
		pat[1][i][i]++;
		pat[1][i][nex[i][1]]++;
		padd[1][i][nex[i][1]]+=add[i][1];
	}
	for(i=2;i<=X;i++) {
		FOR(x,N) FOR(y,N) FOR(z,N) {
			(pat[i][x][z]+=pat[i-1][x][y]*pat[i-2][y][z])%=mo;
			(padd[i][x][z]+=pat[i-1][x][y]*padd[i-2][y][z]+padd[i-1][x][y]*pat[i-2][y][z])%=mo;
		}
	}
	ll ret=0;
	FOR(j,N) ret+=padd[X][0][j];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}