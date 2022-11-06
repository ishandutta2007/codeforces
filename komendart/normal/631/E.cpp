#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)(x).size())

const int tsize = 1 << 21;
const int maxw = 1e6;
const int inf = 1e17;

struct Line {
    int k, b;
    
    Line(): k(0), b(-inf) {}
    Line(int k, int b): k(k), b(b) {}
    
    int get(int x) const {
        return k * (x - maxw) + b;
    }
};

Line tree[tsize * 2];

void clear() {
    for (int i = 0; i < tsize * 2; ++i) {
        tree[i] = Line();
    }
}

int get(int x) {
    x += maxw;
    int ans = -inf;
    for (int p = x + tsize; p > 0; p >>= 1) {
        ans = max(ans, tree[p].get(x));
    }
    return ans;
}

void update(Line line, int v, int tl, int tr) {
    if (line.get(tl) <= tree[v].get(tl) && line.get(tr) <= tree[v].get(tr)) {
        return;
    }
    if (line.get(tl) >= tree[v].get(tl) && line.get(tr) >= tree[v].get(tr)) {
        tree[v] = line;
        return;
    }
    int tm = (tl + tr) / 2;
    if (line.get(tl) < tree[v].get(tl)) swap(line, tree[v]);
    if (line.get(tm) < tree[v].get(tm)) {
        update(line, v * 2, tl, tm);
    } else {
        swap(line, tree[v]);
        update(line, v * 2 + 1, tm + 1, tr);
    }
}

void addLine(int k, int b) {
    update(Line(k, b), 1, 0, tsize - 1);
}

int solveForward(const vector<int> &a) {
    clear();
    int pref = 0;
    int ans = 0;
    for (int i = 0; i < sz(a); ++i) {
        addLine(i, -pref);
        ans = max(ans, pref - a[i] * i + get(a[i]));
        pref += a[i];
    }
    return ans;
}

int solveReverse(const vector<int> &a) {
    clear();
    int suf = 0;
    int ans = 0;
    for (int i = sz(a) - 1; i >= 0; --i) {
        addLine(i, suf);
        ans = max(ans, -a[i] * i - suf + get(a[i]));
        suf += a[i];
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int inc = max(solveForward(a), solveReverse(a));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (i + 1) * a[i];
    }
    ans += inc;
    cout << ans << '\n';
}