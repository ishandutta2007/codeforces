#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, q, ofs = 1;
int a[MAXN];
int t[MAXN*4], prop[MAXN*4];

void propagate (int x) {
    if (prop[x] == 0) return;
    if (x < ofs) {
        t[2*x] = max(t[2*x], t[x]);
        t[2*x+1] = max(t[2*x+1], t[x]);
        prop[2*x] = prop[2*x+1] = 1;
        t[x] = 0;
    }
    prop[x] = 0;
}

void build () {
    while (ofs < n) ofs *= 2;
    for (int i=0; i<n; i++) {
        t[i + ofs] = a[i];
    }
}

void update1 (int x, int from, int to, int low, int high, int val) {
    propagate(x);
    if (from <= low && high <= to) {
        t[x] = max(t[x], val);
        prop[x] = 1;
        propagate(x);
        return;
    }
    if (to < low || high < from) return;
    update1(2*x, from, to, low, (low + high)/2, val);
    update1(2*x+1, from, to, (low + high)/2+1, high, val);
}

void update2 (int x, int from, int to, int low, int high, int val) {
    propagate(x);
    if (from <= low && high <= to) {
        t[x] = val;
        return;
    }
    if (to < low || high < from) return;
    update2(2*x, from, to, low, (low + high)/2, val);
    update2(2*x+1, from, to, (low + high)/2+1, high, val);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    build();
    cin >> q;
    for (int i=0; i<q; i++) {
        int tip;
        cin >> tip;
        if (tip == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            update2(1, p, p, 0, ofs-1, x);
        } else {
            int x;
            cin >> x;
            update1(1, 0, n-1, 0, ofs-1, x);
        }
    }
    for (int i=1; i<ofs; i++) {
        propagate(i);
    }
    for (int i=0; i<n; i++) {
        cout << t[i + ofs] << " ";
    }
    return 0;
}