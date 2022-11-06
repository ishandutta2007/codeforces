#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> l(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    unordered_map<int, int> prev;
    unordered_map<int, int> next;
    prev.rehash(3e5);
    next.rehash(3e5);
    prev[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto j: prev) {
            next[j.first] = INF;
            next[gcd(j.first, l[i])] = INF;
        }
        for (auto j: prev) {
            next[j.first] = min(next[j.first], prev[j.first]);
            int t = gcd(j.first, l[i]);
            next[t] = min(next[t], j.second + c[i]);
        }
        next.swap(prev);
    }

    if (prev.find(1) == prev.end()) {
        cout << -1 << '\n';
    } else {
        cout << prev[1] << '\n';
    }
}