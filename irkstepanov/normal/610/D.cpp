#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

ll ans = 0;

struct simpleEvent
{
    int pos;
    char c;
    bool operator<(const simpleEvent& other) const
    {
        if (pos != other.pos) {
            return pos < other.pos;
        }
        if (c != other.c) {
            if (c == 'o') {
                return true;
            }
            if (other.c == 'o') {
                return false;
            }
        }
        return false;
    }
};

vector<pii> convert(vector<pii>& v)
{
    sort(all(v));
    vector<simpleEvent> e(2 * sz(v));
    int pos = 0;
    forn(i, sz(v)) {
        e[pos++] = {v[i].first, 'o'};
        e[pos++] = {v[i].second, 'c'};
    }
    sort(all(e));
    int balance = 0, curr;
    vector<pii> t;
    forn(i, sz(e)) {
        if (e[i].c == 'o') {
            ++balance;
            if (balance == 1) {
                curr = e[i].pos;
            }
            continue;
        }
        --balance;
        if (!balance) {
            t.pb(mp(curr, e[i].pos));
            ans += static_cast<ll>(e[i].pos - curr + 1);
        }
    }
    return t;
}

struct event
{
    int pos;
    char c;
    int id;
    bool operator<(const event& other) const
    {
        if (pos != other.pos) {
            return pos < other.pos;
        }
        if (c != other.c) {
            if (c == 'o') {
                return true;
            }
            if (other.c == 'o') {
                return false;
            }
            if (c == '?') {
                return true;
            }
            if (other.c == '?') {
                return false;
            }
        }
        return false;
    }
};

vector<int> tree;
int T;

void update(int pos, int val)
{
    pos += T;
    tree[pos] = val;
    for (pos >>= 1; pos; pos >>= 1) {
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
}

int get(int l, int r)
{
    int a = 0;
    for (l += T, r += T; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            a += tree[l];
        }
        if (!(r & 1)) {
            a += tree[r];
        }
    }
    return a;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    scanf("%d", &n);

    map<int, vector<pii> > horOld;
    map<int, vector<pii> > verOld;

    forn(i, n) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a == c) {
            verOld[a].pb(mp(min(b, d), max(b, d)));
        } else {
            horOld[b].pb(mp(min(a, c), max(a, c)));
        }
    }

    vector<vector<pii> > hor;
    vector<vector<pii> > ver;
    vector<int> horC, verC;

    for (map<int, vector<pii> >::iterator it = verOld.begin(); it != verOld.end(); ++it) {
        vector<pii> v = convert(it->second);
        ver.pb(v);
        verC.pb(it->first);
    }
    for (map<int, vector<pii> >::iterator it = horOld.begin(); it != horOld.end(); ++it) {
        vector<pii> v = convert(it->second);
        hor.pb(v);
        horC.pb(it->first);
    }

    if (hor.empty()) {
        cout << ans << "\n";
        return 0;
    }
    T = sz(hor);

    vector<event> e;
    for (int i = 0; i < sz(verC); ++i) {
        e.pb({verC[i], '?', i});
    }

    for (int i = 0; i < sz(hor); ++i) {
        for (int j = 0; j < sz(hor[i]); ++j) {
            e.pb({hor[i][j].first, 'o', i});
            e.pb({hor[i][j].second, 'c', i});
        }
    }

    sort(all(e));

    tree.resize(2 * T);

    for (int i = 0; i < sz(e); ++i) {
        if (e[i].c == 'o') {
            update(e[i].id, 1);
        }
        if (e[i].c == 'c') {
            update(e[i].id, 0);
        }
        if (e[i].c == '?') {
            ///work with ver[e[i].id]
            for (pii p : ver[e[i].id]) {
                int down = p.first, up = p.second;
                int l = 0, r = T - 1;
                while (r - l > 1) {
                    int m = (l + r) >> 1;
                    if (horC[m] < down) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                int L = -1;
                if (horC[l] >= down && horC[l] <= up) {
                    L = l;
                } else if (horC[r] >= down && horC[r] <= up) {
                    L = r;
                } else {
                    continue;
                }
                l = 0, r = T - 1;
                while (r - l > 1) {
                    int m = (l + r) >> 1;
                    if (horC[m] > up) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                int R = -1;
                if (horC[r] >= down && horC[r] <= up) {
                    R = r;
                } else if (horC[l] >= down && horC[l] <= up) {
                    R = l;
                } else {
                    continue;
                }
                int cnt = get(L, R);
                ans -= static_cast<ll>(cnt);
            }
        }
    }

    cout << ans << "\n";

}