#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, cnt, ofs = 1, uk;
int p[MAXN], pos[MAXN], fen[MAXN];
set <int> st;
set <int> :: iterator it;

void fen_ubaci (int x) {
    for (; x < MAXN; x += x&-x) fen[x]++;
}

int fen_upit (int x) {
    int res = 0;
    for (; x > 0; x -= x&-x) res += fen[x];
    return res;
}

struct node {
    llint val, br, prop;
    node () {
        val = br = prop = 0;
    }
    node (llint _val, llint _br) {
        val = _val; br = _br; prop = 0;
    }
} t[MAXN * 3];

void propagate (int x) {
    if (t[x].prop == 0) return;
    if (x < ofs) {
        t[2*x].prop += t[x].prop;
        t[2*x+1].prop += t[x].prop;
    }
    t[x].val += t[x].prop * t[x].br;
    t[x].prop = 0;
}

node spoji (node a, node b) {
    return node(a.val + b.val, a.br + b.br);
}

int from, to, q;

void update (int x, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) {
        t[x].prop--;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2*x, lo, (lo + hi) / 2);
    update(2*x + 1, (lo + hi) / 2 + 1, hi);
    t[x] = spoji(t[2*x], t[2*x+1]);
}

void upali (int x, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) {
        t[x].br = 1;
        t[x].val = q;
        return;
    }
    if (to < lo || hi < from) return;
    upali(2*x, lo, (lo + hi) / 2);
    upali(2*x + 1, (lo + hi) / 2 + 1, hi);
    t[x] = spoji(t[2*x], t[2*x+1]);
}

llint upit (int x, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) return t[x].val;
    if (to < lo || hi < from) return 0;
    return upit(2*x, lo, (lo + hi) / 2) + upit(2*x + 1, (lo + hi) / 2 + 1, hi);
}

void dodaj (int x) {
    st.insert(pos[x]);
    if (x == 1) {
        it = st.begin(); cnt = 1;
        return;
    }
    if (pos[x] < *it) cnt++;
    if (cnt < (x + 1) / 2) it++, cnt++;
    if (cnt > (x + 1) / 2) it--, cnt--;
}

llint get_dist (int x) {
    uk += x - 1 - fen_upit(pos[x]);
    llint res = 0;
    fen_ubaci(pos[x]);

    from = to = pos[x];
    q = pos[x] - fen_upit(pos[x] - 1);
    upali(1, 0, ofs - 1);

    from = pos[x] + 1; to = n;
    if (from <= to) update(1, 0, ofs - 1);

    from = 1; to = *it;
    if (from <= to) {
        llint sum = upit(1, 0, ofs - 1);
        //cout << "bla " << from << " " << to << " " << sum << endl;
        res += cnt * ((*it) - cnt + 1) - sum;
    }
    from = (*it) + 1; to = n;
    if (from <= to) {
        llint sum = upit(1, 0, ofs - 1);
        //cout << "bla " << from << " " << to << " " << sum << endl;
        res += sum - (x - cnt) * ((*it) - cnt + 1);
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (ofs < n+1) ofs *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        dodaj(i);
        cout << get_dist(i) + uk << " ";
    }
    return 0;
}