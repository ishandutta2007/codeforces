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
ll X[1010],Y[1010];
long double D[1010][1010];

long double dist(int a,int b,int c) {
	double AX=X[a]-X[b];
	double AY=Y[a]-Y[b];
	double AD=D[a][b];
	double BX=X[c]-X[b];
	double BY=Y[c]-Y[b];
	double BD=D[c][b];
	double A=abs(AX*BY-AY*BX)/2.0;
	double H=2*A/BD;
	return H;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	
	FOR(i,N) cin>>X[i]>>Y[i];
	long double MD=1e10;
	FOR(x,N) FOR(y,N) D[x][y]=hypot(X[x]-X[y],Y[x]-Y[y]);
	FOR(y,N) FOR(x,y) MD=min(MD,D[x][y]/2.0);
	FOR(x,N) MD=min(MD,dist((x+1)%N,x,(x+2)%N)/2.0);
	
	_P("%.12lf\n",(double)MD);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}