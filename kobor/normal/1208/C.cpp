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

int t[1010][1010];

void solve(){
	int n; cin>>n;
	n/=2;
	FOR(i, 0, n-1){
		FOR(j, 0, n-1){
			t[i][j]=(i*n+j)*4;
			t[i+n][j]=(i*n+j)*4+1;
			t[i][j+n]=(i*n+j)*4+2;
			t[i+n][j+n]=(i*n+j)*4+3;
		}
	}
	FOR(i, 0, n*2-1){
		FOR(j, 0, n*2-1) cout<<t[i][j]<<sp;
		cout<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}