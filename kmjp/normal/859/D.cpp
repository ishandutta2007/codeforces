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

int N,M;
double mat[64][64];

double R[8][64];
double S[8][64];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	M=1<<N;
	FOR(y,M) FOR(x,M) cin>>mat[y][x], mat[y][x]/=100.0;
	
	FOR(y,M) R[0][y]=1;
	FOR(i,N) {
		x=1<<i;
		for(y=0;y<M;y+=2*x) {
			for(int l=y;l<y+x;l++) for(int r=y+x;r<y+2*x;r++) {
				R[i+1][l]+=R[i][l]*R[i][r]*mat[l][r];
				R[i+1][r]+=R[i][l]*R[i][r]*mat[r][l];
			}
			for(int l=y;l<y+x;l++) for(int r=y+x;r<y+2*x;r++) {
				S[i+1][l]=max(S[i+1][l], S[i][l]+S[i][r]+(1<<i)*R[i+1][l]);
				S[i+1][r]=max(S[i+1][r], S[i][l]+S[i][r]+(1<<i)*R[i+1][r]);
			}
		}
	}
	
	double ret=0;
	FOR(x,M) ret=max(ret,S[N][x]);
	_P("%.12lf\n",ret);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}