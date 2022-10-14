#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

int tt, n, ofs = 1, cnt;
pair <int, int> pi[MAXN];

struct node {
    int mn, prop;
    node () {}
} t[MAXN * 4];

void propagate (int x) {
    if (t[x].prop == 0) return;
    if (x < ofs) {
        t[2*x].prop += t[x].prop;
        t[2*x+1].prop += t[x].prop;
    }
    t[x].mn += t[x].prop;
    t[x].prop = 0;
}

node spoji (node a, node b) {
    if (a.mn < b.mn) return a; return b;
}

void update (int x, int from, int to, int lo, int hi, int val) {
    propagate(x);
    if (from <= lo && hi <= to) {
        t[x].prop += val;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2*x, from, to, lo, (lo + hi) / 2, val);
    update(2*x+1, from, to, (lo + hi) / 2 + 1, hi, val);
    t[x] = spoji(t[2*x], t[2*x+1]);
}

void tour () {
    while (ofs < n) ofs *= 2;
    for (int i = 0; i < 2*ofs; i++) {
        t[i].mn = t[i].prop = 0;
    }
}

bool ok (int x) {
    update(1, x, ofs - 1, 0, ofs - 1, 1);
    update(1, cnt - 1, ofs - 1, 0, ofs - 1, -1);
    if (t[1].mn < 0) {
        update(1, x, ofs - 1, 0, ofs - 1, -1);
        update(1, cnt - 1, ofs - 1, 0, ofs - 1, +1);
        return 0;
    }
    return 1;
}

int main () {
    cin >> tt;
    while (tt--) {
        cin >> n;
        tour();
        llint sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> pi[i].second >> pi[i].first;
            sum += pi[i].first;
        }
        sort(pi, pi + n);
        cnt = n;
        for (int i = n-1; i >= 0; i--) {
            if (ok(pi[i].second)) sum -= pi[i].first, cnt--;
        }
        cout << sum << endl;
    }
    return 0;
}