#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}

#define NEUTRAL 9223372036854775807
#define NEUTRAL_LAZY 0
#define COMBINE(a, b) (min(a, b))
#define L(a) (2*a)
#define R(a) (2*a+1)
#define OUT (l>=rb || r<=lb)
#define LEAF (idx>=POW)
#define FULL (l<=lb && r>=rb)

struct segmentTree{
    ll POW, N;
    vector<ll> tree, lazy;
    segmentTree(ll n):N(n){
        POW = pow(2, ceil(log2(N)));
        tree.assign(2*POW, NEUTRAL);
        lazy.assign(2*POW, NEUTRAL_LAZY);
        for (ll i = 0; i < N; i++) tree[i + POW] = 0;
        for (ll i = POW - 1; i > 0; i--) tree[i] = COMBINE(tree[L(i)], tree[R(i)]);
    }
    ll realVal(ll idx) { return tree[idx] + lazy[idx]; }
    void applyLazy(ll idx){
        if (lazy[idx] != NEUTRAL_LAZY){
            tree[idx] = realVal(idx);
            lazy[L(idx)] += lazy[idx];
            lazy[R(idx)] += lazy[idx];
            lazy[idx] = NEUTRAL_LAZY;
        }
    }
    ll query(ll l, ll r) { return query(l, r, 0, POW, 1); }
    ll query(ll l, ll r, ll lb, ll rb, ll idx){
        if (OUT) return NEUTRAL;
        if (LEAF) return realVal(idx);
        if (FULL) return realVal(idx);
        applyLazy(idx);
        ll mid = (lb + rb) / 2;
        return COMBINE(query(l, r, lb, mid, L(idx)), query(l, r, mid, rb, R(idx)));
    }
    void update(ll l, ll r, ll val) { update(l, r, 0, POW, 1, val); }
    void update(ll l, ll r, ll lb, ll rb, ll idx, ll val){
        if (OUT) return;
        if (LEAF) { lazy[idx] += val; return; }
        if (FULL) { lazy[idx] += val; return; }
        applyLazy(idx);
        ll mid = (lb + rb) / 2;
        update(l, r, lb, mid, L(idx), val);
        update(l, r, mid, rb, R(idx), val);
        tree[idx] = COMBINE(realVal(L(idx)), realVal(R(idx)));
    }
};
void solve(){
	ll n = nxt(), k = nxt();
	vec<ll> nums(n);
	generate(all(nums), nxt);
	segmentTree sg(2*k+1);
	for (ll i = 0; i < n/2; ++i){
		ll sm = nums[i] + nums[n-i-1];
		ll top = max(nums[i], nums[n-i-1]) + k;
		ll bot = min(nums[i], nums[n-i-1]) + 1;
		if (sm != top) sg.update(sm+1, top+1, 1);
		if (top != 2*k) sg.update(top+1, 2*k+1, 2);
		if (sm != bot) sg.update(bot, sm, 1);
		sg.update(0, bot, 2);
	}
	ll mn = sg.query(0, 2*k+1);
	cout << mn << endl;	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	cin >> t;
	for (ll i = 1; i < t+1; ++i){ 
		solve();
	}
}