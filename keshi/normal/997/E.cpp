//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define lc (id << 1)
#define rc (lc | 1)

ll n, a[maxn], lz[maxn], mn[maxn], cnt[maxn], ans[maxn], s2[maxn], lz2[maxn], q;
vector<ll> st, ts;
vector<pll> g[maxn];

void bld(ll id, ll s, ll e){
    mn[id] = 1;
    cnt[id] = e - s;
    if(e - s == 1) return;
    ll mid = (s + e) / 2;
    bld(lc, s, mid);
    bld(rc, mid, e);
    return;
}

void shift(ll id){
    mn[lc] += lz[id];
    lz[lc] += lz[id];
    mn[rc] += lz[id];
    lz[rc] += lz[id];
    lz[id] = 0;
	if(mn[id] == mn[lc]){
		s2[lc] += lz2[id] * cnt[lc];
		lz2[lc] += lz2[id];
	}
	if(mn[id] == mn[rc]){
		s2[rc] += lz2[id] * cnt[rc];
		lz2[rc] += lz2[id];
	}
	lz2[id] = 0;
	return;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        mn[id] += x;
        lz[id] += x;
        return;
    }
    ll mid = (s + e) / 2;
	shift(id);
    upd(lc, s, mid, l, r, x);
    upd(rc, mid, e, l, r, x);
    mn[id] = min(mn[lc], mn[rc]);
    cnt[id] = 0;
    if(mn[id] == mn[lc]) cnt[id] += cnt[lc];
    if(mn[id] == mn[rc]) cnt[id] += cnt[rc];
    return;
}

ll get2(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return s2[id];
	ll mid = (s + e) >> 1;
	shift(id);
	return get2(lc, s, mid, l, r) + get2(rc, mid, e, l, r);
}

int main(){
    fast_io;

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
		a[i]--;
    }
	cin >> q;
	for(ll i = 0; i < q; i++){
		ll l, r;
		cin >> l >> r;
		g[r - 1].pb(Mp(l - 1, i));
	}
    bld(1, 0, n);
    st.pb(-1);
    ts.pb(-1);
    for(ll i = 0; i < n; i++){
        while(st.back() != -1 && a[i] > a[st.back()]){
            ll x = a[i] - a[st.back()];
            st.pop_back();
            upd(1, 0, n, st.back() + 1, i, x);
        }
        st.pb(i);
        while(ts.back() != -1 && a[i] < a[ts.back()]){
            ll x = a[ts.back()] - a[i];
            ts.pop_back();
            upd(1, 0, n, ts.back() + 1, i, x);
        }
        ts.pb(i);
        upd(1, 0, n, 0, i + 1, -1);
		s2[1] += cnt[1];
		lz2[1]++;
		for(pll j : g[i]){
			ans[j.S] = get2(1, 0, n, j.F, i + 1);
		}
    }
	for(ll i = 0; i < q; i++){
		cout << ans[i] << "\n";
	}

    return 0;
}