#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;

int n, q, ofs = 1;
string s;
int t[2][MAXN * 4], prop[MAXN * 4], fen[MAXN];
set <int> st;

////////////////////////////////////////////////////////////////////////////////////////////////

void fen_ubaci (int x) {
    for (; x < MAXN; x += x&-x) fen[x] ^= 1;
}

int fen_upit (int x) {
    int res = 0;
    for (; x > 0; x -= x&-x) res ^= fen[x];
    return res;
}

bool get (int pos, int tip) {
    if (tip) return fen_upit(pos);
    return !fen_upit(pos + 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////

void propagate (int x) {
	if (prop[x] == 0) return;
	if (x < ofs) {
		prop[2*x] ^= 1;
		prop[2*x+1] ^= 1;
	}
	swap(t[0][x], t[1][x]);
    prop[x] ^= 1;
}

int qpos, qva, qvb, qfrom, qto;

void update (int x, int lo, int hi) {
	propagate(x);
	if (qpos < lo || hi < qpos) return;
	if (lo == hi) {
        t[0][x] = qva; t[1][x] = qvb;
		return;
	}
	update(2 * x, lo, (lo + hi) / 2);
	update(2 * x + 1, (lo + hi) / 2 + 1, hi);
	t[0][x] = max(t[0][2 * x], t[0][2 * x + 1]);
	t[1][x] = max(t[1][2 * x], t[1][2 * x + 1]);
}

void okreni (int x, int lo, int hi) {
    propagate(x);
    if (qfrom <= lo && hi <= qto) {
        prop[x] = 1;
        propagate(x);
        return;
    }
    if (qto < lo || hi < qfrom) return;
	okreni(2 * x, lo, (lo + hi) / 2);
	okreni(2 * x + 1, (lo + hi) / 2 + 1, hi);
	t[0][x] = max(t[0][2 * x], t[0][2 * x + 1]);
	t[1][x] = max(t[1][2 * x], t[1][2 * x + 1]);
}

int upit (int x, int lo, int hi) {
    propagate(x);
    if (qfrom <= lo && hi <= qto) return t[0][x];
	if (qto < lo || hi < qfrom) return 0;
	return max(upit(2 * x, lo, (lo + hi) / 2), upit(2 * x + 1, (lo + hi) / 2 + 1, hi));
}

////////////////////////////////////////////////////////////////////////////////////////////////

void refresh (int pos) {
    auto it = st.find(pos);
    int sol = 0;
    if (it != st.begin()) {
        it--;
        sol += pos - (*it);
        it++;
    }
    it++;
    if (it != st.end()) sol += (*it) - pos;

    qpos = pos; qva = sol; qvb = 0;
    if (get(pos, pos == n)) swap(qva, qvb);
    //cout << (qvb == 0 ? "suck" : "spit") << " " << qpos << " " << sol << endl;
    update(1, 0, ofs - 1);
}

void ubaci (int pos) {
    //cout << "ubaci " << pos << endl;
    if (pos == 0 || pos == n) return;
    auto nxt = st.lower_bound(pos);
    auto prv = nxt; prv--;
    st.insert(pos);
    refresh(pos); refresh(*prv); refresh(*nxt);
}

void izbaci (int pos) {
    //cout << "izbaci " << pos << endl;
    if (pos == 0 || pos == n) return;
    auto nxt = st.upper_bound(pos);
    st.erase(pos);
    auto prv = nxt; prv--;
    refresh(*prv); refresh(*nxt);

    qpos = pos; qva = 0; qvb = 0;
    update(1, 0, ofs - 1);
}

void toggle (int pos) {
    if (pos == 0 || pos == n) return;
    if (st.count(pos)) izbaci(pos); else ubaci(pos);
}

////////////////////////////////////////////////////////////////////////////////////////////////

void upd (int a, int b) {
    //cout << "upd" << endl;
    qfrom = a; qto = b - 1;
    if (qfrom <= qto) okreni(1, 0, ofs - 1);
    fen_ubaci(a); fen_ubaci(b + 1);
    toggle(a - 1); toggle(b);
}

int calc_lef (int pos) {
    if (get(pos, 0)) return 0;
    auto it = st.find(pos); it++;
    return (*it) - pos;
}
int calc_rig (int pos) {
    if (get(pos, 1)) return 0;
    auto it = st.find(pos); it--;
    return pos - (*it);
}

int solve (int a, int b) {
    //cout << "solve" << endl;
    bool lef = 0, rig = 0;
    if (st.count(a - 1) == 0) lef = 1, toggle(a - 1);
    if (st.count(b) == 0) rig = 1, toggle(b);

    qfrom = a; qto = b - 1;
    int sol = 0;
    if (qfrom <= qto) sol = max(sol, upit(1, 0, ofs - 1));
    sol = max(sol, calc_lef(a - 1));
    sol = max(sol, calc_rig(b));

    if (lef) toggle(a - 1);
    if (rig) toggle(b);
    return sol;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s;
    while (ofs < n + 1) ofs *= 2;
    st.insert(0); st.insert(n);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) st.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') fen_ubaci(i + 1), fen_ubaci(i + 2);
    }
    for (auto x : st) refresh(x);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        upd(a, b);
        cout << solve(a, b) << '\n';
    }
    return 0;
}