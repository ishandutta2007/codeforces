#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, q, cnt, ofs = 1, rip;
int x[MAXN], y[MAXN], tip[MAXN], s[MAXN], f[MAXN];
int t[MAXN * 4][2], sol[MAXN * 2];
map <pi, int> mp;
vector <pi> v;
vector <int> r[MAXN * 4], h[MAXN * 2][2];

void update (int pos, int val, int ind) {
    //cout << "update " << pos << " " << val << " " << ind << endl;
    pos += ofs; t[pos][ind] = val; pos /= 2;
    while (pos > 0) {
        if (ind == 0) t[pos][0] = max(t[pos * 2][0], t[pos * 2 + 1][0]);
        if (ind == 1) t[pos][1] = min(t[pos * 2][1], t[pos * 2 + 1][1]);
        pos /= 2;
    }
}

int upit (int x, int from, int to, int lo, int hi, int ind) {
    if (from <= lo && hi <= to) return t[x][ind];
    if (to < lo || hi < from) return (ind == 0 ? -1 : 1e9);
    if (ind == 0) return max(upit(2 * x, from, to, lo, (lo + hi) / 2, 0), upit(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi, 0));
    if (ind == 1) return min(upit(2 * x, from, to, lo, (lo + hi) / 2, 1), upit(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi, 1));
}

void ubaci (int i) {
    //cout << "ubaci " << i << " " << tip[i] << endl;
    v.push_back({i, rip});
    if (tip[i] == 0) {
        h[x[i]][0].push_back(max(y[i], h[x[i]][0].back()));
        if (t[x[i] + ofs][0] <= y[i]) update(x[i], y[i], 0);
        if (upit(1, 0, x[i], 0, ofs - 1, 1) <= y[i]) rip++;
    } else {
        h[x[i]][1].push_back(min(y[i], h[x[i]][1].back()));
        if (y[i] <= t[x[i] + ofs][1]) update(x[i], y[i], 1);
        if (y[i] <= upit(1, x[i], ofs - 1, 0, ofs - 1, 0)) rip++;
    }
}

void makni () {
    //cout << "makni" << endl;
    int i = v.back().first;
    rip = v.back().second;
    v.pop_back();
    h[x[i]][tip[i]].pop_back();
    update(x[i], h[x[i]][tip[i]].back(), tip[i]);
}

void add_query (int x, int from, int to, int lo, int hi, int ind) {
    if (from <= lo && hi <= to) {
        r[x].push_back(ind);
        return;
    }
    if (to < lo || hi < from) return;
    add_query(2 * x, from, to, lo, (lo + hi) / 2, ind);
    add_query(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi, ind);
}

void dfs (int x, int lo, int hi) {
    int siz = v.size();
    for (auto i : r[x]) ubaci(i);
    if (lo == hi) {
        sol[lo] = (rip == 0);
    } else {
        dfs(2 * x, lo, (lo + hi) / 2);
        dfs(2 * x + 1, (lo + hi) / 2 + 1, hi);
    }
    while (v.size() > siz) makni();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    while (ofs < max(max(n, m), q)) ofs *= 2;
    for (int i = 0; i < 2*ofs; i++) {
        t[i][0] = -1, t[i][1] = 1e9;
        if (i < ofs) {
            h[i][0].push_back(-1);
            h[i][1].push_back(1e9);
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (mp.find({a, b}) == mp.end()) {
            cnt++;
            x[cnt] = a / 2; y[cnt] = b / 2; tip[cnt] = !(a % 2);
            s[cnt] = i; f[cnt] = ofs;
            mp[{a, b}] = cnt;
        } else {
            int ind = mp[{a, b}];
            f[ind] = i;
            mp.erase({a, b});
        }
    }
    for (int i = 1; i <= cnt; i++) {
        add_query(1, s[i], f[i] - 1, 0, ofs - 1, i);
    }
    dfs(1, 0, ofs - 1);
    for (int i = 0; i < q; i++) {
        cout << (sol[i] ? "YES\n" : "NO\n");
    }
    return 0;
}