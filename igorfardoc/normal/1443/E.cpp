#include<bits/stdc++.h>
#define mx 14
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll fact[mx + 1];

void precalc() {
    fact[0] = 1;
    for(int i = 1; i <= mx; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

vi get_per(ll k) {
    set<int> now;
    for(int i = 0; i < mx; i++) {
        now.insert(i + 1);
    }
    vi ans(mx);
    for(int i = 0; i < mx; i++) {
        for(auto it = now.begin(); it != now.end(); ++it) {
            if(fact[now.size() - 1] <= k) {
                k -= fact[now.size() - 1];
            } else {
                ans[i] = *it;
                now.erase(it);
                break;
            }
        }
    }
    return ans;
}

ll get_sum(int l, int r) {
    if(l > r) return 0;
    ll res = (ll)r * (r + 1) / 2;
    res -= (ll)l * (l - 1) / 2;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    precalc();
    int n, q;
    cin >> n >> q;
    ll k = 0;
    for(int o = 0; o < q; o++) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int l1 = l;
            int r1 = min(r, n - mx - 1);
            ll ans = get_sum(l1 + 1, r1 + 1);
            auto a = get_per(k);
            int r2 = mx - (n - r);
            int l2 = max(mx - (n - l), 0);
            for(int i = l2; i <= r2; i++) {
                ans += a[i] + (n - mx);
            }
            cout << ans << '\n';
        } else {
            int val;
            cin >> val;
            k += val;
        }
    } 

}