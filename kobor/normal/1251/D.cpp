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

const int N=2e5+5;

int n;
ll s;
ii gosc[N];
vii spoko;

bool check(ll val){
	ll sum=0;
	spoko.clear();
	FOR(i, 1, n){
		if(gosc[i].nd>=val) spoko.pb(gosc[i]);
		else sum+=gosc[i].st;
	}
	int ludzi=(n+1)/2;
	if(SIZE(spoko)<ludzi) return 0;
	sort(spoko.begin(), spoko.end());
	FOR(i, 0, SIZE(spoko)-ludzi-1) sum+=spoko[i].st;
	FOR(i, SIZE(spoko)-ludzi, SIZE(spoko)-1) sum+=max((ll)spoko[i].st, val);
	return sum<=s;
}

void solve(){
	cin>>n>>s;
	FOR(i, 1, n) cin>>gosc[i].st>>gosc[i].nd;
	ll l=0, r=1e10, mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}