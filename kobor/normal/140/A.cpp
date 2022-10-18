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



void solve(){
	int n, r, R;
	cin>>n>>R>>r;
	double RP=(n==1 ? 0.0 : sqrt(2.0/(1-cos(2.0*acos(-1.0)/n)))*r);
	cout<<(RP+r <= R+1e-9 ? "YES" : "NO")<<ent;
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