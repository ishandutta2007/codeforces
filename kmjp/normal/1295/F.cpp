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
int L[51],R[51];
const ll mo=998244353;

ll dp[60][120];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		R[i]++;
		V.push_back(L[i]);
		V.push_back(R[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	dp[0][V.size()-1]=1;
	FOR(x,N) {
		FOR(y,V.size()-1) {
			ll sum=0;
			for(i=y+1;i<V.size();i++) sum+=dp[x][i];
			sum%=mo;
			if(sum==0) continue;
			for(i=x;i<N;i++) {
				if(L[i]<=V[y]&&V[y]<R[i]) {
					(sum*=(V[y+1]-V[y])*modpow(R[i]-L[i])%mo)%=mo;
					(dp[i+1][y]+=sum*comb(V[y+1]-V[y]-1+i+1-x,i+1-x)%mo*modpow(modpow(V[y+1]-V[y],i+1-x)))%=mo;
				}
				else {
					break;
				}
			}
		}
	}
	ll ret=0;
	FOR(y,V.size()) ret+=dp[N][y];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}