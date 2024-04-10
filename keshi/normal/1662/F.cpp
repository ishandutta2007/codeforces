//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 100;

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

int t, n, a, b, p[maxn];
pii seg0[maxn << 2];

void bld0(int id, int s, int e){
	if(e - s == 1){
		seg0[id] = Mp(s - p[s], s);
		return;
	}
	int mid = (s + e) >> 1;
	bld0(lc, s, mid);
	bld0(rc, mid, e);
	seg0[id] = min(seg0[lc], seg0[rc]);
	return;
}
void upd0(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg0[id] = Mp(inf, s);
		return;
	}
	int mid = (s + e) >> 1;
	upd0(lc, s, mid, l, r);
	upd0(rc, mid, e, l, r);
	seg0[id] = min(seg0[lc], seg0[rc]);
	return;
}
pii get0(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return Mp(inf, inf);
	if(l <= s && e <= r) return seg0[id];
	int mid = (s + e) >> 1;
	return min(get0(lc, s, mid, l, r), get0(rc, mid, e, l, r));
}

pii seg1[maxn << 2];

void bld1(int id, int s, int e){
	if(e - s == 1){
		seg1[id] = Mp(s + p[s], s);
		return;
	}
	int mid = (s + e) >> 1;
	bld1(lc, s, mid);
	bld1(rc, mid, e);
	seg1[id] = max(seg1[lc], seg1[rc]);
	return;
}
void upd1(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg1[id] = Mp(-inf, s);
		return;
	}
	int mid = (s + e) >> 1;
	upd1(lc, s, mid, l, r);
	upd1(rc, mid, e, l, r);
	seg1[id] = max(seg1[lc], seg1[rc]);
	return;
}
pii get1(int id, int s, int e, int l, int r){
	if(r <= s || e <= l) return Mp(-inf, -inf);
	if(l <= s && e <= r) return seg1[id];
	int mid = (s + e) >> 1;
	return max(get1(lc, s, mid, l, r), get1(rc, mid, e, l, r));
}

bool vis[maxn];
int dis[maxn];
queue<int> q;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		a--;
		b--;
		for(int i = 0; i < n; i++){
			vis[i] = 0;
			dis[i] = inf;
			cin >> p[i];
		}
		bld0(1, 0, n);
		bld1(1, 0, n);
		dis[b] = 0;
		vis[b] = 1;
		q.push(b);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			pii x = get0(1, 0, n, v + 1, v + p[v] + 1);
			while(x.F <= v){
				if(!vis[x.S]){
					vis[x.S] = 1;
					dis[x.S] = dis[v] + 1;
					q.push(x.S);
				}
				upd0(1, 0, n, x.S, x.S + 1);
				x = get0(1, 0, n, v + 1, v + p[v] + 1);
			}
			x = get1(1, 0, n, v - p[v], v);
			while(x.F >= v){
				if(!vis[x.S]){
					vis[x.S] = 1;
					dis[x.S] = dis[v] + 1;
					q.push(x.S);
				}
				upd1(1, 0, n, x.S, x.S + 1);
				x = get1(1, 0, n, v - p[v], v);
			}
		}
		cout << dis[a] << "\n";
	}
	
	return 0;
}