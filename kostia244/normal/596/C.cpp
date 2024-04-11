#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int MAXN = (1 << 20);

struct node
{
    int mx;
    node() { mx = -1e9; }
    node(int val) { mx = val; }
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
    node t[2 * MAXN];

    void init(int sz)
    {
        n = sz;
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
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    map<int, vector<array<int, 2>>> pts;
    cin >> n;
    for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		pts[y-x].push_back({(1<<17)+x, (1<<17)+y});
	}
	for(auto &i : pts) sort(all(i.second), greater<>());
	vector<array<int, 3>> vals;
	for(int x, i = 0; i < n; i++) {
		cin >> x;
		if(pts[x].empty()) return cout << "NO\n", 0;
		vals.push_back({pts[x].back()[0], pts[x].back()[1], i});
		pts[x].pop_back();
	}
	auto ffff =vals;
	sort(all(vals), greater<>());
	segment_tree f;f.init(1<<18);
	for(auto [x, y, id] : vals) {
		auto t = -f.query(y, 1<<18).mx;
		if(t < id) return cout << "NO\n", 0;
		f.modify(y, node(-id));
	}
	cout << "YES\n";
	for(auto &i : ffff) cout << i[0]-(1<<17) << " " << i[1]-(1<<17) << '\n';
}