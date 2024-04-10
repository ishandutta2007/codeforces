#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

struct node
{
    int cnt[10][10];
    int l, r, promise;
    node()
    {
        forn(i, 10) {
            forn(j, 10) {
                cnt[i][j] = 0;
            }
        }
        l = r = 0;
        promise = -1;
    }
};

int n;
vector<node> t;
string s;

void push(int v, int tl, int tr)
{
    if (t[v].promise == -1) {
        return;
    }
    if (tl == tr) {
        t[v].promise = -1;
        return;
    }
    t[v * 2].l = t[v].promise;
    t[v * 2 + 1].l = t[v].promise;
    t[v * 2].r = t[v].promise;
    t[v * 2 + 1].r = t[v].promise;
    forn(i, 10) {
        forn(j, 10) {
            t[v * 2].cnt[i][j] = 0;
            t[v * 2 + 1].cnt[i][j] = 0;
        }
    }
    int pr = t[v].promise;
    int tm = (tl + tr) >> 1;
    t[v * 2].cnt[pr][pr] = tm - tl;
    t[v * 2 + 1].cnt[pr][pr] = tr - (tm + 1);
    t[v * 2].promise = t[v].promise;
    t[v * 2 + 1].promise = t[v].promise;
    t[v].promise = -1;
}

void build(int v, int tl, int tr)
{
    if (tl == tr) {
        t[v].l = t[v].r = s[tl] - 'a';
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    forn(i, 10) {
        forn(j, 10) {
            t[v].cnt[i][j] = t[v * 2].cnt[i][j] + t[v * 2 + 1].cnt[i][j];
        }
    }
    ++t[v].cnt[t[v * 2].r][t[v * 2 + 1].l];
    t[v].l = t[v * 2].l;
    t[v].r = t[v * 2 + 1].r;
}

void update(int v, int tl, int tr, int l, int r, int c)
{
    if (l > r) {
        return;
    }
    push(v, tl, tr);
    if (tl == l && tr == r) {
        forn(i, 10) {
            forn(j, 10) {
                t[v].cnt[i][j] = 0;
            }
        }
        t[v].cnt[c][c] = tr - tl;
        t[v].l = t[v].r = c;
        t[v].promise = c;
        return;
    }
    int tm = (tl + tr) >> 1;
    update(v * 2, tl, tm, l, min(r, tm), c);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, c);
    forn(i, 10) {
        forn(j, 10) {
            t[v].cnt[i][j] = t[v * 2].cnt[i][j] + t[v * 2 + 1].cnt[i][j];
        }
    }
    ++t[v].cnt[t[v * 2].r][t[v * 2 + 1].l];
    t[v].l = t[v * 2].l;
    t[v].r = t[v * 2 + 1].r;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("output.txt", "w", stdout);

    int m, k;
    cin >> n >> m >> k;

    cin >> s;
    t.resize(4 * n);

    build(1, 0, n - 1);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            char c;
            cin >> c;
            update(1, 0, n - 1, l, r, c - 'a');
        } else {
            string r;
            cin >> r;
            vector<int> pos(k);
            forn(i, k) {
                pos[r[i] - 'a'] = i;
            }
            int ans = 1;
            forn(i, k) {
                forn(j, k) {
                    if (!t[1].cnt[i][j]) {
                        continue;
                    }
                    //cout << i << " " << j << " " << t[1].cnt[i][j] << "\n";
                    int x = pos[i], y = pos[j];
                    //cout << i << " " << j << " " << t[1].cnt[i][j] << "\n";
                    if (x >= y) {
                        ans += t[1].cnt[i][j];
                    }
                }
            }
            cout << ans << "\n";
        }
    }

}