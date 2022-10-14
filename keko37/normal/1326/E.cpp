#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

int n, ofs = 1;
int p[MAXN];
int t[MAXN * 4];
int mx[MAXN * 4], ind[MAXN * 4], prop[MAXN * 4];
set <int> st;

int spoji (int a, int b) {
    if (p[a] > p[b]) return a; return b;
}

void t_init () {
    for (int i = 0; i < 2*ofs; i++) t[i] = ind[i] = n;
    for (int i = 0; i < n; i++) {
        st.insert(i + 1);
        t[i + ofs] = ind[i + ofs] = i;
    }
    for (int i = ofs-1; i >= 0; i--) {
        t[i] = spoji(t[i * 2], t[i * 2 + 1]);
        ind[i] = ind[i * 2];
    }
}

int upit (int x, int from, int to, int lo, int hi) {
    if (from <= lo && hi <= to) return t[x];
    if (to < lo || hi < from) return n;
    return spoji(upit(2 * x, from, to, lo, (lo + hi) / 2), upit(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi));
}

void brisi (int pos) {
    p[pos] = -1e9;
    pos = (pos + ofs) / 2;
    while (pos > 0) {
        t[pos] = spoji(t[pos * 2], t[pos * 2 + 1]);
        pos /= 2;
    }
}

void propagate (int x) {
    if (prop[x] == 0) return;
    if (x < ofs) {
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    mx[x] += prop[x];
    prop[x] = 0;
}

void update (int x, int from, int to, int lo, int hi, int d) {
    propagate(x);
    if (from <= lo && hi <= to) {
        prop[x] += d;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2 * x, from, to, lo, (lo + hi) / 2, d);
    update(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi, d);
    mx[x] = max(mx[2 * x], mx[2 * x + 1]);
    if (mx[2 * x] >= mx[2 * x + 1]) ind[x] = ind[2 * x]; else ind[x] = ind[2 * x + 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (ofs < n) ofs *= 2;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    t_init();
    cout << n << " ";
    for (int i = 0; i < n-1; i++) {
        int pos; cin >> pos; pos--;
        update(1, pos, n-1, 0, ofs - 1, 1);
        pos = ind[1];
        int get = upit(1, 0, pos, 0, ofs - 1);
        st.erase(p[get]);
        brisi(get);
        update(1, get, n-1, 0, ofs - 1, -1);
        cout << *st.rbegin() << " ";
    }
    return 0;
}