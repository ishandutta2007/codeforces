#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 500000;
vector<pair<int, int>> v[maxn + 2];
int s[maxn + 2];
LL S[maxn + 2], p[maxn + 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < m; i += 1){
        int l, r, x;
        cin >> l >> r >> x;
        v[r].push_back({l, x});
    }
    for(int i = 0; i <= n; i += 1) p[i] = i ? p[i - 1] * 2 % mod : 1;
    LL ans = 1;
    for(k -= 1; ~k; k -= 1){
        for(int r = 1; r <= n; r += 1) s[r] = S[r] = 0;
        for(int r = 1; r <= n; r += 1)
            for(auto [l, x] : v[r]) if(x >> k & 1){
                s[l] += 1;
                s[r + 1] -= 1;
            }
        for(int r = 1; r <= n + 1; r += 1) s[r] += s[r - 1];
        int ml = 0, m = 0;
        for(int r = 1; r <= n + 1; r += 1){
            if(not s[r]){
                if(ml == 0) S[r] = p[m];
                else S[r] = (S[r - 1] - S[ml - 1] + mod) % mod;
                m += 1;
            }
            for(auto [l, x] : v[r]) if(not(x >> k & 1)) ml = max(ml, l);
            if(r > n) ans = ans * S[r] % mod;
            S[r] = (S[r] + S[r - 1]) % mod;
        }
    }
    cout << ans;
    return 0;
}