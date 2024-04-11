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

int N,K,M;
int A[101010];
int S[101010][20];
map<int,int> P;
vector<int> V,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(K==1) {
		cout<<1LL*N*(N+1)/2<<endl;
		return;
	}
	
	for(j=2;j*j<=K;j++) while(K%j==0) P[j]++, K/=j;
	if(K>1) P[K]++;
	FORR(r,P) V.push_back(r.first),W.push_back(r.second);
	M=V.size();
	
	FOR(i,N) {
		cin>>A[i];
		FOR(j,M) {
			S[i+1][j]=S[i][j];
			while(A[i]%V[j]==0) S[i+1][j]++, A[i]/=V[j];
		}
	}
	ll ret=0;
	int L,R=0;
	FOR(L,N) {
		R=max(R,L+1);
		while(1) {
			if(R>N) break;
			int ok=1;
			FOR(j,M) if(S[R][j]-S[L][j]<W[j]) ok=0;
			if(ok) break;
			R++;
		}
		if(R>N) break;
		ret+=(N+1)-R;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}