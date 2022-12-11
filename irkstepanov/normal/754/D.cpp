#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

struct segment
{
    int l, r;
    int id;
    bool operator<(const segment& other) const
    {
        return l < other.l;
    }
};

bool comp(const segment& a, const segment& b)
{
    return a.r > b.r;
}

vector<int> t;

void update(int v, int tl, int tr, int pos)
{
    if (tl == tr) {
        t[v] = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int get(int v, int tl, int tr, int k)
{
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (t[v * 2 + 1] >= k) {
        return get(v * 2 + 1, tm + 1, tr, k);
    } else {
        return get(v * 2, tl, tm, k - t[v * 2 + 1]);
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("triangles.out");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<segment> a(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        r[i] = a[i].r;
        a[i].id = i;
    }

    if (k == 1) {
        int bestLen = -1, id = -1;
        for (int i = 0; i < n; ++i) {
            int len = a[i].r - a[i].l + 1;
            if (len > bestLen) {
                bestLen = len;
                id = a[i].id;
            }
        }
        cout << bestLen << "\n";
        cout << id + 1 << "\n";
        return 0;
    }

    sort(all(r));
    sort(all(a));

    map<int, vector<int> > mapa;
    for (int i = 0; i < n; ++i) {
        mapa[r[i]].pb(i);
    }
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        w[i] = mapa[a[i].r].back();
        mapa[a[i].r].pop_back();
    }

    t.resize(4 * n);

    int ans = 0;
    int t = -1;
    for (int i = 0; i < k - 1; ++i) {
        update(1, 0, n - 1, w[i]);
    }
    for (int i = k - 1; i < n; ++i) {
        int pos = get(1, 0, n - 1, k - 1);
        update(1, 0, n - 1, w[i]);
        if (min(r[pos], a[i].r) - a[i].l + 1 > ans) {
            ans = min(r[pos], a[i].r) - a[i].l + 1;
            t = i;
        }
    }

    if (ans == 0) {
        cout << "0\n";
        for (int i = 0; i < k; ++i) {
            cout << i + 1 << " ";
        }
        cout << "\n";
        return 0;
    }

    cout << ans << "\n";
    sort(a.begin(), a.begin() + t, comp);
    cout << a[t].id + 1 << " ";
    for (int i = 0; i < k - 1; ++i) {
        cout << a[i].id + 1 << " ";
    }
    cout << "\n";

}