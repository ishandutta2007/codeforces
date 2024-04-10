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

const int mxN = 2e5;
const ll INF = 1e18;
const int md = 1e9 + 7;

void solve() {
    auto move = [&](int x, int y) {
        cout << x << ' ' << y << endl;
        string res;
        cin >> res;
        if (res == "Done") return -1;
        if (res[0] == 'D') return 1;
        if (res[0] == 'U') return 2;
        return 0;
    };
    int cur = 1;
    if (move(1, 1) == -1) return;
    for (int i = 1; i <= 8; ++i) {
        while (true) {
            int state = -1;
            for (int j = 1; j <= 8; ++j) {
                if (cur == j) continue;
                int t = move(i, j);
                if (t == -1) return;
                cur = j;
                if (t == 1) {
                    state = 1;
                    break;
                }
                if (t == 0) continue;
                if (t != 2) {
                    exit(2);
                }
                if (cur == 1) continue;
                int t2 = move(i, 1);
                cur = 1;
                if (t2 == -1) return;
                if (t2 == 1) {
                    state = 1;
                    break;
                }
                state = 2;
                break;
            }
            if (state == 2) {
                continue;
            }
            if (move(i + 1, cur) == -1) return;
            break;
        }
    }
    assert(0);
}

int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}