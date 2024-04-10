#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int amax = 200500;
const int inf = 1e9;

struct node
{
    int cnt;
    int promise;
    node() : cnt(0), promise(-1) {}
};

vector<vector<node> > t(26);

void push(int w, int v, int tl, int tr)
{
    if (t[w][v].promise == -1) {
        return;
    }
    int tm = (tl + tr) >> 1;
    if (t[w][v].promise) {
        t[w][v * 2].cnt = tm - tl + 1;
        t[w][v * 2 + 1].cnt = tr - tm;
    } else {
        t[w][v * 2].cnt = t[w][v * 2 + 1].cnt = 0;
    }
    t[w][v * 2].promise = t[w][v].promise;
    t[w][v * 2 + 1].promise = t[w][v].promise;
    t[w][v].promise = -1;
}

void update(int w, int v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        if (val == 1) {
            t[w][v].cnt = tr - tl + 1;
        } else {
            t[w][v].cnt = 0;
        }
        t[w][v].promise = val;
        return;
    }
    push(w, v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(w, v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update(w, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t[w][v].cnt = t[w][v * 2].cnt + t[w][v * 2 + 1].cnt;
}

int get(int w, int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return t[w][v].cnt;
    }
    push(w, v, tl, tr);
    int tm = (tl + tr) >> 1;
    int ans = 0;
    if (l <= tm) {
        ans += get(w, v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        ans += get(w, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    //freopen("input.txt", "r", stdin);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < 26; ++i) {
        t[i].resize(4 * n);
    }

    for (int i = 0; i < n; ++i) {
        update(s[i] - 'a', 1, 0, n - 1, i, i, 1);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        vector<int> v(26);
        for (int i = 0; i < 26; ++i) {
            v[i] = get(i, 1, 0, n - 1, l, r);
        }
        if (k == 1) {
            int oldl = l;
            for (int i = 0; i < 26; ++i) {
                if (v[i]) {
                    update(i, 1, 0, n - 1, oldl, r, 0);
                    update(i, 1, 0, n - 1, l, l + v[i] - 1, 1);
                }
                l += v[i];
            }
        } else {
            int oldr = r;
            for (int i = 0; i < 26; ++i) {
                if (v[i]) {
                    update(i, 1, 0, n - 1, l, oldr, 0);
                    update(i, 1, 0, n - 1, r - v[i] + 1, r, 1);
                }
                r -= v[i];
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < 26; ++i) {
            if (get(i, 1, 0, n - 1, j, j)) {
                cout << (char)(i + 'a');
                break;
            }
        }
    }
    cout << "\n";

}