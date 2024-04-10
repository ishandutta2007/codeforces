#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;
const int INF = 1000000000;

int n, ofs = 1;
char a[MAXN];
string s;

struct node {
    int mn, mx, prop;
    node () {
        mn = mx = prop = 0;
    }
    node (int _mn, int _mx) {
        mn = _mn; mx = _mx; prop = 0;
    }
} t[MAXN * 4];

int from, to, dif;

void propagate (int x) {
    if (t[x].prop == 0) return;
    if (x < ofs) {
        t[2*x].prop += t[x].prop;
        t[2*x+1].prop += t[x].prop;
    }
    t[x].mn += t[x].prop;
    t[x].mx += t[x].prop;
    t[x].prop = 0;
}

node spoji (node a, node b) {
    return node(min(a.mn, b.mn), max(a.mx, b.mx));
}

void update (int x, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) {
        t[x].prop += dif;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2 * x, lo, (lo + hi) / 2);
    update(2 * x + 1, (lo + hi) / 2 + 1, hi);
    t[x] = spoji(t[2*x], t[2*x+1]);
}

int get (char c) {
    if (c == '(') return 1;
    if (c == ')') return -1;
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i <= n; i++) a[i] = '.';
    while (ofs < n) ofs *= 2;
    int pos = 0, sign = 0;
    for (auto c : s) {
        if (c == 'R') {
            pos++;
        } else if (c == 'L') {
            pos--;
            if (pos < 0) pos++;
        } else {
            from = pos; to = ofs - 1, dif = -get(a[pos]);
            sign += dif;
            if (dif != 0) update(1, 0, ofs - 1);
            a[pos] = c; dif = get(a[pos]);
            sign += dif;
            if (dif != 0) update(1, 0, ofs - 1);
        }
        if (sign != 0 || t[1].mn < 0) {
            cout << -1 << " ";
        } else {
            cout << t[1].mx << " ";
        }
    }
    return 0;
}