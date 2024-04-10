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

ll mo=1000000007;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

int N;
string S;
int C[256],Q;

ll dp[101010],dp2[101010],dp3[101010];
ll ret[52][52];


void solve() {
	int i,j,k,l,r,x,y; string s;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>S;
	N=S.size();
	FORR(c,S) {
		if(c>='a' && c<='z') c=c-'a';
		if(c>='A' && c<='Z') c=c-'A'+26;
		C[c]++;
	}
	
	ll pat=2*fact[N/2]*fact[N/2]%mo;
	FOR(i,52) pat=pat*factr[C[i]]%mo;
	
	dp[0]=1;
	FOR(i,52) if(C[i]) for(j=N;j>=0;j--) if(dp[j]) (dp[j+C[i]]+=dp[j])%=mo;
	FOR(x,52) {
		memmove(dp2,dp,sizeof(dp));
		for(i=N;i>=C[x];i--) {
			dp2[i-C[x]]-=dp2[i];
			if(dp2[i-C[x]]<0) dp2[i-C[x]]+=mo;
		}
		ret[x][x]=dp2[N/2];
		for(y=x+1;y<52;y++) {
			memmove(dp3,dp2,sizeof(dp2));
			for(i=N;i>=C[y];i--) {
				dp3[i-C[y]]-=dp3[i];
				if(dp3[i-C[y]]<0) dp3[i-C[y]]+=mo;
			}
			ret[x][y]=dp3[N/2];
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		int a,b;
		a=S[x-1];
		b=S[y-1];
		if(a>b) swap(a,b);
		cout<<(ret[a][b]*pat%mo)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}