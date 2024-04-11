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

const int N=1e5+5;

int n, m;
ll a[N], b[N];

void solve(){
	cin>>n>>m;
	FOR(i, 1, n) cin>>a[i];
	FOR(i, 1, m) cin>>b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	FOR(i, 1, n) a[i]+=a[i-1];
	FOR(i, 1, m) b[i]+=b[i-1];
	ll ans=INF;
	FOR(i, 1, n) if((INF-a[n-i])/i>=b[m]) ans=min(ans, a[n-i]+b[m]*i);
	FOR(i, 1, m) if((INF-b[m-i])/i>=a[n]) ans=min(ans, b[m-i]+a[n]*i);
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}