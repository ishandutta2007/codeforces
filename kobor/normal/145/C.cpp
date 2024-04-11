//Krzysztof Boryczka
#pragma GCC optimize "O3"
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
const int N=1030;
const int K=1e5+5;

int n, k, pom, il, akt=1, ans;
vi luckys;
int grpk[N], dp[K]={1};
int frac[K]={1}, invf[K]={1};

bool lucky(int a){
	while(a){
		if(a%10!=4 && a%10!=7) return 0;
		a/=10;
	}
	return 1;
}

int pov(int base, int exp){
	int ret=1;
	while(exp){
		if(exp&1) ret=(ll)ret*base%mod;
		base=(ll)base*base%mod;
		exp>>=1;
	}
	return ret;
}

int binom(int a, int b){
	if(a<0 || b<0 || a<b) return 0;
	return (ll)frac[a]*invf[b]%mod*invf[a-b]%mod;
}

void solve(){
	FOR(i, 1, K-3) frac[i]=(ll)frac[i-1]*i%mod;
	FOR(i, 1, K-3) invf[i]=pov(frac[i], mod-2);
	cin>>n>>k;
	FOR(i, 1, n){
		cin>>pom;
		if(lucky(pom)) luckys.pb(pom);
	}
	sort(luckys.begin(), luckys.end());
	FOR(i, 1, SIZE(luckys)-1){
		if(luckys[i]!=luckys[i-1]){
			grpk[++il]=akt;
			akt=0;
		}
		akt++;
	}
	if(SIZE(luckys)) grpk[++il]=akt;
	FOR(i, 1, il){
		FORD(j, k, 1) dp[j]=(dp[j]+(ll)dp[j-1]*grpk[i])%mod;
	}
	FOR(i, 0, k) ans=(ans+(ll)dp[i]*binom(n-SIZE(luckys), k-i))%mod;
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}