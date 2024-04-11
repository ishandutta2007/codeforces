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

const int N=5e5+5;

int t[N], n;
ii t2[N];
ll ans;
set<int> ava;

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) t2[i]={t[i], i};
	FOR(i, 1, n) ava.insert(i);
	sort(t2+1, t2+n+1);
	FOR(i, 1, n-2){
		ans+=(t2[i].st-t2[i-1].st)*(n-i-1);
		auto gosc=ava.find(t2[i].nd);
		if(gosc!=ava.begin() && next(gosc)!=ava.end()) ans+=min(t[*prev(gosc)], t[*next(gosc)])-t2[i].st;
		ava.erase(t2[i].nd);
	}
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