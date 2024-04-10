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

int Q;
int N;
string S,T;

int dpdp[2020][2020];
int C[26][2020];
int D[26][2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>S>>T;
		ZERO(C);
		ZERO(D);
		FOR(i,N) {
			FOR(j,26) C[j][i+1]=C[j][i], D[j][i+1]=D[j][i];
			S[i]-='a';
			T[i]-='a';
			C[S[i]][i+1]++;
			D[T[i]][i+1]++;
		}
		
		FOR(x,N+1) FOR(y,N+1) dpdp[x][y]=101010;
		dpdp[0][0]=0;
		FOR(y,N+1) FOR(x,y+1) {
			if(y<N && S[x]==T[y]) dpdp[x+1][y+1]=min(dpdp[x+1][y+1],dpdp[x][y]);
			if(y<N) dpdp[x][y+1]=min(dpdp[x][y+1],dpdp[x][y]+1);
			if(D[S[x]][y]>C[S[x]][x]) dpdp[x+1][y]=min(dpdp[x+1][y],dpdp[x][y]);
		}
		
		int mi=dpdp[N][N];
		if(mi>2020) mi=-1;
		
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}