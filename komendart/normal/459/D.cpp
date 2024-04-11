#include <bits/stdc++.h>

using namespace std;

vector<int> tree;

void inc(int p, int v) {
    for (int i = p; i < tree.size(); i |= i + 1) {
        tree[i] += v;
    }
}

int get(int p) {
    int result = 0;
    for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
        result += tree[i];
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> pref(n), suf(n);
    unordered_map<int, int> num;
    for (int i = 0; i < n; i++) {
        if (num.find(a[i]) == num.end()) pref[i] = 1;
        else pref[i] = pref[num[a[i]]] + 1;
        num[a[i]] = i;
    }
    num.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (num.find(a[i]) == num.end()) suf[i] = 1;
        else suf[i] = suf[num[a[i]]] + 1;
        num[a[i]] = i;
    }

    tree.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        inc(suf[i], 1);
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        inc(suf[i], -1);
        result += get(pref[i] - 1);
    }
    printf("%I64d\n", result);
}