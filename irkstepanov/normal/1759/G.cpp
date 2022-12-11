#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

struct node {
    int sum;
    int pref;
    int pos;
    node() : sum(0), pref(0), pos(-1) {}
};

vector<node> t;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v].sum = val;
        t[v].pref = min(0, val);
        t[v].pos = (val == 1 ? tl : -1);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    t[v].pref = min(t[v * 2].pref, t[v * 2].sum + t[v * 2 + 1].pref);
    t[v].pos = max(t[v * 2].pos, t[v * 2 + 1].pos);
}

int getLast(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v].pos;
    }
    int tm = (tl + tr) >> 1;
    if (r > tm) {
        int ans = getLast(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        if (ans != -1) {
            return ans;
        }
    }
    return getLast(v * 2, tl, tm, l, min(r, tm));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;
    
    while (tt--) {
        int n;
        cin >> n;
        t = vector<node>(4 * n);
        vector<int> b(n / 2);
        vector<bool> was(n + 1, false);
        for (int i = 0; i < n / 2; ++i) {
            cin >> b[i];
            was[b[i]] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (was[i]) {
                ++cnt;
            }
            update(1, 1, n, i, (was[i] ? -1 : 1));
        }
        if (cnt != n / 2 || t[1].pref < 0) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n / 2; ++i) {
            int lf = 0, rg = b[i] - 1;
            update(1, 1, n, b[i], 0);
            while (rg - lf > 1) {
                int md = (lf + rg) >> 1;
                int g = getLast(1, 1, n, 1, md);
                if (g == -1) {
                    lf = md;
                    continue;
                }
                update(1, 1, n, g, 0);
                if (t[1].pref < 0) {
                    lf = md;
                } else {
                    rg = md;
                }
                update(1, 1, n, g, 1);
            }
            cout << rg << " " << b[i] << " ";
            update(1, 1, n, rg, 0);
        }
        cout << "\n";
    }

}