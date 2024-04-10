#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int answer = 0;
    vi have(2e6 + 5, -1);
    repr(_, 22) {
        for(int l = 0, r = 0; l < n; l = r) {
            r = l + 1;
            if (!Bit(a[l], 0)) continue;
            while(r < n && Bit(a[r], 0)) r++;
            {
                int px = 0;
                have[px] = l;
                for(int j = l + 2; j <= r; j += 2) {
                    px ^= a[j - 1] ^ a[j - 2];
                    if (have[px] != -1) {
                        ckmax(answer, j - have[px]);
                    } else {
                        have[px] = j;
                    }
                }
                px = 0;
                have[px] = -1;
                for(int j = l + 2; j <= r; j += 2) {
                    px ^= a[j - 1] ^ a[j - 2];
                    have[px] = -1;
                }
            }
            {
                int px = 0;
                have[px] = l + 1;
                for(int j = l + 3; j <= r; j += 2) {
                    px ^= a[j - 1] ^ a[j - 2];
                    if (have[px] != -1) {
                        ckmax(answer, j - have[px]);
                    } else {
                        have[px] = j;
                    }
                }
                px = 0;
                have[px] = -1;
                for(int j = l + 3; j <= r; j += 2) {
                    px ^= a[j - 1] ^ a[j - 2];
                    have[px] = -1;
                }
            }
        }
        rep(i, n) a[i] >>= 1;
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(20-7) << fixed;
    int t = 1;
//     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}