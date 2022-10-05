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


int N,M;
int L[303030],R[303030];
int A[21],B[21];
int S[303030];
int T[303030];
int sel[303030];
ll num[303030][41];
const ll mo=998244353;
ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(N_<0 || C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>L[i]>>R[i];
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		//S[A[i]]=1;
		//S[B[i]]=1;
	}
	FOR(i,N) if(S[i]==0) {
		T[L[i]]++;
		T[R[i]+1]--;
	}
	
	for(i=1;i<=N;i++) {
		T[i]+=T[i-1];
		//cout<<i<<" "<<T[i]<<endl;
		FOR(j,41) {
			num[i][j]=(comb(T[i]-j,i-j)+num[i-1][j])%mo;
		}
	}
	
	ll ret=0;
	int mask;
	FOR(mask,1<<M) {
		int TL=1,TR=N,del=0;
		FOR(i,M) if(mask&(1<<i)) {
			if(sel[A[i]]==0) {
				del++;
				sel[A[i]]++;
				TL=max(TL,L[A[i]]);
				TR=min(TR,R[A[i]]);
			}
			if(sel[B[i]]==0) {
				del++;
				sel[B[i]]++;
				TL=max(TL,L[B[i]]);
				TR=min(TR,R[B[i]]);
			}
		}
		
		TL=max(TL,del);
		if(TL<=TR) {
			ll tmp=num[TR][del]-num[TL-1][del];
			//cout<<mask<<" "<<del<<" "<<tmp<<endl;
			if(__builtin_popcount(mask)%2==1) {
				ret-=tmp;
			}
			else {
				ret+=tmp;
			}
		}
		
		FOR(i,M) sel[A[i]]=sel[B[i]]=0;
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}