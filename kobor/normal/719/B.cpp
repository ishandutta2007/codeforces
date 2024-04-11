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

int n;
char t[N];

int licz(){
	int ret[2]={0, 0};
	FOR(i, 1, n) ret[i&1]+=t[i]!=(i&1);
	return max(ret[0], ret[1]);
}

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) t[i]=(t[i]=='r');
	int ans=licz();
	FOR(i, 1, n) t[i]^=1;
	ans=min(ans, licz());
	cout<<ans<<ent;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}