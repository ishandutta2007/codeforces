#include <bits/stdc++.h>
using namespace std;

long long power(long long a, int e, int mod) {
    long long result = 1;
    while (e) {
        if (e & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        e >>= 1;
    }
    return result;
}

long long inverse(long long a, int mod) {
    return power(a, mod-2, mod);
}

bool contains(set<int> &s, int val, int elem, int m) {
    if (val < 0) val += m;
    if (val >= m) val -= m;
    if (val < elem) return false;
    return s.count(val) > 0;
}

pair<int, int> solve(vector<int> a, int n, int m) {
    if (n == 1) {
        return {a.front(), 1};
    }
    if (n == 0) {
        return {0, 1};
    }

    int diff = a[1] - a[0];

    int cnt = 0;
    set<int> s(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cnt += contains(s, a[i] + diff, a[i], m);
        cnt += contains(s, a[i] - diff, a[i], m);
    }

    int k = n - cnt;
    int d = ((long long)diff * inverse(k, m)) % m;

    // check
    cnt = 1;
    int cur = a[0];
    while (s.count((cur + d) % m)) {
        cur = (cur + d) % m;
        cnt++;
    }
    cur = a[0];
    while (s.count((cur - d + m) % m)) {
        cur = (cur - d + m) % m;
        cnt++;
    }

    if (cnt == n) {
        return {cur, d};
    } else {
        return {-1, -1};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int m, n;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    if (2*n < m) {
        auto res = solve(a, n, m);
        if (res.first >= 0) 
            cout << res.first << ' ' << res.second << endl;
        else 
            cout << -1 << endl;
    } else {
        vector<int> b;
        b.reserve(m - n);
        int index = 0;
        for (int i = 0; i < m; i++) {
            if (a[index] == i) index++;
            else b.push_back(i); 
        }

        auto res = solve(b, b.size(), m);
        if (res.first == -1) {
            cout << -1 << endl;
        } else {
            cout << (res.first + (long long)(m - n) * (long long)res.second) % m << ' ' << res.second << endl;
        }
    }

    return 0;
}