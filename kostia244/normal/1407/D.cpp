#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    node t[1<<21];

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
segment_tree Mn, Mx;
int n, a[maxn], dp[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<int> b;
	for(int i = 1; i <= n; i++) cin >> a[i], b.push_back(a[i]);
	sort(all(b));
	for(int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin();
	//for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << '\n';
	vector<int> mn {}, mx {};
	memset(dp, 0x4f, sizeof dp); dp[0] = -1;
	Mn.init(n+3);
	Mx.init(n+3);
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1] + 1;
		dp[i] = min(dp[i], 1-Mx.query(0, a[i]).mx);
		dp[i] = min(dp[i], 1-Mn.query(a[i]+1, n+3).mx);
		//cout << i << " - " << dp[i] << '\n';
		//for(auto i : mn) cout << i << " "; cout << '\n';
		//for(auto i : mx) cout << i << " "; cout << '\n';
		while(!mn.empty() && a[mn.back()] >= a[i]) {
			int t = mn.back();mn.pop_back();
			if(!mn.empty()) Mn.modify(a[t], node());
		}
		if(!mn.empty()) Mn.modify(a[i], node(-dp[mn.back()]));//, cout << "add " << i << " " << a[i] << " " << -dp[mn.back()] << '\n';
		mn.push_back(i);
		while(!mx.empty() && a[mx.back()] <= a[i]) {
			int t = mx.back();mx.pop_back();
			if(!mx.empty()) Mx.modify(a[t], node());
		}
		if(!mx.empty()) Mx.modify(a[i], node(-dp[mx.back()]));//, cout << "addx " << i << " " << a[i] << " " << -dp[mx.back()] << '\n';
		mx.push_back(i);
	}
	cout << dp[n] << '\n';
}