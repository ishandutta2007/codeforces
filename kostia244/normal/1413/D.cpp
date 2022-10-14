#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 998244353, inv2 = (mod+1)/2;
const int MAXN = (1 << 18);

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

node t[2 * MAXN];
struct segment_tree
{
    int n;

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
segment_tree st;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	st.init(n+10);
	char c;
	int x;
	vector<array<int, 2>> ans;
	set<int> have;
	for(int i = 0; i < 2*n; i++) {
		cin >> c;
		if(c == '+') have.insert(i);
		else {
			cin >> x;
			auto it = have.upper_bound(st.query(x, n+10).mx);
			if(it == have.end()) {
				cout << "NO\n";
				return 0;
			}
			ans.push_back({*it, x});
			st.modify(x, node(i));
			have.erase(it);
		}
	}
	cout << "YES\n";
	sort(all(ans));
	for(auto [x, y] : ans) cout << y << " "; cout << '\n';
}