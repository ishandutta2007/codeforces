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

int R[51][51];

void magic(int N) {
	int i,x,y;
	if(N%2) {
		y=0,x=N/2;
		FOR(i,N*N) {
			R[y][x]=i+1;
			int ty=(y+N-1)%N,tx=(x+1)%N;
			if(R[ty][tx]!=0) ty=(y+1)%N, tx=x;
			y=ty,x=tx;
		}
	}
	else if(N%4==0) {
		FOR(y,N) FOR(x,N) {
			int tx=x%4,ty=y%4;
			if((tx%3==0)^(ty%3==0)) R[y][x]=N*N+1-(y*N+x+1);
			else R[y][x]=y*N+x+1;
		}
	}
	else {
		int RR[51][51]={};
		int T[51][51]={};
		int N2=N/2;
		magic(N/2);
		FOR(y,N/2) FOR(x,N/2) RR[y][x]=R[y][x];
		FOR(y,N2) FOR(x,N2) RR[y][x]=(RR[y][x]-1)*4;
		FOR(y,N2) FOR(x,N2) {
			if(y==N2/2+1) T[y][x]=1;
			if(y>N2/2+1) T[y][x]=2;
		}
		swap(T[N2/2][N2/2],T[N2/2+1][N2/2]);
		
		FOR(y,N2) FOR(x,N2) {
			if(T[y][x]==0) R[y*2][x*2]=RR[y][x]+4, R[y*2][x*2+1]=RR[y][x]+1;
			else           R[y*2][x*2]=RR[y][x]+1, R[y*2][x*2+1]=RR[y][x]+4;
			
			if(T[y][x]!=2) R[y*2+1][x*2]=RR[y][x]+2, R[y*2+1][x*2+1]=RR[y][x]+3;
			else           R[y*2+1][x*2]=RR[y][x]+3, R[y*2+1][x*2+1]=RR[y][x]+2;
		}
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	magic(N);
	FOR(y,N) {
		FOR(x,N) _P("%d%c",R[y][x],(x==N-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}