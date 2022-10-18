// Krzysztof Boryczka
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

void solve(){
	int n, k, odj=1;
	cin>>n>>k;
	if(n%2 == 1 && k%2 == 0){
		cout<<"NO\n";
		return;
	}
	if(n%2 == 0 && k%2 == 1) odj++;
	if(n-(k-1)*odj <= 0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	FOR(i, 1, k-1) cout<<odj<<' ';
	cout<<n-(k-1)*odj<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt){
		// cout<<"Case #"<<te<<": ";
		solve();
	}
	// solve();
	return 0;
}