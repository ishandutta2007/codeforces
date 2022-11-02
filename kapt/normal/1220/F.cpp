#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int tree[MAXN], add[MAXN];
int arr[MAXN];

void pull(int v) {
    int v1 = v * 2;
    int v2 = v * 2 + 1;
    tree[v] = max(tree[v1] + add[v1], tree[v2] + add[v2]);
}

void push(int v) {
    int v1 = v * 2;
    int v2 = v * 2 + 1;
    add[v1] += add[v];
    add[v2] += add[v];
    tree[v] += add[v];
    add[v] = 0;
}

int get(int v, int l, int r, int vl, int vr) {
    // cout << v << endl;
    /*if (v == 1) {
        cout << l << " " << r << endl;
    }
    cout << v << " " << vl << " " << vr << endl;*/
    push(v);
    if (l >= vr || r <= vl) {
        return 0;
    }
    if (l <= vl && r >= vr) {
        return tree[v];
    }
    int v1 = v * 2;
    int v2 = v * 2 + 1;
    int vm = (vl + vr) / 2;
    int res1 = get(v1, l, r, vl, vm);
    int res2 = get(v2, l, r, vm, vr);
    // cout << v << " | " << res1 << " | " << res2 << endl;
    return max(res1, res2);
}

void update(int v, int l, int r, int del, int vl, int vr) {
    // cout << v << " " << vl << " " << vr << endl;
    // cout << " " << v << endl;
    push(v);
    if (l >= vr || r <= vl) {
        return;
    }
    if (l <= vl && r >= vr) {
        add[v] += del;
        return;
    }
    int v1 = v * 2;
    int v2 = v * 2 + 1;
    int vm = (vl + vr) / 2;
    update(v1, l, r, del, vl, vm);
    update(v2, l, r, del, vm, vr);
    pull(v);
    // cout << "u " << v << " " << tree[v] << " " << l << " " << r << " " << del << endl;
}

void calc(const vector<int> &arr, vector<int> &ans) {
    int n = arr.size();
    ans.resize(n, 0);
    fill(tree, tree + 4 * n, 0);
    fill(add, add + 4 * n, 0);
    vector<pair<int, int>> st;
    vector<int> lef(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.back().first > arr[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            lef[i] = st.back().second;
        }
        st.push_back({arr[i], i});
    }
    for (int i = 0; i < n; ++i) {
        // cout << arr[i] << " ";
        int x = lef[i];
        // cout << x << " ";
        int k = get(1, x, x + 1, 0, n);
        // cout << k << " ";
        // cout << endl;
        update(1, x + 1, i, 1, 0, n);
        update(1, i, i + 1, k + 1, 0, n);
        // cout << get(1, i, i + 1, 0, n) << " ";
        ans[i] = get(1, 0, i + 1, 0, n);
        // cout << endl;
        /*for (int j = 0; j < 4 * n; ++j) {
            cout << "(" << tree[j] << " " << add[j] << ") ";
        }
        cout << endl;*/
        // cout << k + 1 << " ";
        // cout << ans[i] << ", ";
    }
    // cout << endl;
}

main() {
    int n;
    cin >> n;
    int imin = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < arr[imin]) {
            imin = i;
        }
    }
    vector<int> a;
    for (int i = (imin + 1) % n; i != imin; i = (i + 1) % n) {
        a.push_back(arr[i]);
    }
    vector<int> pref, suf;
    calc(a, pref);
    reverse(a.begin(), a.end());
    calc(a, suf);
    /*for (auto elem : pref) {
        cout << elem << " ";
    }
    cout << endl;
    for (auto elem : suf) {
        cout << elem << " ";
    }
    cout << endl;*/
    int res = 1e9;
    int resi = -1;
    for (int i = 0; i < n; ++i) {
        int j1 = i - 1;
        int j2 = n - 1 - i - 1;
        if (j1 == -1) {
            j1 = 0;
        } else {
            j1 = pref[j1];
        }
        if (j2 == -1) {
            j2 = 0;
        } else {
            j2 = suf[j2];
        }
        if (max(j1, j2) < res) {
            res = max(j1, j2);
            resi = i;
        }
    }
    cout << res + 1 << " " << (imin + resi + 1) % n;
    return 0;
}