#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18;
struct node
{
    int mx;
    node() { mx = -1e9; }
    node(int val) { mx = val; }
};

node temp;

node merge(node l, node r)
{
    temp.mx = min(l.mx, r.mx);
    return temp;
}

struct segment_tree
{
    int n;
    node t[2 * maxn];

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
        node resl(1<<30), resr(1<<30);
        for(l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if(l & 1) resl = merge(resl, t[l++]);
            if(r & 1) resr = merge(t[--r], resr);
        }

        return merge(resl, resr);
    }
};
vector<int> solve(int n, int m, vector<array<int, 2>> co, vector<array<int, 4>> qs) {
	vector<int> ans(qs.size());
	vector<vector<array<int, 4>>> qr(n+1);
	vector<vector<int>> here(n+1);
	for(auto [x, y] : co) here[x].push_back(y);
	for(int i = 0; i < qs.size(); i++) {
		qr[qs[i][2]].push_back({i, qs[i][1], qs[i][3], qs[i][0]});
	}
	segment_tree st;
	st.init(m+1);
	for(int i = 1; i <= n; i++) {
		for(auto j : here[i]) {
			st.modify(j, node(i));
		}
		for(auto [id, yl, yr, xl] : qr[i]) {
			ans[id] = st.query(yl, yr+1).mx >= xl;
		}
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<array<int, 2>> co(k);
	vector<array<int, 4>> qs(q);
	for(auto &i : co) cin >> i[0] >> i[1];
	for(auto &i : qs) cin >> i[0] >> i[1] >> i[2] >> i[3];
	auto ans1 = solve(n, m, co, qs);
	for(auto &i : co) swap(i[0], i[1]);
	for(auto &i : qs) swap(i[0], i[1]);
	for(auto &i : qs) swap(i[2], i[3]);
	auto ans2 = solve(m, n, co, qs);
	for(int i = 0; i < q; i++) cout << (ans1[i]||ans2[i]?"YES":"NO") << '\n';
}