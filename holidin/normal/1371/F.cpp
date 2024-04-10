#include <bits/stdc++.h>
//#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 12;
bool debag = false;

struct vertex {
    int maxcnt, leftcnt, rightcnt, sz, leftsz, rightsz;
    char typeleft, typeright;
    vertex(char type = '<') {
        maxcnt = leftcnt = rightcnt = sz = leftsz = rightsz = 1;
        typeleft = typeright = type;
    }
};

vertex m[2][N];

vertex merg(const vertex& l, const vertex& r) {
    vertex u;
    u.maxcnt = max(l.maxcnt, r.maxcnt);
    if (l.typeleft == r.typeleft && l.leftsz == l.sz) {
        u.leftsz = l.sz + r.leftsz;
    } else
        u.leftsz = l.leftsz;
    if (r.typeright == l.typeright && r.rightsz == r.sz) {
        u.rightsz = r.sz + l.rightsz;
    } else
        u.rightsz = r.rightsz;
    u.typeleft = l.typeleft;
    u.typeright = r.typeright;
    u.sz = l.sz + r.sz;
    if (debag)
        cout << u.maxcnt  << ' ' << l.typeright << ' '  << r.typeright << endl;
    if (l.typeright == '>' && r.typeleft == '<') {
        u.maxcnt = max(u.maxcnt, l.rightsz + r.leftsz);
        if (debag)
            exit(1);
        if (l.sz == l.leftsz)
            u.leftcnt = l.sz + r.leftsz;
        else
            u.leftcnt = l.leftcnt;
        if (r.sz == r.rightsz)
            u.rightcnt = r.sz + l.rightsz;
        else
            u.rightcnt = r.rightcnt;
    }
    if (l.typeright == '<' && r.typeleft == '<') {
        u.maxcnt = max(u.maxcnt, l.rightcnt + r.leftsz);
        if (l.sz == l.leftcnt)
            u.leftcnt = l.sz + r.leftsz;
        else
            u.leftcnt = l.leftcnt;
        if (r.sz == r.leftsz)
            u.rightcnt = l.rightcnt + r.sz;
        else
            u.rightcnt = r.rightcnt;
    }
    if (l.typeright == '>' && r.typeleft == '>') {
        u.maxcnt = max(u.maxcnt, l.rightsz + r.leftcnt);
        if (r.sz == r.rightcnt)
            u.rightcnt = r.sz + l.rightsz;
        else
            u.rightcnt = r.rightcnt;
        if (l.sz == l.rightsz)
            u.leftcnt = l.sz + r.leftcnt;
        else
            u.leftcnt = l.leftcnt;
    }
    if (l.typeright == '<' && r.typeleft == '>') {
        u.rightcnt = r.rightcnt;
        u.leftcnt = l.leftcnt;
    }
    u.maxcnt = max(u.maxcnt, max(u.leftcnt, u.rightcnt));
    return u;
}

bool ninv[N];

void push(int v) {
    if (ninv[v]) {
        ninv[2*v + 1] ^= 1;
        ninv[2*v + 2] ^= 1;
        swap(m[0][2*v + 1], m[1][2*v + 1]);
        swap(m[0][2*v + 2], m[1][2*v + 2]);
    }
    ninv[v] = 0;
}

void recalc(int v) {
    for (int i = 0; i < 2; ++i)
        m[i][v] = merg(m[i][2*v + 1], m[i][2*v + 2]);
}

vertex get(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r) {
        return m[0][v];
    } else {
        push(v);
        //recalc(v);
        if (l >= (vl + vr) / 2)
            return get(2*v + 2, (vl + vr) / 2, vr, l, r);
        if (r <= (vl + vr) / 2)
            return get(2*v + 1, vl, (vl + vr) / 2, l, r);
        return merg(get(2*v + 1, vl, (vl + vr) / 2, l, r), get(2*v + 2, (vl + vr) / 2, vr, l, r));
    }

}

void invert(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r) {
        ninv[v] ^= 1;
        swap(m[0][v], m[1][v]);
    } else if (l >= vr || vl >= r)
            return;
        else {
            push(v);
            invert(2*v + 1, vl, (vl + vr) / 2, l, r);
            invert(2*v + 2, (vl + vr) / 2, vr, l, r);
            recalc(v);
        }
}

void build(int v, int vl, int vr, string& s) {
    if (vl > s.size())
        return;
    if (vr - vl > 1) {
        build(2*v + 1, vl, (vl + vr) / 2, s);
        build(2*v + 2, (vl + vr) / 2, vr, s);
        recalc(v);
    } else {
        m[0][v] = vertex(s[vl  - 1]);
        m[1][v] = vertex(s[vl - 1] == '<' ? '>' : '<');
    }
}


void run() {
    int n, x, i, j, xmin = 1e9 + 1, q, l, r;
    string s;
    cin >> n >> q;
    cin >> s;
    int v = 1;
    while (v < n)
        v *= 2;
    build(0, 1, v + 1, s);
    while (q--) {
        cin >> l >> r;
        invert(0, 1, v + 1, l, r + 1);
        cout << get(0, 1, v + 1, l, r + 1).maxcnt << "\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    run();
}