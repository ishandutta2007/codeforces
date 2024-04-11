#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int MAXN = 1<<20, maxn = 1<<20, mod = 1e9 + 7;
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
ll n, t, a[maxn], x[maxn], b[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> t;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= n; i++) {
		b[i]++;
		b[x[i]]--;
		if(x[i] < i) return cout << "No\n", 0;
	}
	for(int i = 1; i <= n; i++) b[i] += b[i-1];
	segment_tree f; f.init(n+3);
	b[0] = -(1ll<<60);
	for(int i = 1; i <= n; i++) {
		b[i] = t + a[i + (b[i]>0)];
		b[i] = max(b[i], b[i-1]+1);
		f.modify(i, node((a[i]+t) > b[i-1]));
	}
	//for(int i = 1; i <= n; i++) cout << f.query(i, i+1).mx << " "; cout << endl;
	for(int i = 1; i <= n; i++) {
		if(x[i] == n) continue;
		//cout << i << " " << i+1 << " " << x[i]+2 << " " << f.query(2, 3).mx << endl;
		if(a[i]+t <= b[x[i]+1] && f.query(i+1, x[i]+2).mx == 0) return cout << "No\n", 0;
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) cout << b[i] << " "; cout << endl;
}