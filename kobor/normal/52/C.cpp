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

const int T = 1 << 18;

ll t[T*2+5], lazy[T*2+5];

void push(int v){
	t[v*2] += lazy[v];
	t[v*2+1] += lazy[v];
	lazy[v*2] += lazy[v];
	lazy[v*2+1] += lazy[v];
	lazy[v] = 0;
}

void pull(int v){
	t[v] = min(t[v*2], t[v*2+1]);
}

void add(int l, int r, int val, int v = 1, int le = 0, int re = T-1){
	if(l > re || r < le) return;
	if(l <= le && re <= r){
		t[v] += val, lazy[v] += val;
		return;
	}
	push(v);
	int mid = (le+re)/2;
	add(l, r, val, v*2, le, mid), add(l, r, val, v*2+1, mid+1, re);
	pull(v);
}

ll query(int l, int r, int v = 1, int le = 0, int re = T-1){
	if(l > re || r < le) return 1ll*INF*INF;
	if(l <= le && re <= r) return t[v];
	push(v);
	int mid = (le+re)/2;
	ll ret = min(query(l, r, v*2, le, mid), query(l, r, v*2+1, mid+1, re));
	pull(v);
	return ret;
}

void solve(){
	int n, m;
	cin >> n;
	memset(t, INF, sizeof(t));
	FOR(i, 0, n) cin >> t[i+T];
	for(int i = T-1; i > 0; i--) t[i] = min(t[i*2], t[i*2+1]);
	cin >> m;
	cin.ignore();
	FOR(i, 0, m){
		string s;
		getline(cin, s);
		int ile = 0;
		TRAV(x, s) ile += x == ' ';
		stringstream hin(s);
		if(ile == 2){
			int a, b, v;
			hin >> a >> b >> v;
			if(a > b) add(0, b, v), add(a, n-1, v);
			else add(a, b, v);
		}
		else{
			int a, b;
			hin >> a >> b;
			if(a > b) cout << min(query(0, b), query(a, n-1)) << '\n';
			else cout << query(a, b) << '\n';
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