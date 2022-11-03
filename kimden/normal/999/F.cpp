#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
/*
const int DEG = 13;
const int MAXN = 1 << DEG;
const int MOD = 998244353;
const int ROOT = 64341522;*/


int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, k, a;
    cin >> n >> k;
    vector<int> c(100005, 0);
    vector<int> p(100005, 0);
    for(int i = 0; i < n * k; ++i){
        cin >> a;
        ++c[a];
    }
    for(int i = 0; i < n; ++i){
        cin >> a;
        ++p[a];
    }
    vector<pii> v;
    int mx = 0;
    for(int i = 0; i < 100005; ++i){
        if(p[i]){
            v.push_back({p[i], c[i]});
            mx = max(mx, p[i]);
        }
    }
    sort(all(v));
    const int MAXN = 6000;
    vector<int> h(MAXN, 0);
    for(int i = 1; i <= k; ++i){
        cin >> h[i];
    }
    const ll INF = 1000000000000000000;
    vector<ll> z(MAXN, -INF);
    z[0] = 0;
    ll ans = 0;
    int ptr = 0;
    for(int i = 1; i <= mx; ++i){
        vector<ll> z1(MAXN, -INF);
        for(int j = 0; j < MAXN; ++j){
            for(int u = 0; u <= k && u <= j; ++u){
                if(z[j - u] == -INF){
                    continue;
                }
                z1[j] = max(z1[j], z[j - u] + h[u]);
            }
        }
        z = z1;
        while(ptr != v.size() && v[ptr].first == i){
            ans += z[min(v[ptr].first * k, v[ptr].second)];
            ++ptr;
        }
    }
    cout << ans << endl;




}