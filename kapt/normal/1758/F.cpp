#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int arr[MAXN];

int tree[MAXN * 4];

void pull(int v) {
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tree[v] = 1;
        return;
    }
    int vm = (vl + vr) / 2;
    build(v * 2, vl, vm);
    build(v * 2 + 1, vm, vr);
    pull(v);
}

void update(int v, int vl, int vr, int ind) {
    if (ind >= vr || ind < vl) return;
    if (vr - vl == 1) {
        tree[v] *= -1;
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2, vl, vm, ind);
    update(v * 2 + 1, vm, vr, ind);
    pull(v);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l >= vr || r <= vl) return 0;
    if (l <= vl && r >= vr) return tree[v];
    int vm = (vl + vr) / 2;
    int res1 = get(v * 2, vl, vm, l, r);
    int res2 = get(v * 2 + 1, vm, vr, l, r);
    return res1 + res2;
}

int main() {
    int n;
    cin >> n;
    set<array<int, 2>> seg;
    build(1, 0, MAXN);
    for (int i = 0; i < n; ++i) {
        /// cout << endl;
        int x;
        cin >> x;
        update(1, 0, MAXN, x);
        vector<array<int, 2>> add, del;
        if (arr[x] == 0) {
            arr[x] = 1;
            array<int, 2> el = {x + 2, 0};
            auto it = seg.lower_bound(el);
            int r = -1, l = -1;
            if (it != seg.begin()) {
                it--;
                r = (*it)[1];
                l = (*it)[0];
            }
            bool f = false;
            if (r < x) {
                add.push_back({x, x + 1});
            } else {
                add.push_back({min(x, l), r + 1});
                if (l <= x) {
                    f = true;
                }
                del.push_back({l, r});
            }
            l = add[0][0], r = add[0][1];
            el = {r + 1, 0};
            it = seg.lower_bound(el);
            if (it != seg.end() && (*it)[0] == r + 1) {
                add.pop_back();
                add.push_back({l, (*it)[1]});
                del.push_back(*it);
            }
            if (f) {
                add.back()[1]++;
                l = add[0][0], r = add[0][1];
                el = {r + 1, 0};
                it = seg.lower_bound(el);
                if (it != seg.end() && (*it)[0] == r + 1) {
                    add.pop_back();
                    add.push_back({l, (*it)[1]});
                    del.push_back(*it);
                }
            }
            l = add[0][0], r = add[0][1];
            el = {l, 0};
            it = seg.lower_bound(el);
            if (it != seg.begin()) {
                it--;
                if ((*it)[1] == l - 1) {
                    add.pop_back();
                    add.push_back({(*it)[0], r});
                    del.push_back(*it);
                }
            }
            cout << del.size() << '\n';
            for (auto elem : del) {
                cout << elem[0] << " " << elem[1] << '\n';
                seg.erase(elem);
            }
            cout << add.size() << '\n';
            for (auto elem : add) {
                cout << elem[0] << " " << elem[1] << '\n';
                seg.insert(elem);
            }
        } else {
            arr[x] = 0;
            array<int, 2> el = {x + 1, 0};
            auto it = seg.lower_bound(el);
            it--;
            int l = (*it)[0], r = (*it)[1];
            vector<array<int, 2>> add, del;
            del.push_back({l, r});
            int lb = l, rb = r + 1;
            while (rb - lb > 1) {
                int m = (lb + rb) / 2;
                if (get(1, 0, MAXN, l, m) <= 0) {
                    lb = m;
                } else {
                    rb = m;
                }
            }
            /// cerr << lb << endl;
            if (lb != l) {
                add.push_back({l, lb - 1});
            }
            l = rb;
            lb = l, rb = r + 1;
            while (rb - lb > 1) {
                int m = (lb + rb) / 2;
                if (get(1, 0, MAXN, l, m) <= 0) {
                    lb = m;
                } else {
                    rb = m;
                }
            }
            /// cerr << lb << endl;
            if (lb != l) {
                add.push_back({l, lb - 1});
            }
            l = rb;
            if (l <= r) {
                add.push_back({l, r});
            }
            cout << del.size() << '\n';
            for (auto elem : del) {
                cout << elem[0] << " " << elem[1] << '\n';
                seg.erase(elem);
            }
            cout << add.size() << '\n';
            for (auto elem : add) {
                cout << elem[0] << " " << elem[1] << '\n';
                seg.insert(elem);
            }
        }
    }
    return 0;
}