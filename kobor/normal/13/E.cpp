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

const int N = 1e5+5;
const int K = 300;

int n, m;
int jump[N], nast[N], ile[N];

void przelicz(int v){
	int u = v + jump[v];
	if(u/K == v/K && u < n){
		ile[v] = ile[u]+1;
		nast[v] = nast[u];
	}
	else{
		ile[v] = 1;
		nast[v] = u;
	}
}

ii pytaj(int v){
	int ret = 0;
	while(nast[v] < n){
		ret += ile[v];
		v = nast[v];
	}
	while(v + jump[v] < n){
		ret++;
		v += jump[v];
	}
	return {v+1, ret+1};
}

void solve(){
	cin >> n >> m;
	FOR(i, 0, n) cin >> jump[i];
	for(int i = n-1; i >= 0; i--) przelicz(i);
	FOR(i, 0, m){
		int typ, a, b;
		cin >> typ >> a;
		a--;
		if(typ == 0){
			cin >> b;
			jump[a] = b;
			for(int j = a; j >= 0 && j/K == a/K; j--) przelicz(j);
		}
		else{
			ii ans = pytaj(a);
			cout << ans.X << ' ' << ans.Y << '\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}