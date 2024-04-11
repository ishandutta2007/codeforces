#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
int n, s, l, a[maxn], dp[maxn], to[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int mn = 1e9, mx = -1e9;
	cin >> n >> s >> l;
	int ans = 0;
	int j = 1;
	multiset<int> F;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		F.insert(a[i]);
		while(*F.rbegin()-*F.begin() > s) {
			F.erase(F.find(a[j]));
			j++;
		}
		to[i] = j-1;
	}
	segment_tree st;
	st.modify(0, 0);
	for(int j = 1,i = 1; i <= n; i++) {
		dp[i] = 1-st.query(to[i], i-l+1).mx;
		st.modify(i, -dp[i]);
	}
	if(dp[n] > n) dp[n] = -1;
	cout << dp[n] << '\n';
}