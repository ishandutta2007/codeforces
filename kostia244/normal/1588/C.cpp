// Problem: C. Game with Stones
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1588/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
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
	vector<node> t;

    segment_tree(int sz)
    {
        n = sz;
        t = vector<node>(2*n);
        for(int i = n - 1; i > 0; --i)
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int p, int val)
    {
        for(t[p += n] = node(val); p >>= 1; )
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
	multitest([&](){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		for(int i = 1; i < n; i+=2) 
			a[i] *= -1;
		for(int i = 1; i < n; i++)
			a[i] += a[i-1];
		auto b = a;b.push_back(0);
		for(auto i : a) b.push_back(-i);
		sort(all(b));
		segment_tree odd(b.size()), even(b.size());
		vector<vector<int>> occ(b.size());
		auto count = [&](int x, int R) {
			int p = -1, S = int(occ[x].size())-1;
			for(int z = 1<<20; z>>=1;)
				if(p+z<occ[x].size() && occ[x][S-(p+z)]<R)
					p += z;
			return p+1;
		};
		ll ans = 0;
		// for(auto i : a) cout << i << " "; cout << endl;
		for(int i = n; i--;) {
			ll sub = i?a[i-1]:0;
			int sid = lower_bound(all(b), sub)-b.begin();
			int msid = lower_bound(all(b), -sub)-b.begin();
			int rid = lower_bound(all(b), a[i])-b.begin();
			int mrid = lower_bound(all(b), -a[i])-b.begin();
			int B;
			if(i%2 == 0) {
				B = min(-even.query(0, sid).mx,
					-odd.query(0, msid).mx);
			} else {
				B = min(-odd.query(0, msid).mx,
					-even.query(0, sid).mx);
			}
			occ[rid].push_back(i);
			ans += count(sid, B);
			if(i%2 == 0) {
				even.modify(rid, -i);
			} else {
				odd.modify(mrid, -i);
			}
			// cout << i << " " << B << " " << ans << " | " << sid << " " << b[sid] << endl;
		}
		cout << ans << '\n';
	});
	
}