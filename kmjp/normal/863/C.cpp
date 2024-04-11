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

const int MAT=10;
struct Mat { ll v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
	}
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

ll K;
int A,B;
int X[3][3],Y[3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>A>>B;
	A--,B--;
	FOR(y,3) FOR(x,3) cin>>X[y][x], X[y][x]--;
	FOR(y,3) FOR(x,3) cin>>Y[y][x], Y[y][x]--;
	
	Mat XW,YW;
	ZERO(XW.v);
	ZERO(YW.v);
	FOR(x,3) FOR(y,3) {
		int nx=X[x][y];
		int ny=Y[x][y];
		
		if((y+1)%3==x) XW.v[9][x*3+y]=1;
		if((x+1)%3==y) YW.v[9][x*3+y]=1;
		XW.v[nx*3+ny][x*3+y]=1;
		YW.v[nx*3+ny][x*3+y]=1;
	}
	XW.v[9][9]=YW.v[9][9]=1;
	
	Mat XF=powmat(K,XW);
	Mat YF=powmat(K,YW);
	
	cout<<XF.v[9][A*3+B]<<" "<<YF.v[9][A*3+B]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}