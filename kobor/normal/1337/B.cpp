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

bool f(int x, int n, int m){
	if(x<=0) return 1;
	if(x>20 && n>0) return f(x/2 + 10, n-1, m);
	if(m>0) return f(x-10, n, m-1);
	return 0;
}

void solve(){
	int x, n, m;
	cin>>x>>n>>m;
	cout<<(f(x, n, m) ? "YES" : "NO")<<ent;
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