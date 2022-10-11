//In the name of God
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 4e6 + 100;
const ll mod = 1e9 + 7;
const int inf = 2e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int seg[maxn], cnt;

void bld(int id, int s, int e){
	seg[id] = inf;
	if(e - s == 1) return;
	int mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	return;
}
void upd(int id, int s, int e, int l, int r, int x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = x;
		return;
	}
	int mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = min(seg[lc], seg[rc]);
	return;
}
int fnd(int id, int s, int e, int l, int r, int x){
	if(r <= s || e <= l) return -1;
	if(seg[id] > x) return -1;
	if(e - s == 1) return s;
	int mid = (s + e) >> 1;
	int y = fnd(lc, s, mid, l, r, x);
	if(~y) return y;
	return fnd(rc, mid, e, l, r, x);
}

int n, q, a[maxn];
bool b[maxn];
vector<int> vec;
map<int, bool> vis;

int main(){
	fast_io;
	
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		char ch;
		cin >> a[i] >> a[i] >> ch;
		b[i] = (ch == 'U');
		vec.pb(a[i]);
		vec.pb(n + 1 - a[i]);
	}
	vec.pb(0);
	vec.pb(n + 1);
	sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin());
	int N = Sz(vec) * 2;
	bld(1, 0, N);
	upd(1, 0, N, Sz(vec) - 1, Sz(vec), -inf);
	upd(1, 0, N, N - 1, N, -inf);
	for(int i = 0; i < q; i++){
		if(b[i]){
			if(vis[a[i]]){
				cout << "0\n";
				continue;
			}
			vis[a[i]] = 1;
			int xi = lower_bound(all(vec), a[i]) - vec.begin();
			int y = n + 1 - a[i];
			int yi = lower_bound(all(vec), y) - vec.begin();
			int c = fnd(1, 0, N, yi, Sz(vec), -a[i]);
			cout << vec[c] - y << "\n";
			upd(1, 0, N, Sz(vec) + xi, Sz(vec) + xi + 1, -vec[c]);
		}
		else{
			if(vis[a[i]]){
				cout << "0\n";
				continue;
			}
			vis[a[i]] = 1;
			int xi = lower_bound(all(vec), a[i]) - vec.begin();
			int y = n + 1 - a[i];
			int yi = lower_bound(all(vec), y) - vec.begin();
			int c = fnd(1, 0, N, Sz(vec) + xi, N, -y) - Sz(vec);
			cout << vec[c] - a[i] << "\n";
			upd(1, 0, N, yi, yi + 1, -vec[c]);
		}
	}
	
	return 0;
}