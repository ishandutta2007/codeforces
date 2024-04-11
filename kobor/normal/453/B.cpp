//Krzysztof Boryczka
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

const int M=(1<<16)-1;

int pomq, n, mask, ans=inf;
int dp[110][M+2], liczba[110][M+2], trace[110][M+2];
int t[110];
vi wypsz, primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int ind[60], fact[60];

int gen(int v){
	int ret=0;
	for(auto x: primes){
		if(v%x==0) ret|=(1<<ind[x]);
	}
	return ret;
}

void solve(){
	FOR(i, 0, SIZE(primes)-1) ind[primes[i]]=i;
	FOR(i, 1, 58) fact[i]=gen(i);
	memset(dp, inf, sizeof(dp));
	FOR(j, 0, M) dp[0][j]=0;
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n){
		FOR(k, 1, 58){
			mask=(~fact[k]) & M;
			for(int s=mask; ; s=(s-1)&mask){
				if(dp[i-1][s]+abs(t[i]-k)<dp[i][s|fact[k]]){
					dp[i][s|fact[k]]=dp[i-1][s]+abs(t[i]-k);
					liczba[i][s|fact[k]]=k;
					trace[i][s|fact[k]]=s;
				}
				if(s==0) break;
			}
		}
	}
	FOR(j, 0, M){
		if(dp[n][j]<ans){
			ans=dp[n][j];
			pomq=j;
		}
	}
	FORD(i, n, 1){
		wypsz.pb(liczba[i][pomq]);
		pomq=trace[i][pomq];
	}
	FORD(i, SIZE(wypsz)-1, 0) cout<<wypsz[i]<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}