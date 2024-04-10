#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

vector<int> t, d;

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = l + 1;
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

void push(int v, int l, int r) {
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    t[v] += d[v];
    d[v] = 0;
}
void update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return 0;
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, k;
    cin >> n >> k >> q;
    k--;
    t.resize(8 * n, 0);
    d.resize(8 * n, 0);
    build(0, 0, 2 * n);
    multiset<int> min_pos;
    set<pii> point;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        swap(x, y);
        int z = x + abs(y - k);
        if (point.find({x, y}) == point.end()) {
            min_pos.insert(z);
            point.insert({x, y});
            update(0, 0, 2 * n, 0, z, 1);
        }
        else {
            min_pos.erase(min_pos.find(z));
            point.erase({x, y});
            update(0, 0, 2 * n, 0, z, -1);
        }
        if (min_pos.size() == 0) {
            cout << "0\n";
        }
        else {
            int w = *min_pos.rbegin();
            cout << max(0, get(0, 0, 2 * n, 0, w + 1) - n) << '\n';
        }
    }
}