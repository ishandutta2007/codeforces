#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef long double ld;
typedef pair <llint, llint> pi;

const int MAXN = 100005;

llint n, cnt, br, jen, dva, uk, ofs = 1;
llint a[MAXN], b[MAXN], c[MAXN];
llint x[MAXN], y[MAXN], sum[MAXN];
int pos[MAXN], lim[MAXN], t[MAXN * 4], prop[MAXN * 4];
vector <int> q, v, r;
map <pi, llint> mp;

int sign (int i) {
    if (y[i] > 0) return 1;
    if (y[i] < 0) return -1;
    if (x[i] > 0) return 1;
    if (x[i] < 0) return -1;
}

__int128 ccw (int i, int j) {
    return (__int128) x[i] * y[j] - (__int128) x[j] * y[i];
}

bool cmp (int i, int j) {
    if (sign(i) == 1) {
        if (sign(j) == -1) return 1;
    } else {
        if (sign(j) == 1) return 0;
    }
    return ccw(i, j) > 0;
}

void poredaj () {
    for (int i = 1; i <= cnt; i++) {
        if (x[i] != 0 || y[i] != 0) v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if (i != 0 && x[v[i]] == x[v[i-1]] && y[v[i]] == y[v[i-1]]) {
            pos[v[i]] = pos[v[i-1]];
            continue;
        }
        pos[v[i]] = br++;
        r.push_back(v[i]);
    }
    while (ofs < br) ofs *= 2;
}

void two_pointers () {
    if (br <= 1) return;
    int curr = br - 1;
    for (int i = br - 1; i >= 0; i--) {
        while (1) {
            int nxt = (curr == 0 ? br - 1 : curr - 1);
            if (nxt == i || ccw(r[i], r[nxt]) > 0) break;
            curr = nxt;
        }
        lim[i] = curr;
        if (curr == i) curr--;
    }
}

void propagate (int x) {
    if (prop[x] == 0) return;
    if (x < ofs) {
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    t[x] += prop[x];
    prop[x] = 0;
}

int from, to, val;

void update (int x, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) {
        prop[x] += val;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2 * x, lo, (lo + hi) / 2);
    update(2 * x + 1, (lo + hi) / 2 + 1, hi);
    t[x] = max(t[2 * x], t[2 * x + 1]);
}

void upd (int FROM, int TO, int VAL) {
    from = FROM, to = TO, val = VAL;
    update(1, 0, ofs - 1);
}

void ubaci (int ind, int k) {
    uk += k;
    if (x[ind] == 0 && y[ind] == 0) {
        jen += k;
        return;
    }

    dva -= mp[{x[ind], y[ind]}] * mp[{-x[ind], -y[ind]}];
    mp[{x[ind], y[ind]}] += k;
    dva += mp[{x[ind], y[ind]}] * mp[{-x[ind], -y[ind]}];

    int i = pos[ind];
    if (lim[i] <= i) {
        upd(lim[i], i, k);
    } else {
        upd(lim[i], br - 1, k);
        upd(0, i, k);
    }
}

int get () {
    if (jen > 0) return 1;
    if (dva > 0) return 2;
    if (t[1] < uk) return 3;
    return 0;
}

void solve () {
    for (auto i : q) {
        if (i > 0) ubaci(i, 1); else ubaci(-i, -1);
        cout << get() << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a[0] >> b[0] >> c[0] >> n;
    sum[0] = a[0] + b[0] + c[0];
    for (int i = 1; i <= n; i++) {
        char tip;
        cin >> tip;
        if (tip == 'A') {
            cnt++;
            q.push_back(cnt);
            cin >> a[cnt] >> b[cnt] >> c[cnt];

            sum[cnt] = a[cnt] + b[cnt] + c[cnt];
            x[cnt] = a[cnt] * sum[0] - a[0] * sum[cnt];
            y[cnt] = b[cnt] * sum[0] - b[0] * sum[cnt];

            if (x[cnt] != 0 && y[cnt] != 0) {
                llint d = __gcd(abs(x[cnt]), abs(y[cnt]));
                x[cnt] /= d; y[cnt] /= d;
            } else if (x[cnt] != 0) {
                x[cnt] /= abs(x[cnt]);
            } else if (y[cnt] != 0) {
                y[cnt] /= abs(y[cnt]);
            }
        } else {
            int ind; cin >> ind;
            q.push_back(-ind);
        }
    }
    poredaj();
    two_pointers();
    solve();
    return 0;
}