#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;

int n, m, q, cnt, br, ofs = 1;
int p[MAXN], par[MAXN];
int ea[MAXN], eb[MAXN], tip[MAXN], ind[MAXN], ok[MAXN], bitan[MAXN];
int lo[MAXN], hi[MAXN];
vector <int> v[MAXN], ch[MAXN];
set <int> lef, rig;
pi mn[MAXN * 4];

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

void dfs (int x) {
    lo[x] = hi[x] = br;
    for (auto sus : ch[x]) {
        dfs(sus);
        hi[x] = hi[sus];
    }
    if (ch[x].size() == 0) {
        mn[ofs + br] = {p[x], br};
        br++;
    }
}

int get_lef (int pos) {
    auto it = lef.upper_bound(pos);
    it--;
    return *it;
}

int get_rig (int pos) {
    auto it = rig.lower_bound(pos);
    return *it;
}

pi spoji (pi a, pi b) {
    if (a.first > b.first) return a;
    return b;
}

void update (int x, int from, int to, int lo, int hi) {
	if (from <= lo && hi <= to) {
        mn[lo + ofs].first = 0;
		return;
	}
	if (to < lo || hi < from) return;
	update(2 * x, from, to, lo, (lo + hi) / 2);
	update(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi);
	mn[x] = spoji(mn[2 * x], mn[2 * x + 1]);
}

pi upit (int x, int from, int to, int lo, int hi) {
	if (from <= lo && hi <= to) return mn[x];
	if (to < lo || hi < from) return {-1e9, 0};
	return spoji(upit(2 * x, from, to, lo, (lo + hi) / 2), upit(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi));
}

void ispis () {
    for (int i =0 ; i < 2*ofs; i++) {
        cout << "bla " << i << " " << mn[i].first << " " << mn[i].second << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    cnt = n;
    while (ofs < n) ofs *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        par[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> ea[i] >> eb[i];
        ok[i] = 1;
    }
    for (int i = 1; i <= q; i++) {
        cin >> tip[i] >> ind[i];
        if (tip[i] == 2) ok[ind[i]] = 0;
    }
    for (int i = 1; i <= m; i++) {
        if (ok[i]) {
            int a = nadi(ea[i]);
            int b = nadi(eb[i]);
            if (a == b) continue;
            cnt++;
            par[a] = par[b] = par[cnt] = cnt;
            ch[cnt].push_back(a);
            ch[cnt].push_back(b);
        }
    }
    for (int i = q; i >= 1; i--) {
        if (tip[i] == 2) {
            int a = nadi(ea[ind[i]]);
            int b = nadi(eb[ind[i]]);
            if (a == b) continue;
            bitan[i] = 1;
            cnt++;
            par[a] = par[b] = par[cnt] = cnt;
            ch[cnt].push_back(a);
            ch[cnt].push_back(b);
            v[i].push_back(cnt);
            v[i].push_back(a);
            v[i].push_back(b);
        }
    }
    for (int i = 0; i < 2 * ofs; i++) mn[i] = {-1e9, 0};
    for (int i = 1; i <= cnt; i++) {
        if (par[i] == i) {
            dfs(i);
            lef.insert(lo[i]);
            rig.insert(hi[i]);
        }
    }
    for (int i = ofs - 1; i > 0; i--) {
        mn[i] = spoji(mn[2 * i], mn[2 * i + 1]);
    }
    for (int i = 1; i <= q; i++) {
        if (tip[i] == 1) {
            int pos = lo[ind[i]];
            int L = get_lef(pos);
            int R = get_rig(pos);
            pi res = upit(1, L, R, 0, ofs - 1);
            cout << res.first << '\n';
            update(1, res.second, res.second, 0, ofs - 1);
        } else {
            if (bitan[i]) {
                int root = v[i][0], a = v[i][1], b = v[i][2];
                lef.insert(lo[b]);
                rig.insert(hi[a]);
            }
        }
    }
    return 0;
}