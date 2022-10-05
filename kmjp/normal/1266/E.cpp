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
int A[202020];
int Q;
int S[201010],T[201010],U[201010];
ll P;
int B[201010];
map<int,int> M[201010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i+1]);
		P+=A[i+1];
	}
	scanf("%d",&Q);
	FOR(i,Q) {
		scanf("%d%d%d",&S[i],&T[i],&U[i]);
		if(M[S[i]].count(T[i])) {
			x=M[S[i]][T[i]];
			B[x]--;
			if(B[x]<A[x]) P++;
			M[S[i]].erase(T[i]);
		}
		if(U[i]) {
			M[S[i]][T[i]]=U[i];
			B[U[i]]++;
			if(B[U[i]]<=A[U[i]]) P--;
		}
		cout<<P<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}