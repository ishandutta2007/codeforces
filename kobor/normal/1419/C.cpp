#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

void solve(){
	int n, x, ile = 0, sum = 0;
	cin >> n >> x;
	FOR(i, 0, n){
		int a;
		cin >> a;
		ile += a == x;
		sum += a;
	}
	if(ile == n){
		cout << 0 << '\n';
		return;
	}
	if(ile >= 1 || n*x == sum){
		cout << 1 << '\n';
		return;
	}
	cout << 2 << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin>>tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}