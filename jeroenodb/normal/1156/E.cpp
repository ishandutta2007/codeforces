#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], tree[4*N], Pos[N];

long long merge(int x, int y) {
    return max(x, y);
}

void build(int v, int tl, int tr) {
    if (tl == tr)
        tree[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1;
    if (l == tl and r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;

    return merge(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

long long ans = 0;
int n;

bool chk(int val, int l, int r) {
    return (Pos[val] >= l and Pos[val] <= r);
}

void divide_conquer(int l, int r) {
    if (l > r)return;
    int x = a[l];
    int y = a[r];
    int M = query(1, 0, n - 1, l, r);//log
    if (Pos[M] - l <= r - Pos[M]) {//n
        for (int i = l; i < Pos[M]; i++) {
            if (chk(M - a[i], Pos[M], r)) {
                ans++;
            }
        }
    } else {
        for (int i = Pos[M] + 1; i <= r; i++) {//n
            if (chk(M - a[i], l, Pos[M])) {
                ans++;
            }
        }
    }
    divide_conquer(l, Pos[M] - 1);//log
    divide_conquer(Pos[M] + 1, r);//log

}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], Pos[a[i]] = i;
    build(1, 0, n - 1);
    divide_conquer(0, n - 1);
    cout << ans << endl;
}