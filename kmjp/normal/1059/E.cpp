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

int N,L;
ll S;
ll W[101010];
ll WS[101010];
int P[20][101010];
int C[101010];
vector<int> E[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>S;
	FOR(i,N) {
		cin>>W[i];
		if(W[i]>S) return _P("-1\n");
	}
	WS[0]=W[0];
	FOR(i,N-1) {
		cin>>P[0][i+1];
		P[0][i+1]--;
		E[P[0][i+1]].push_back(i+1);
		WS[i+1]=WS[P[0][i+1]]+W[i+1];
	}
	FOR(i,19) FOR(j,N) P[i+1][j]=P[i][P[i][j]];
	FOR(j,N) {
		x=j;
		for(i=19;i>=0;i--) if((L-1)&(1<<i)) x=P[i][x];
		C[j]=x;
		x=j;
		for(i=19;i>=0;i--) if(WS[j]-(WS[P[i][x]]-W[P[i][x]])<=S) x=P[i][x];
		C[j]=max(C[j],x);
	}
	int ret=0;
	for(i=N-1;i>=0;i--) {
		int T=101010;
		FORR(e,E[i]) if(C[e]>=0) {
			if(T!=101010) ret++;
			T=min(T,C[e]);
		}
		
		if(T!=101010) C[i]=max(C[i],T);
		if(C[i]==i) {
			ret++;
			C[i]=-1;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}