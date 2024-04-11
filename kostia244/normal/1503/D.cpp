// Problem: D. Flip the Cards
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1<<30;
const array<int, 2> def = {-inf, 0};
struct SegTree {
    int n;
    vector<array<int, 2>> tree;
    SegTree(int n) : n(n), tree(2*n, def) {}
    void upd(int p, int x) {
        array<int, 2> y = {x, p};
        for(tree[p+=n]=y;p/=2;)
            tree[p] = max(tree[2*p], tree[2*p+1]);
    }
    array<int, 2> query(int l, int r) {
        array<int, 2> res = def;
        for(l+=n,r+=n; l < r; l>>=1,r>>=1) {
            if(l&1) res = max(res, tree[l++]);
            if(r&1) res = max(res, tree[--r]);
        }
        return res;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, comp = 0;
    cin >> n;
    vector<int> vis(n), Pcol(2*n), type(n);
    vector<array<int, 2>> ranges(n);
    SegTree stR(2*n);
    SegTree stL(2*n);
    int aaaaa = 0;
    int minR = inf, maxL = -inf;
    for(auto &[l, r] : ranges) {
        cin >> l >> r;l--,r--;
        type[aaaaa] = l<r;
        if(l > r) swap(l, r);
        Pcol[r] = aaaaa;
        Pcol[l] = aaaaa++;
        stR.upd(r, -l);
        stL.upd(l, r);
		maxL = max(maxL, l);
		minR = min(minR, r);
    }
    if(minR <= maxL) {
    	return cout << "-1\n", 0;
    }
    queue<int> q;
    auto add = [&](int v, int col) {
        if(vis[v]) {return;}
        vis[v] = col;
        q.push(v);
        stL.upd(ranges[v][0], -1);
        stR.upd(ranges[v][1], -inf);
    };
    int ans = 0;
    for(int i = 0; i < n; i++) if(!vis[i]) {
        add(i, 1);
        comp++;
        array<array<int, 2>, 2> fuck;
        fuck[0].fill(0);
        fuck[1].fill(0);
        while(!q.empty()) {
            int id = q.front();
            fuck[vis[id]-1][type[id]]++;
            //cout << id << endl;
            q.pop();
            int L = ranges[id][0], R = ranges[id][1];
            for(array<int, 2> x; (x=stL.query(L, R))[0]>R;) {
                add(Pcol[x[1]], vis[id]^3);
            }
            for(array<int, 2> x; -(x=stR.query(L, R))[0]<L;) {
                add(Pcol[x[1]], vis[id]^3);
            }
        }
        ans += min(fuck[0][0]+fuck[1][1], fuck[0][1]+fuck[1][0]);
    }
    vector<int> events(2*n, -1);
    vector<SegTree> mark(2, SegTree(2*n));
    for(int i = 0; i < n; i++) {
        events[ranges[i][1]] = i;
    }
    int ok = 1;
    for(int x = 2*n; x--;) {
        int i = events[x];
        if(i == -1) continue;
        //cout << vis[i] << endl;
        ok &= mark[vis[i]-1].query(ranges[i][0], ranges[i][1])[0] < 1;
        mark[vis[i]-1].upd(ranges[i][0], 1);
    }
	if(!ok) ans = -1;
	cout << ans << '\n';
}