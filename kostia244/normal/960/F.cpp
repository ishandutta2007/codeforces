#include<bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;
const int maxn = 1<<17;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node
{
    ll mx;
    node() { mx = 0; }
    node(ll val) { mx = val; }
};

node temp;

node merge(node l, node r)
{
    temp.mx = max(l.mx, r.mx);
    return temp;
}

struct segment_tree
{
    int n;
    vector<node> t;

    void init(int sz)
    {
        n = sz;
        t.resize(2*sz);
        for(int i = 0; i < n; i++) t[i + n] = node();
        for(int i = n - 1; i > 0; --i)
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int p, const node& value)
    {
        for(t[p += n] = value; p >>= 1; )
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }

    node query(int l, int r)
    {
        node resl, resr;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if(l & 1) resl = merge(resl, t[l++]);
            if(r & 1) resr = merge(t[--r], resr);
        }

        return merge(resl, resr);
    }
};

int n, m;
vector<int> vals[maxn];
segment_tree st[maxn];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<array<ll, 3>> edges(m);
	for(auto &[x,y,z] : edges) {
		cin >> x>> y >>z;
		vals[y].push_back(z);
	}
	for(int i = 1; i <= n; i++) {
		sort(all(vals[i]));
		st[i].init(vals[i].size());
	}
	ll ans = 0;
	for(auto [f, t, w] : edges) {
		ll cur = st[f].query(0, lower_bound(all(vals[f]), w)-vals[f].begin()).mx + 1;
		ll p = lower_bound(all(vals[t]), w)-vals[t].begin();
		st[t].modify(p, node(max(st[t].query(p, p).mx, cur)));
		ans = max(ans, cur);
		//cout << f << " " << t << " " << w << " " << cur << endl;
	}
	cout << ans << '\n';
}