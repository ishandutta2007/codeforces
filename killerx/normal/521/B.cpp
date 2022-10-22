#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
    return f ? x : -x;
}
typedef pair <int, int> P;
#define MP make_pair
pair <P, int> v[100005];
set <int> g[100005], rg[100005];
set <int> pq;
int mod = 1000000009;
int main() {
    int n = read();
    for (int i = 0; i < n; ++ i) {
        int x = read(), y = read();
        v[i] = MP(MP(x, y), i);
    }
    sort(v, v + n);
    for (int i = 0; i < n; ++ i) {
        P p = v[i].first;
        int ii = v[i].second;
        for (int dx = -1; dx <= 1; ++ dx) {
            P np = MP(p.first + dx, p.second - 1);
            int ps = lower_bound(v, v + n, MP(np, 0)) - v;
            if (v[ps].first != np) continue;
            int pss = v[ps].second;
            g[ii].insert(pss);
            rg[pss].insert(ii);
        }
    }
    for (int i = 0; i < n; ++ i) {
        bool ok = 1;
        for (int j : rg[i]) {
            if (g[j].size() <= 1) ok = 0;
        }
        if (ok) pq.insert(i);
    }
    int ans = 0;
    for (int stp = 0; stp < n; ++ stp) {
        int i = !(stp & 1) ? *pq.rbegin() : *pq.begin();
        // cerr << i << endl;
        pq.erase(i);
        ans = (1LL * ans * n + i) % mod; 
        for (int j : g[i]) {
            rg[j].erase(i);
            bool ok = 1;
            for (int k : rg[j]) {
                if (g[k].size() <= 1) ok = 0;
            }
            if (ok) pq.insert(j);
        }
        for (int j : rg[i]) {
            g[j].erase(i);
            for (int k : g[j]) {
                if (g[j].size() <= 1) pq.erase(k);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}