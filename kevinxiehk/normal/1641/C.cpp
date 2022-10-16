#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;

struct node{
    int next, prev;
    int status = 0; // 0 = unknown, -1 = not, 1 = yes;
};
set<int> dsu[200005];
int fa[200005];
int beg[200005];
int en[200005];
node arr[200005];
int f(int x) {
    if(fa[x] == x) return x;
    return fa[x] = f(fa[x]);
}
void merge(int a, int b) {
    a = f(a);
    b = f(b);
    if(a == b) return;
    if(dsu[a].size() > dsu[b].size()) swap(a, b);
    for(auto it = dsu[a].begin(); it != dsu[a].end(); it++) {
        dsu[b].insert(*it);
    }
    dsu[a].clear();
    fa[a] = b;
    beg[b] = min(beg[a], beg[b]);
    en[b] = max(en[a], en[b]);
}
void solve(int TC) {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        fa[i] = beg[i] = en[i] = i;
    }
    int t;
    while(q--) {
        cin >> t;
        if(t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if(x == 1) {
                dsu[f(l)].insert(r);
            }
            else {
                int pt = beg[f(r)];
                while(pt > l) {
                    merge(pt, pt - 1);
                    pt = beg[f(r)];
                }
                // if(arr[f(pt - 1)].status == -1) merge(pt, pt - 1);
                arr[f(l)].status = -1;
            }
        }
        else {
            int j;
            cin >> j;
            if(arr[f(j)].status == -1) {
                cout << "NO\n";
            }
            else {
                string ans = "N/A\n";
                int upper = j;
                if(arr[f(j + 1)].status == -1) {
                    int jj = en[f(j + 1)];
                    while(arr[f(jj + 1)].status == -1) {
                        merge(jj, jj + 1);
                        jj = en[f(j + 1)];
                    }
                    upper = en[f(j + 1)];
                }
                if(arr[f(j - 1)].status == -1) {
                    int jj = beg[f(j - 1)];
                    while(arr[f(jj - 1)].status == -1) {
                        merge(jj, jj - 1);
                        jj = beg[f(j - 1)];
                    }
                    auto it = dsu[f(j - 1)].lower_bound(j);
                    if(it != dsu[f(j - 1)].end() && *it <= upper) {
                        ans = "YES\n";
                    }
                }
                auto it = dsu[f(j)].lower_bound(j);
                if(it != dsu[f(j)].end() && *it <= upper) {
                    ans = "YES\n";
                }
                cout << ans;
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}