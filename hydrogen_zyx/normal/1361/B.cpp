#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
struct node {
    ll type;
    pair<ll, ll> pa;
};
vector<ll> v;
vector<node> ans;

bool cmp(ll a, ll b) { return a > b; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        v.clear();
        ans.clear();
        ll n, p;
        cin >> n >> p;
        for (int i = 1; i <= n; i++) {
            ll a;
            cin >> a;
            v.push_back(a);
        }
        if (p == 1) {
            if (n & 1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
            continue;
        }
        sort(v.begin(), v.end(), cmp);
        for (auto x : v) {
            if (ans.empty())
                ans.push_back({0, pair<ll, ll>(x, 1)});
            else if (ans.rbegin()->type == 0) {
                ll s = ans.rbegin()->pa.first;
                ans.rbegin()->pa.second--;
                if (ans.rbegin()->pa.second == 0) ans.pop_back();
                if (s != x) ans.push_back({1, pair<ll, ll>(s - 1, x)});

            } else {
                pair<ll, ll> s = ans.rbegin()->pa;
                ans.pop_back();
                if (s.first != s.second)
                    ans.push_back({1, pair<ll, ll>(s.first, s.second + 1)});
                if (p != 2) ans.push_back({0, pair<ll, ll>(s.second, p - 2)});
                if (s.second != x)
                    ans.push_back({1, pair<ll, ll>(s.second - 1, x)});
            }
        }
        ll sum = 0;
        for (auto x : ans) {
            if (x.type) {
                sum = (sum + qpow(p, x.pa.first + 1)) % mod;
                sum = (sum + mod - qpow(p, x.pa.second)) % mod;
            } else {
                sum = (sum + qpow(p, x.pa.first) * x.pa.second) % mod;
            }
        }
        cout << sum << endl;
    }
}