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
	int n, a;
	bool off=0;
	bool flip=0;
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		if(a!=1) off=1;
		else if(!off) flip^=1;
	}
	flip^=off;
	cout<<(flip ? "First" : "Second")<<ent;
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