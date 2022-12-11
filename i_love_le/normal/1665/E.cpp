#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 100;

struct Node {
    Node *to[2];
    vi have;

    Node() : have() {
        to[0] = nullptr;
        to[1] = nullptr;
    }
};

void add(Node *&v, int x, int i, int h) {
    if (!v) v = new Node();
    v->have.push_back(i);
    if (h == -1) return;
    add(v->to[(x >> h) & 1], x, i, h - 1);
}

int A[maxN];

int get(int l, int r, Node *v) {
    int ans = 0;
    vi have;
    for (int h = 29; h >= 0; --h) {
        int cntL = 0;
        for (auto &x : have) {
            if ((1 << h) & x) continue;
            cntL++;
        }
        int L = 0;
        int R = 0;
        if (v && v->to[0]) {
            L = lower_bound(all(v->to[0]->have), l) - (v->to[0]->have.begin());
            R = lower_bound(all(v->to[0]->have), r) - (v->to[0]->have.begin());
        }
        cntL += R - L;

        if (cntL >= 2) {
            if (v) v = v->to[0];
            int j = 0;
            rep(i, (int) have.size()) {
                if ((1 << h) & have[i]) continue;
                swap(have[j], have[i]);
                j++;
            }
            have.resize(j);
            continue;
        }
        ans |= (1 << h);
        if (L != R) {
            have.push_back(A[v->to[0]->have[L]]);
        }
        if (v) v = v->to[1];
    }
    return ans;
}

void solve() {
    Node *root = nullptr;
    int n;
    cin >> n;
    rep(i, n) {
        int x;
        cin >> x;
        A[i] = x;
        add(root, x, i, 29);
    }
    int q;
    cin >> q;
    rep(_, q) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << get(l, r, root) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}