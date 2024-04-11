#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,H;
double P,Q;
int X[10101];
int le[10101],ri[10101];
double memo[2020][2020][2][2];

double dodo(int L,int R,int LL,int RL) {
	if(L>R) return 0;
	if(memo[L][R][LL][RL]>=0) return memo[L][R][LL][RL];
	double ret=0;
	
	int LX=X[L-1] + (LL==0)*H;
	int RX=X[R+1] - (RL==1)*H;
	
	if(L==R) {
		ret=P*min(H,X[L]-LX)+Q*min(H,RX-X[L]);
	}
	else {
		// left tree
		ret += P*(min(H,X[L]-LX)+dodo(L+1,R,1,RL));
		int NL=min(R,ri[L]);
		if(NL>=R) {
			ret += Q*(min(RX,X[R]+H)-X[L]);
		}
		else {
			ret += Q*(X[NL]+H-X[L]+dodo(NL+1,R,0,RL));
		}
		
		// right tree
		ret += Q*(min(H,RX-X[R])+dodo(L,R-1,LL,0));
		int NR=max(L,le[R]);
		if(NR<=L) {
			ret += P*(X[R]-max(LX,X[L]-H));
		}
		else {
			ret += P*(X[R]-(X[NR]-H)+dodo(L,NR-1,LL,1));
		}
		
		ret /= 2;
	}
	
	return memo[L][R][LL][RL]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,2010) FOR(x,2010) FOR(r,4) memo[y][x][r/2][r%2]=-1;
	
	cin>>N>>H>>P;
	Q=1-P;
	X[0]=-300000000;
	X[N+1]=300000000;
	FOR(i,N) cin>>X[i+1];
	sort(X+1,X+N+1);
	
	for(i=1;i<=N;i++) le[i]=(X[i]-X[i-1]<H)?le[i-1]:i;
	for(i=N;i>=1;i--) ri[i]=(X[i+1]-X[i]<H)?ri[i+1]:i;
	
	_P("%.12lf\n",dodo(1,N,0,1));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}