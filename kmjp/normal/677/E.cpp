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
int A[1010][1010];
int SH[4][1010][1010];
int SV[4][1010][1010];
int Ssl[4][1010][1010];
int Srev[4][1010][1010];
int L[1010][1010];
int R[1010][1010];
int U[1010][1010];
int D[1010][1010];
int UL[1010][1010];
int UR[1010][1010];
int DL[1010][1010];
int DR[1010][1010];
ll mo=1000000007;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S;
		FOR(x,N) A[y][x]=S[x]-'0';
	}
	FOR(i,4) {
		FOR(y,N) FOR(x,N) {
			SH[i][y+1][x+1]=SH[i][y+1][x]+(A[y][x]==i);
			SV[i][y+1][x+1]=SV[i][y][x+1]+(A[y][x]==i);
			Ssl[i][y+1][x+1]=Ssl[i][y][x+2]+(A[y][x]==i);
			Srev[i][y+1][x+1]=Srev[i][y][x]+(A[y][x]==i);
		}
	}
	FOR(y,N) FOR(x,N) {
		L[y+1][x+1]=(A[y][x]==0)?0:(1+L[y+1][x]);
		UL[y+1][x+1]=(A[y][x]==0)?0:(1+UL[y][x]);
		UR[y+1][x+1]=(A[y][x]==0)?0:(1+UR[y][x+2]);
	}
	FOR(y,N) for(x=N-1;x>=0;x--) R[y+1][x+1]=(A[y][x]==0)?0:(1+R[y+1][x+2]);
	FOR(x,N) FOR(y,N) U[y+1][x+1]=(A[y][x]==0)?0:(1+U[y][x+1]);
	FOR(x,N) for(y=N-1;y>=0;y--) D[y+1][x+1]=(A[y][x]==0)?0:(1+D[y+2][x+1]);
	for(y=N-1;y>=0;y--) FOR(x,N) {
		DL[y+1][x+1]=(A[y][x]==0)?0:(1+DL[y+2][x]);
		DR[y+1][x+1]=(A[y][x]==0)?0:(1+DR[y+2][x+2]);
	}
	
	double ma=-3;
	int p2=0,p3=0;
	FOR(y,N) FOR(x,N) if(A[y][x]!=0) {
		int mc=min(min(L[y+1][x+1],R[y+1][x+1]),min(U[y+1][x+1],D[y+1][x+1]));
		int t[4]={};
		for(i=2;i<=3;i++) t[i]=SH[i][y+1][x+1+mc-1]-SH[i][y+1][x+1-mc]+SV[i][y+1+mc-1][x+1]-SV[i][y+1-mc][x+1] - (A[y][x]==i);
		double dt=t[2]*log(2)+t[3]*log(3);
		if(dt>ma) ma=dt, p2=t[2], p3=t[3];
		
		mc=min(min(UL[y+1][x+1],UR[y+1][x+1]),min(DL[y+1][x+1],DR[y+1][x+1]));
		for(i=2;i<=3;i++) t[i]=Srev[i][y+1+mc-1][x+1+mc-1]-Srev[i][y+1-mc][x+1-mc]+Ssl[i][y+1+mc-1][x+1-(mc-1)]-Ssl[i][y+1-mc][x+1+mc] - (A[y][x]==i);
		dt=t[2]*log(2)+t[3]*log(3);
		if(dt>ma) ma=dt, p2=t[2], p3=t[3];
		
	}
	
	if(ma<-2) cout<<0<<endl;
	else {
		ll ret=1;
		FOR(i,p2) ret=ret*2%mo;
		FOR(i,p3) ret=ret*3%mo;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}