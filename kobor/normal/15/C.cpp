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

ll query(ll a){
	ll ret=0;
	while((a&3)!=3) ret^=a--;
	return ret;
}

void solve(){
	ll a, b, xorsum=0;
	int n;
	cin>>n;
	FOR(i, 1, n){
		cin>>a>>b;
		xorsum^=query(a-1)^query(a+b-1);
	}
	cout<<(xorsum == 0 ? "b" : "t")<<"olik\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}