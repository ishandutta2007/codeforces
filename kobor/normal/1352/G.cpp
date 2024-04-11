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
	int n;
	cin>>n;
	if(n < 4) cout<<(n == 1 ? 1 : -1);
	else{
		for(int i=1; i<=n; i+=2){
			if(i == n-3) cout<<n-1;
			else if(i == n-1) cout<<n-3;
			else cout<<i;
			cout<<' ';
		}
		for(int i=n-n%2; i>=1; i-=2){
			if(i == n-3) cout<<n-1;
			else if(i == n-1) cout<<n-3;
			else cout<<i;
			cout<<' ';
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