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

int a, b, c;

void solve(){
	cin>>a>>b>>c;
	if(b==0){
		if(a > 0) FOR(i, 1, a+1) cout<<0;
		else FOR(i, 1, c+1) cout<<1;
	}
	else{
		FOR(i, 1, b+1){
			if(i == 1) FOR(j, 1, c) cout<<1;
			if(i == 2) FOR(j, 1, a) cout<<0;
			cout<<i%2;
		}
	}
	cout<<'\n';
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