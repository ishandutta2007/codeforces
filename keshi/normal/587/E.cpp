//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll lg = 30;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)

struct node{
	ll base[lg];
	node(){
		fill(base, base + lg, 0);
	}
};

ll n, a[maxn], q, fen[maxn], b[maxn];
node seg[maxn << 2];

node mrg(node l, node r){
	for(ll i = 0; i < lg; i++){
		if(!r.base[i]) continue;
		for(ll j = i + 1; j--;){
			if(!((r.base[i] >> j) & 1)) continue;
			if(l.base[j]){
				r.base[i] ^= l.base[j];
			}
			else{
				l.base[j] = r.base[i];
				break;
			}
		}
	}
	return l;
}

void bld(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return;
	if(e - s == 1){
		seg[id] = node();
		for(ll i = lg; i--;){
			if((a[s] >> i) & 1){
				seg[id].base[i] = a[s];
				break;
			}
		}
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid, l, r);
	bld(rc, mid, e, l, r);
	seg[id] = mrg(seg[lc], seg[rc]);
}
node get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return node();
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) >> 1;
	return mrg(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}

void fup(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen[x] ^= y;
	}
	return;
}
ll fge(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y ^= fen[x];
	}
	return y;
}

int main(){
    fast_io;
    
    cin >> n >> q;
    for(ll i = 0; i < n; i++){
    	cin >> b[i];
    	a[i] = b[i];
    	if(i) a[i] ^= b[i - 1];
	}
	bld(1, 0, n, 0, n);
	while(q--){
		ll t, l, r, x;
		cin >> t >> l >> r;
		l -= 1;
		if(t == 2){
			node p = get(1, 0, n, l + 1, r);
			x = fge(l) ^ b[l];
			for(ll i = lg; i--;){
				if((x >> i) & 1){
					if(p.base[i]){
						x ^= p.base[i];
					}
					else{
						p.base[i] = x;
						break;
					}
				}
			}
			ll y = 0;
			for(ll i = 0; i < lg; i++){
				if(p.base[i]) y++;
			}
			cout << (1 << y) << "\n";
		}
		else{
			cin >> x;
			a[l] ^= x;
			bld(1, 0, n, l, l + 1);
			fup(l, x);
			a[r] ^= x;
			bld(1, 0, n, r, r + 1);
			fup(r, x);
		}
	}
 
    return 0;
}