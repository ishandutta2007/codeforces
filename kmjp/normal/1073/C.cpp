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
string S;
int X,Y;
int U,D,L,R;

int SX[202020],SY[202020];
int TX[202020],TY[202020];

int ok(int v) {
	if(v<0) return 0;
	int i;
	FOR(i,N) {
		if(i+v>N) break;
		
		int d=abs(SX[i]-TX[i+v])+abs(SY[i]-TY[i+v]);
		if(d<=v) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) {
		if(c=='U') U++;
		if(c=='D') D++;
		if(c=='L') L++;
		if(c=='R') R++;
	}
	cin>>X>>Y;
	if(abs(X)+abs(Y)>N) return _P("-1\n");
	if((abs(X)+abs(Y))%2!=N%2) return _P("-1\n");
	
	FOR(i,N) {
		SX[i+1]=SX[i];
		SY[i+1]=SY[i];
		if(S[i]=='R') SX[i+1]++;
		if(S[i]=='L') SX[i+1]--;
		if(S[i]=='U') SY[i+1]++;
		if(S[i]=='D') SY[i+1]--;
	}
	
	TX[N]=X;
	TY[N]=Y;
	for(i=N-1;i>=0;i--) {
		TX[i]=TX[i+1];
		TY[i]=TY[i+1];
		if(S[i]=='R') TX[i]--;
		if(S[i]=='L') TX[i]++;
		if(S[i]=='U') TY[i]--;
		if(S[i]=='D') TY[i]++;
	}
	
	int ret=N;
	for(i=20;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}