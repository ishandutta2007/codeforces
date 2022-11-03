#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 10100100;
int lp[N];
int mp[N];
vector<int> primes;
vector<ll> deg;

void init() {
    lp[0] = 0;
    lp[1] = 1;
    fill(lp + 2, lp + N, -1);
    for (int i = 2; i < N; ++i) {
        if (lp[i] == -1) {
            mp[i] = primes.size();
            primes.push_back(i);
            lp[i] = i;
            for (ll j = (i * (ll)i); j < N; j += i) {
                if (lp[j] == -1) {
                    lp[j] = i;
                }
            }
        }
    }
    deg.resize(primes.size(), 0);
}

ll get(int p, ll d, ll already) {
    auto check = [p, d](ll x) -> bool {
        ll ans = 0;
        ll cur = x / p;
        while (cur) {
            ans += cur;
            cur /= p;
        }
        return ans >= d;
    };
    ll L = already - 1;
    ll R = 1e18;
    if (check(L + 1))
        return L + 1;
    while (R - L > 1) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    return R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
//    n = 1000000;
    init();
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
//        x = 10000000;
        if (x >= a.size()) {
            a.resize(x + 1, 0);
        }
        ++a[x];
    }
    while (a.size() > 2) {
        int o = a.back();
        int what = (int)a.size() - 1;
        a.pop_back();
        a.back() += o;
        while (what > 1) {
            deg[mp[lp[what]]] += o;
            what /= lp[what];
        }
    }
    ll ans = 1;
    vector<int> v;
    for (int i = 0; i < primes.size(); ++i) {
        v.push_back(i);
    }
    mt19937 mt(time(nullptr));
    shuffle(v.begin(), v.end(), mt);
    for (int i: v) {
        if (deg[i] > 0) {
            ans = get(primes[i], deg[i], ans);
        }
    }
    cout << ans << endl;
}