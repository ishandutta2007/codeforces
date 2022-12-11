#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int pc(ll val) {
    return __builtin_popcount(val >> 16) + __builtin_popcount(val & ((1 << 16) - 1));
}

bool bit(ll mask, int pos) {
    return (mask >> pos) & 1;
}

vector<ll> a;
vector<int> cnt;
ll ans = 0;
int n;

void rec(int pos, int eq, ll val) {
    if (pos == n) {
        for (int i = 0; i < sz(a); ++i) {
            if (n - pc(val ^ a[i]) != cnt[i]) {
                return;
            }
        }
        ++ans;
        return;
    }
    if (bit(a[0], pos)) {
        rec(pos + 1, eq, val);
        if (eq + 1 <= cnt[0]) {
            rec(pos + 1, eq + 1, val + (1LL << pos));
        }
    } else {
        rec(pos + 1, eq, val + (1LL << pos));
        if (eq + 1 <= cnt[0]) {
            rec(pos + 1, eq + 1, val);
        }
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        ll val = 0;
        ll deg = 1;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                val += deg;
            } 
            deg *= 2;
        }
        a.pb(val);
        cin >> val;
        cnt.pb(val);
    }

    rec(0, 0, 0);
    cout << ans << endl;

}