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

const int N=1e5+5;

int n;
char a[N], b[N];

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>a[i];
	FOR(i, 1, n) cin>>b[i];
	vi ans;
	int l=1, r=n;
	FORD(i, n, 1){
		if((n-i)%2 == 0){
			if(a[l] == b[i]) ans.pb(1);
			l++;
		}
		else{
			if(a[r] != b[i]) ans.pb(1);
			r--;
		}
		ans.pb(i);
	}
	cout<<SIZE(ans)<<sp;
	for(auto &x: ans) cout<<x<<sp;
	cout<<ent;
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