#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int T[3030];
int A[3030][3030];
ll S[3030];

ll ret;

void hoge(int L,int R,vector<ll> X) {
	if(L+1==R) {
		int i;
		ll sum=0;
		FOR(i,min(K,T[L])+1) {
			if(i) sum+=A[L][i-1];
			ret=max(ret,sum+X[K-i]);
		}
		return;
	}
	int M=(L+R)/2;
	vector<ll> Y=X,Z=X;
	int i,j;
	for(i=L;i<M;i++) for(j=K;j>=T[i];j--) Y[j]=max(Y[j],Y[j-T[i]]+S[i]);
	for(i=M;i<R;i++) for(j=K;j>=T[i];j--) Z[j]=max(Z[j],Z[j-T[i]]+S[i]);
	hoge(L,M,Z);
	hoge(M,R,Y);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>T[i];
		FOR(j,T[i]) cin>>A[i][min(3000,j)];
		T[i]=min(T[i],3000);
		FOR(j,T[i]) S[i]+=A[i][j];
	}
	
	vector<ll> dp(K+1,-1LL<<60);
	dp[0]=0;
	hoge(0,N,dp);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}