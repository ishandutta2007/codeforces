#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N;
ll A[1010101];
int P[1010101];
ll miA[1010101];
ll maA[1010101];
ll ret;
int step;
void dfs(int L,int R) {
	
	if(R-L<=1) {
		ret+=R-L;
		return;
	}
	
	int M=(L+R)/2;
	int i,j;
	miA[M-1]=maA[M-1]=A[M-1];
	for(i=M-2;i>=L;i--) {
		miA[i]=min(miA[i+1],A[i]);
		maA[i]=max(maA[i+1],A[i]);
	}
	miA[M]=maA[M]=A[M];
	for(i=M+1;i<R;i++) {
		miA[i]=min(miA[i-1],A[i]);
		maA[i]=max(maA[i-1],A[i]);
	}
	
	int D[60]={};
	int L1=M,L2=M;
	
	miA[M]=maA[M]=A[M];
	for(i=M;i<R;i++) {
		int pma=__builtin_popcountll(maA[i]);
		int pmi=__builtin_popcountll(miA[i]);
		while(L1>L&&maA[L1-1]<=maA[i]) L1--, D[__builtin_popcountll(miA[L1])]++;
		while(L2>L1&&miA[L2-1]>=miA[i]) L2--, D[__builtin_popcountll(miA[L2])]--;
		if(L1==M) continue;
		if(pma==pmi) ret+=M-L2;
		ret+=D[pma];
	}
	
	ZERO(D);
	
	int R1=M-1,R2=M-1;
	miA[M-1]=maA[M-1]=A[M-1];
	for(i=M-1;i>=L;i--) {
		int pma=__builtin_popcountll(maA[i]);
		int pmi=__builtin_popcountll(miA[i]);
		while(R1+1<R&&maA[R1+1]<maA[i]) R1++, D[__builtin_popcountll(miA[R1])]++;
		while(R2<R1&&miA[R2+1]>=miA[i]) R2++, D[__builtin_popcountll(miA[R2])]--;
		if(R1==M-1) continue;
		if(pma==pmi) ret+=R2-(M-1);
		ret+=D[pma];
	}
	
	
	dfs(L,M);
	dfs(M,R);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		P[i]=__builtin_popcountll(A[i]);
	}
	dfs(0,N);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}