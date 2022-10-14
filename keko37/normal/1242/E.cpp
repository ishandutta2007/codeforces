#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int n, siz, cnt;
int a[MAXN], suf[MAXN], lef[MAXN], rig[MAXN];
pair <int, int> p[MAXN];
set < pair <int, int> > st;
vector <int> v[MAXN];

void init_cyc (int x) {
    siz = x; cnt = x;
    st.insert({1, x});
    for (int i = 1; i <= x; i++) {
        if (i != x) st.insert({i, i + 1});
        v[p[0].second].push_back(i);
        if (i == 1) lef[i] = x; else lef[i] = i - 1;
        if (i == x) rig[i] = 1; else rig[i] = i + 1;
    }
}

void spoji (int a, int b) {
    rig[a] = b; lef[b] = a;
    st.insert({min(a, b), max(a, b)});
}

void add (int ind, int len, int k) {
    int lo = 1, hi = 1;
    for (int i = 0; i < k; i++) hi = rig[hi];
    if (k == len - 1 && st.find({min(lo, hi), max(lo, hi)}) != st.end()) lo = rig[lo], hi = rig[hi];

    int curr = hi;
    while (curr != lo) {
        v[ind].push_back(curr);
        curr = lef[curr];
    }
    for (auto x : v[ind]) {
        if (x == hi) continue;
        rig[lef[x]] = rig[x];
        lef[rig[x]] = lef[x];
        siz--;
    }

    int novi = lo;
    for (int i = 1; i < len - k; i++) {
        v[ind].push_back(novi);
        cnt++; siz++;
        spoji(novi, cnt);
        novi = cnt;
    }
    v[ind].push_back(novi);
    spoji(novi, hi);
}

void rjesi () {
    for (int i = 1; i < n; i++) {
        int ind = p[i].second;
        if (siz - suf[i] <= 2) {
            int val = siz + a[i] - 2 - suf[i + 1];
            if (val <= 2) {
                add(ind, a[i], 1);
            } else {
                int k = (val - 3) / 2 + 1;
                add(ind, a[i], k);
            }
        } else {
            add(ind, a[i], a[i] - 1);
        }
    }
}

void ispis () {
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        for (auto x : v[i]) cout << x << " ";
        cout << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p, p + n);
    reverse(p, p + n);
    for (int i = n-1; i >= 0; i--) {
        a[i] = p[i].first;
        suf[i] = suf[i + 1] + a[i] - 2;
    }
    init_cyc(a[0]);
    rjesi();
    ispis();
    return 0;
}