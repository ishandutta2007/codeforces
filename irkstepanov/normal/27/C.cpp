#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9;

struct node
{
    int lf, rg;
    node() : lf(inf), rg(-inf) {}
};

vector<node> t;

void update(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr) {
        t[v].lf = t[v].rg = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v].lf = min(t[v * 2].lf, t[v * 2 + 1].lf);
    t[v].rg = max(t[v * 2].rg, t[v * 2 + 1].rg);
}

pii get(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return mp(t[v].lf, t[v].rg);
    }
    pii ans = mp(inf, -inf);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        pii p = get(v * 2, tl, tm, l, min(r, tm));
        ans.first = min(ans.first, p.first);
        ans.second = max(ans.second, p.second);
    }
    if (r > tm) {
        pii p = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        ans.first = min(ans.first, p.first);
        ans.second = max(ans.second, p.second);
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    t.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        update(1, 0, n - 1, i, a[i]);
    }

    map<int, int> leftist, rightist;
    for (int i = 0; i < n; ++i) {
        rightist[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        leftist[a[i]] = i;
    }

    for (int i = 1; i < n - 1; ++i) {
        pii lf = get(1, 0, n - 1, 0, i - 1);
        pii rg = get(1, 0, n - 1, i + 1, n - 1);
        if (lf.first < a[i] && rg.first < a[i]) {
            cout << "3\n";
            cout << leftist[lf.first] + 1 << " " << i + 1 << " " << rightist[rg.first] + 1 << "\n";
            return 0;
        }
        if (lf.second > a[i] && rg.second > a[i]) {
            cout << "3\n";
            cout << leftist[lf.second] + 1 << " " << i + 1 << " " << rightist[rg.second] + 1 << "\n";
            return 0;
        }
    }
    cout << "0\n";

}