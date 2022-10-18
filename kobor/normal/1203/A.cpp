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

int n;
int t[210];

bool gut(){
	int j;
	FOR(i, 0, n-1) if(t[i]==1) j=i;
	for(int k=j; (k+1)%n!=j; k=(k+1)%n) if(t[k]+1!=t[(k+1)%n]) return 0;
	return 1;
}

void solve(){
	cin>>n;
	FOR(i, 0, n-1) cin>>t[i];
	if(gut()){
		cout<<"YES\n";
		return;
	}
	reverse(t, t+n);
	if(gut()) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}