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

int n, k;
vector<vi> t;

bool ok(vi a, vi b){
	FOR(i, 0, SIZE(a)-1) if(a[i] && b[i]) return 0;
	return 1;
}

void solve(){
	int a;
	cin>>n>>k;
	FOR(i, 1, n){
		vi xd;
		FOR(j, 1, k){
			cin>>a;
			xd.pb(a);
		}
		t.pb(xd);
	}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for(auto &x: t) for(auto &y: t){
		if(ok(x, y)){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}