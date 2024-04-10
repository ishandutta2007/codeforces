#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct FUNC {
    ll a, b;
    FUNC(): a(-1e18), b(0) {}
    FUNC(ll a, ll b): a(a), b(b) {}
    ll get(int x) { return a + b * x; }
};

struct LCSEG {
    static const int mxn = 2e5 + 7;
    struct Node {
        FUNC f;
        Node *ls, *rs;
    };
    void ins(FUNC f0, Node *&i, int a = -mxn, int b = mxn) {
        if (!i) {
            i = new Node();
        }
        if (a + 1 == b) {
            if (f0.get(a) > i->f.get(a)) i->f = f0;
            return ;
        }
        int m = a + ((b - a) >> 1);
        bool lef = f0.get(a) > i->f.get(a);
        bool mid = f0.get(m) > i->f.get(m);
        if (mid) {
            swap(i->f, f0);
        }
        if (lef != mid) {
            ins(f0, i->ls, a, m);
        } else {
            ins(f0, i->rs, m, b);
        }
    }
    ll get(int x, Node *i, int a = -mxn, int b = mxn) {
        if (!i) {
            return -1e18;
        }
        if (a + 1 == b) {
            return i->f.get(x);
        }
        int m = a + ((b - a) >> 1);
        ll ans = i->f.get(x);
        if (x < m) {
            ans = max(ans, get(x, i->ls, a, m));
        } else {
            ans = max(ans, get(x, i->rs, m, b));
        }
        return ans;
    }
} lcseg;

const int mxn = 2e5 + 5;
int n;
int a[mxn];
ll ans;

void solve(int l, int r) {
    if (l + 1 == r) {
        ans = max(ans, 0LL + a[l]);
        return ;
    }
    int m = (l + r) >> 1;
    solve(l, m);
    solve(m, r);
    LCSEG::Node *rt = nullptr;
    {
        ll tot = 0, sum = 0;
        for (int i = m; i < r; ++ i) {
            sum += a[i];
            tot += 1LL * (i - m + 1) * a[i];
            lcseg.ins(FUNC(tot, sum), rt);
        }
    }
    {
        ll tot = 0, sum = 0;
        for (int i = m - 1; i >= l; -- i) {
            sum += a[i];
            tot += sum;
            ans = max(ans, tot + lcseg.get(m - i, rt));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    solve(0, n);
    cout << ans << endl;
    return 0;
}