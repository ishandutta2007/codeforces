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
const ll mo=998244353;

ll comb(ll N_, ll C_) {
	const int NUM_=1400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

int A[1010101],B[1010101];
int L[1010101],R[1010101];
ll pat[2][1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) {
		A[i+1]=A[i], L[i+1]=L[i];
		if(S[i]=='(') A[i+1]++;
		if(S[i]=='?') L[i+1]++;
	}
	for(i=N-1;i>=0;i--) {
		B[i+1]=B[i+2];
		R[i+1]=R[i+2];
		if(S[i]==')') B[i+1]++;
		if(S[i]=='?') R[i+1]++;
	}
	
	for(i=L[N];i>=0;i--) pat[0][i]=(comb(L[N],i)+pat[0][i+1])%mo;
	for(i=L[N]-1;i>=0;i--) pat[1][i]=(comb(L[N]-1,i)+pat[1][i+1])%mo;
	
	ll ret=0;
	FOR(i,N-1) if(S[i]=='(' || S[i]=='?') {
		int X=1+A[i];
		int Y=B[i+2];
		int C=L[i];
		
		ret+=pat[S[i]=='?'][max(0,X-Y+C)];
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}