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
int A[6060][6060];
int R[6060];
int C[6060];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>s;
		FOR(i,N/4) {
			x=0;
			if(s[i]>='0'&&s[i]<='9') x=s[i]-'0';
			if(s[i]>='A'&&s[i]<='F') x=s[i]-'A'+10;
			
			A[y][i*4]=(x&8)!=0;
			A[y][i*4+1]=(x&4)!=0;
			A[y][i*4+2]=(x&2)!=0;
			A[y][i*4+3]=(x&1)!=0;
		}
	}
	
	R[N-1]=C[N-1]=1;
	for(y=N-2;y>=0;y--) {
		R[y]=R[y+1]+1;
		C[y]=C[y+1]+1;
		FOR(x,N) if(A[y][x]!=A[y+1][x]) R[y]=1;
		FOR(x,N) if(A[x][y]!=A[x][y+1]) C[y]=1;
	}
	
	for(i=N;i>=1;i--) if(N%i==0) {
		int ok=1;
		for(x=0;x<N;x+=i) if(C[x]<min(i,N-x)) ok=0;
		for(y=0;y<N;y+=i) if(R[y]<min(i,N-y)) ok=0;
		if(ok) return _P("%d\n",i);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}