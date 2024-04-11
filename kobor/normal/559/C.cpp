//Krzysztof Boryczka
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int mod=1e9+7;
const int M=2e5+5;
const int N=2010;

int h, w, n;
int fact[M]={1}, invf[M]={1}, dp[N];
ii t[N];

int pov(int base, int exp){
	int ret=1;
	while(exp){
		if(exp&1) ret=(ll)ret*base%mod;
		base=(ll)base*base%mod;
		exp>>=1;
	}
	return ret;
}

int binom(int m, int k){
	if(m<0 || k<0 || k>m) return 0;
	return (ll)fact[m]*invf[k]%mod*invf[m-k]%mod;
}

int grid(int m, int k){
	return binom(m+k-2, m-1);
}

void solve(){
	FOR(i, 1, M-3) fact[i]=(ll)fact[i-1]*i%mod;
	FOR(i, 1, M-3) invf[i]=pov(fact[i], mod-2);
	cin>>h>>w>>n;
	FOR(i, 1, n) cin>>t[i].st>>t[i].nd;
	t[n+1]={h, w};
	sort(t+1, t+n+1);
	FOR(i, 1, n+1){
		dp[i]=grid(t[i].st, t[i].nd);
		FOR(j, 1, i-1) dp[i]=((dp[i]-(ll)dp[j]*grid(t[i].st-t[j].st+1, t[i].nd-t[j].nd+1))%mod+mod)%mod;
	}
	cout<<dp[n+1]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}