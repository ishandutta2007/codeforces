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


int T;
int N,L,R;
const ll mo=1000000007;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_==0) return 1;
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>R;
		ll ret=0;
		
		for(int CL=N,CR=1;CR<=N;CR++) {
			while(CL>1&&CL-1-L>R-CR) CL--;
			if(CL>=CR) continue;
			int len=R-CR;
			int cand=CR-CL;
			int mi=N-CR;
			
			
			if(N%2==0) {
				if(N/2-mi>0) (ret+=len*comb(cand,N/2-mi))%=mo;
			}
			else {
				if(N/2-mi>0) (ret+=len*comb(cand,N/2-mi))%=mo;
				if(N/2+1-mi>0) (ret+=len*comb(cand,N/2+1-mi))%=mo;
			}
		}
		for(int CR=1,CL=N;CL>=1;CL--) {
			while(CR<N&&CL-L<=R-(CR+1)) CR++;
			if(CL>=CR) continue;
			int len=CL-L;
			
			int cand=CR-CL;
			int pl=CL-1;
			
			if(N%2==0) {
				if(N/2-pl>0) (ret+=len*comb(cand,N/2-pl))%=mo;
			}
			else {
				if(N/2-pl>0) (ret+=len*comb(cand,N/2-pl))%=mo;
				if(N/2+1-pl>0) (ret+=len*comb(cand,N/2+1-pl))%=mo;
			}
			
		}
		
		for(x=1;x<=N;x++) {
			y=N-x;
			if(abs(x-y)<=1) {
				ret+=min(R-x,(x+1)-L);
				ret%=mo;
			}
		}
		
		/*
		for(x=1;x<=N;x++) { // left minus
			for(y=1+1;y<=N;y++) {// right plus
				int pl=x;
				int mi=N-y+1;
				
				int len=min(R-y,x-L);
				
				if(N%2==0) ret+=len*comb(N-(pl+mi),N/2-mi);
				else {
					ret+=len*comb(N-(pl+mi),N/2-mi);
					ret+=len*comb(N-(pl+mi),N/2+1-mi);
				}
				ret%=mo;
			}
		}
		*/
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}