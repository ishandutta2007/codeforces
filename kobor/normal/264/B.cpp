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

const int N=1e5+5;

int lp[N];
int dp[N], t[N];
int n;
vi rozkl[N], inds[N];

void sieve(){
	for(int i=2; i*i<=N-2; i++){
		if(lp[i]) continue;
		for(int j=i*i; j<=N-2; j+=i){
			if(!lp[j]) lp[j]=i;
		}
	}
}

void factor(int a){
	int pom, val=t[a];
	while(val>1){
		pom=lp[val];
		if(!pom) pom=val;
		inds[pom].pb(a);
		rozkl[a].pb(pom);
		while(val%pom==0) val/=pom;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	sieve();
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) factor(i);
	FOR(i, 1, n){
		dp[i]=1;
		for(auto x: rozkl[i]){
			int wh=lower_bound(inds[x].begin(), inds[x].end(), i)-inds[x].begin()-1;
			if(wh>=0) dp[i]=max(dp[i], dp[inds[x][wh]]+1);
		}
	}
	cout<<*max_element(dp+1, dp+n+1)<<ent;
	return 0;
}