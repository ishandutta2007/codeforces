#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<20, mod = 1000000007;
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
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
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	if(count(all(s), '1') == 0) return cout << s.size() << '\n', 0;
	int _cntl = 1, _cntr = 1;
	while(s.size() && s.back() == '0') _cntl++, s.pop_back();
	reverse(all(s));
	while(s.size() && s.back() == '0') _cntr++, s.pop_back();
	int _cnt = _cntl * 1ll * _cntr % mod;
	s.pop_back();
	reverse(all(s));
	//cout << s << " " << _cnt << endl;
	vector<int> segs {-1}, dp {1}, pref {1};
	int cur = 0;
	for(auto &i : s) {
		if(i == '0') cur++;
		else segs.push_back(cur), cur = 0;
	}
	segment_tree ll;
	ll.init(s.size()+1);
	for(int i = 1; i < segs.size(); i++) {
		int res = 0, len = segs[i];
		for(int j = 0; j <= len; j++) {
			int k = ll.query(j, s.size()+1).mx;
			add(res, pref.back());
			if(--k >= 0)
				add(res, mod-pref[k]);
		}
		ll.modify(len, node(i));
		pref.push_back(pref.back());
		add(pref.back(), res);
		dp.push_back(res);
	}
	//for(auto i : dp) cout << i << " "; cout << endl;
	//multiply answer my _cnt
	cout << pref.back() * 1ll * _cnt % mod << '\n';
}