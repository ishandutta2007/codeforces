#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

struct node {
    int pro;
    int minn;
    node() : pro(0), minn(inf) {}
};

vector<node> t;

void build(int v, int tl, int tr, vector<int>& a) {
    if (tl == tr) {
        t[v].minn = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].minn = min(t[v * 2].minn, t[v * 2 + 1].minn);
}

void push(int v) {
    int x = t[v].pro;
    t[v * 2].minn += x;
    t[v * 2].pro += x;
    t[v * 2 + 1].minn += x;
    t[v * 2 + 1].pro += x;
    t[v].pro = 0;
}

int getMin(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v].minn;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    int ans = inf;
    if (l <= tm) {
        ans = min(ans, getMin(v * 2, tl, tm, l, min(r, tm)));
    }
    if (r > tm) {
        ans = min(ans, getMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    return ans;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (tl == l && tr == r) {
        t[v].minn += val;
        t[v].pro += val;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t[v].minn = min(t[v * 2].minn, t[v * 2 + 1].minn);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    int n, k;
    cin >> n >> k;

    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    t.resize(4 * (n + 1));
    build(1, 0, n, b);

    vector<bool> used(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (int x = 1; x <= n; ++x) {
            if (used[x]) {
                continue;
            }
            if (getMin(1, 0, n, x, x)) {
                continue;
            }
            if (x - k >= 1 && getMin(1, 0, n, 1, x - k) == 0) {
                continue;
            }
            used[x] = true;
            cout << x << " ";
            if (x - k >= 1) {
                update(1, 0, n, 1, x - k, -1);
            }
            update(1, 0, n, x, x, inf);
            break;
        }
    }

    cout << "\n";

}