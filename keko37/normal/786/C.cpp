#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, cnt = 1, ofs = 1;
int t[80 * MAXN], lef[80 * MAXN], rig[80 * MAXN], root[MAXN], a[MAXN], ind[MAXN];
vector < pair <int, int> > v;

void build (int len) {
    if (len == 1) return;
    int curr = cnt;
    cnt++; lef[curr] = cnt;
    build(len/2);
    cnt++; rig[curr] = cnt;
    build(len/2);
}

int update (int cvor, int pos, int low, int high) {
    if (low == pos && high == pos) {
        cnt++;
        t[cnt] = 1;
        return cnt;
    }
    cnt++;
    int curr = cnt;
    int mid = (low + high) / 2;
    if (pos <= mid) {
        lef[curr] = update(lef[cvor], pos, low, mid);
        rig[curr] = rig[cvor];
    } else {
        lef[curr] = lef[cvor];
        rig[curr] = update(rig[cvor], pos, mid+1, high);
    }
    t[curr] = t[lef[curr]] + t[rig[curr]];
    return curr;
}

void precompute () {
    sort(v.begin(), v.end());
    root[0] = 1;
    build(ofs);
    for (int i=0; i<v.size(); i++) {
        root[i+1] = update(root[i], v[i].second-1, 0, ofs-1);
    }
}

int upit (int x, int from, int to, int low, int high) {
    if (to < low || high < from) return 0;
    if (from <= low && high <= to) return t[x];
    return upit(lef[x], from, to, low, (low + high)/2) + upit(rig[x], from, to, (low + high)/2+1, high);
}

int bs (int x, int low, int high, int k) {
    if (low == high) return low;
    if (t[lef[x]] <= k) return bs(rig[x], (low+high)/2+1, high, k - t[lef[x]]);
    return bs(lef[x], low, (low+high)/2, k);
}

int nxt (int x, int k) {
    int val = lower_bound(v.begin(), v.end(), make_pair(x, 0)) - v.begin();
    int ost = 0;
    if (x > 1) ost = upit(root[val], 0, x-2, 0, ofs-1);
    k += ost;
    if (t[root[val]] <= k) return n+1;
    return bs(root[val], 0, ofs-1, k) + 1;
}

int calc (int k) {
    int pos = 1, cnt = 0;
    while (1) {
        pos = nxt(pos, k);
        cnt++;
        if (pos == n+1) return cnt;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (ofs < n) ofs *= 2;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        v.push_back(make_pair(ind[a[i]], i));
        ind[a[i]] = i;
    }
    precompute();
    for (int i=1; i<=n; i++) {
        cout << calc(i) << " ";
    }
    return 0;
}