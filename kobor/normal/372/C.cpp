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

const int N=15e4+5;

int n, m, d;
ll dp[2][N];
int a[N], b[N], t[N]={-inf};

void licz(int w){
	deque<pair<ll, int> > q;
	ll przes=min((ll)(t[w]-t[w-1])*d, (ll)n);
	int l, r;
	l=-przes;
	r=przes;
	FOR(i, 1, r){
		while(!q.empty() && q.back().st<=dp[(w-1)&1][i]) q.pop_back();
		q.pb({dp[(w-1)&1][i], i});
	}
	FOR(i, 1, n){
		l++; r++;
		while(!q.empty() && q.front().nd<l) q.pop_front();
		if(r<=n){
			while(!q.empty() && q.back().st<=dp[(w-1)&1][r]) q.pop_back();
			q.pb({dp[(w-1)&1][r], r});
		}
		dp[w&1][i]=q.front().st+(b[w]-abs(a[w]-i));
	}
}

void solve(){
	ll ans=-INF;
	cin>>n>>m>>d;
	FOR(i, 1, m) cin>>a[i]>>b[i]>>t[i];
	FOR(j, 1, m) licz(j);
	FOR(i, 1, n) ans=max(ans, dp[m&1][i]);
	cout<<ans<<ent;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve(); 
	return 0;
}