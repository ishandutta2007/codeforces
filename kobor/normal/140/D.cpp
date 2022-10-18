// Krzysztof Boryczka
#pragma GCC optimize("O3")
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

const int N=110;

int t[N];

void solve(){
	int n, ans=0, bula=0;
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	sort(t+1, t+n+1);
	int tim=10;
	FOR(i, 1, n){
		tim+=t[i];
		if(tim>720) break;
		ans++;
		bula+=max(0, tim-360);
	}
	cout<<ans<<sp<<bula<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt){
	// 	cout<<"Case #"<<te<<": ";
	// 	solve();
	// }
	solve();
	return 0;
}