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

int H,W,N;
int NGR[3601],NGC[3601];
int okR,okC;
const ll mo=998244353;

const int NUM_=400001;
ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

vector<ll> Rdp,Cdp;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		FOR(j,2) {
			cin>>y>>x;
			NGR[y-1]=1;
			NGC[x-1]=1;
		}
	}
	
	vector<ll> Rdp[3],Cdp[3];
	FOR(i,3) Rdp[i].resize(2401),Cdp[i].resize(2401);
	Rdp[1][0]=Cdp[1][0]=1;
	
	FOR(y,H) {
		if(NGR[y]==0) okR++;
		Rdp[0]=Rdp[1];
		if(y&&NGR[y]==0&&NGR[y-1]==0) {
			FOR(i,2400) (Rdp[0][i+1]+=Rdp[2][i])%=mo;
		}
		swap(Rdp[1],Rdp[2]);
		swap(Rdp[0],Rdp[1]);
	}
	
	FOR(x,W) {
		if(NGC[x]==0) okC++;
		Cdp[0]=Cdp[1];
		if(x&&NGC[x]==0&&NGC[x-1]==0) {
			FOR(i,2400) (Cdp[0][i+1]+=Cdp[2][i])%=mo;
		}
		swap(Cdp[1],Cdp[2]);
		swap(Cdp[0],Cdp[1]);
	}
	
	ll ret=0;
	comb(0,0);
	FOR(x,2401) FOR(y,2401) {
		//cout<<x<<" "<<y<<" "<<Rdp[x]*Cdp[y]%mo*comb(okR-2*x,y)%mo*comb(okC-2*y,x)<<endl;
		(ret+=Rdp[1][x]*Cdp[1][y]%mo*comb(okR-2*x,y)%mo*fact[y]%mo*fact[x]%mo*comb(okC-2*y,x))%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}