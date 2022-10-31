// Hydro submission #62c565ae8672efa577bec613@1657103791027
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define UP(a,b,c) for(ll (a)=(b);(a)<(c);++(a))
#define UU(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))
#define DN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))
#define DU(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))
#define lc(i) i+1
#define rc(i) i+(m-l+1)*2

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll expo(ll a, ll b, ll mod) {
	if(b == 0) return 1;
	if(b == 1) return a % mod;
	ll ret = expo(a, b>>1, mod);
	ret *= ret;
	if(ret >= mod) ret %= mod;
	if(b & 1) {
		ret *= a;
		if(ret >= mod) ret %= mod;
	}
	return ret;
}

ll inv(ll v, ll mod) {
	return expo(v, mod - 2, mod);
}

struct Node {
	ll t, l, r, v, i;
	Node(ll _t, ll _l, ll _r, ll _v, ll _i) {
		t = _t;
		l = _l;
		r = _r;
		v = _v;
		i = _i;
	}

	void prll() {
		cout << t << " " << l << " " << r << " " << v <<" " << i << endl;
	}
};

ll n, m, a[100005];
set<ll, greater<ll>> dsc[100005];
set<ll> asc[100005];
ll fen[100005];
vector<Node> vec, tmp;
vector<ll> ans;

void upd(ll i, ll x) {
	while(i <= n) {
		fen[i] += x;
		i += (i & (-i));
	}
}

ll get(ll i) {
	ll sum = 0;
	while(i) {
		sum += fen[i];
		i -= (i & (-i));
	}
	return sum;
}

void reset() {
}

void input() {
	cin >> n >> m;
	UU(i, 1, n) {
		cin >> a[i];
		auto l = dsc[a[i]].lower_bound(i);
		if(l != dsc[a[i]].end()) vec.pb(Node(0, *l, i, i - (*l), -1));

		asc[a[i]].insert(i);
		dsc[a[i]].insert(i);
	}

	ll t, x, y;
	UU(i, 1, m) {
		cin >> t >> x >> y;
		if(t == 1) {
			if(a[x] == y) continue;

			auto l = dsc[a[x]].upper_bound(x);
			auto r = asc[a[x]].upper_bound(x);
	
			if(l != dsc[a[x]].end()) vec.pb(Node(i, *l, x, -(x - (*l)), -1));
			if(r != asc[a[x]].end()) vec.pb(Node(i, x, *r, -((*r) - x), -1));
			if(l != dsc[a[x]].end() && r != asc[a[x]].end()) vec.pb(Node(i, *l, *r, (*r) - (*l), -1));
	
			dsc[a[x]].erase(dsc[a[x]].find(x));				
			asc[a[x]].erase(asc[a[x]].find(x));				

			a[x] = y;
			l = dsc[a[x]].upper_bound(x);
			r = asc[a[x]].upper_bound(x);
			
			if(l != dsc[a[x]].end()) vec.pb(Node(i, *l, x, x - (*l), -1));
			if(r != asc[a[x]].end()) vec.pb(Node(i, x, *r, (*r) - x, -1));
			// cout << *l << " " << x << " " << *r << " " << (l == dsc[a[x]].end()) << " " << (r == asc[a[x]].end()) << endl;
			if(l != dsc[a[x]].end() && r != asc[a[x]].end()) vec.pb(Node(i, *l, *r, -((*r) - (*l)), -1));

			asc[a[x]].insert(x);
			dsc[a[x]].insert(x);
		}
		else {
			vec.pb(Node(i, x, y, 0, ans.size()));
			ans.pb(0);
		}
	}
}

void debug(ll l, ll r) {
	UU(i, l, r) vec[i].prll();
	cout << endl;
}

void solve(ll l, ll r) {
	if(l == r) return ;
	ll m = l + r >> 1;
	solve(l, m);
	solve(m + 1, r);

	vector<pii> memo;

	ll i = l, j = m + 1, k = l;
	while(i <= m || j <= r) {
		if(j > r || (i <= m && tmp[i].l >= tmp[j].l)) {
			if(!~tmp[i].i) {
				memo.pb({tmp[i].r, tmp[i].v});
				upd(tmp[i].r, tmp[i].v);
			}
			vec[k++] = tmp[i++];
		}
		else {
			if(~tmp[j].i) {
				// cout << tmp[j].i << " " << get(tmp[j].r) << endl;
				ans[tmp[j].i] += get(tmp[j].r);
			}
			vec[k++] = tmp[j++];
		}
	}

	UU(i, l, r) tmp[i] = vec[i];

	// debug(l, r);
	for(pii &p : memo) upd(p.fi, -p.se);

	memo.clear();
}

bool cmp(Node &a, Node &b) {
	return a.t < b.t;
}

void Ahoy() {
	// UP(i, 0, vec.size()) if(vec[i].v < 0) cout << vec[i].t << " " << vec[i].l << " " << vec[i].r << " " << vec[i].v << endl;

	sort(vec.begin(), vec.end(), cmp);
	tmp = vec;

	solve(0, vec.size() - 1);

	UP(i, 0, ans.size())
		cout << ans[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll TC = 1;
	UU(t, 1, TC) {
		input();
		Ahoy();
		reset();
	}

	return 0;
}