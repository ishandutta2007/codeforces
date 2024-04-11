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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

const int N=1e5+5;
const ll MOD=1e9+7;

int sieve[10*N], t[N];
vi rozkl;
ll dp[10*N];

void makeg(int a){
	rozkl.clear();
	int val=sqrt(a);
	if(a==val*val){
		rozkl.pb(val);
		val--;
	}
	if(a!=1){
		FOR(i, 1, val){
			if(a%i==0){
				rozkl.pb(i);
				rozkl.pb(a/i);
			}
		}
	}
	sort(rozkl.begin(), rozkl.end());
	FORD(i, SIZE(rozkl)-1, 0){
		// cout<<"dodaje do: "<<rozkl[i]<<ent;
		dp[rozkl[i]]+=dp[rozkl[i]-1];
		dp[rozkl[i]]%=MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll odp=0;
	cin>>n;
	FOR(i, 1, n){
		cin>>t[i];
	}
	// FOR(i, 2, 10^3+10){
	// 	if(!sieve[i]){
	// 		for(int j=i*i; j<=N-3; j+=i){
	// 			sieve[j]=i;
	// 		}
	// 	}
	// }
	dp[0]=1;
	FOR(i, 1, n){
		makeg(t[i]);
	}
	FOR(i, 1, n){
		// cout<<dp[i]<<sp;
		odp=(odp+dp[i])%MOD;
	}
	cout<<odp<<ent;
	return 0;
}