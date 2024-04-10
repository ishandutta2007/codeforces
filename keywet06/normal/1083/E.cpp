#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct CHT {
    vector<long long> a, b;
    double cross(int i, int j, int k) {
        return 1.d * (a[j] - a[i]) * (b[k] - b[i]) -
               1.d * (a[k] - a[i]) * (b[j] - b[i]);
    }
    void add(long long A, long long B) {
        a.push_back(A);
        b.push_back(B);
        while (a.size() > 2 &&
               cross(a.size() - 3, a.size() - 2, a.size() - 1) <= 0) {
            a.erase(a.end() - 2);
            b.erase(b.end() - 2);
        }
    }
    long long query(long long x) {
        if (a.empty()) return (long long)1e18;
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long f1 = a[mid] * x + b[mid];
            long long f2 = a[mid + 1] * x + b[mid + 1];
            if (f1 > f2) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return a[l] * x + b[l];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long ans = 0;
    int n;
    cin >> n;
    vector<tuple<long long, long long, long long>> a;
    for (int i = 0; i < n; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        a.emplace_back(x, y, z);
    }
    sort(a.begin(), a.end());
    CHT hull;
    hull.add(0, 0);
    for (auto [x, y, z] : a) {
        long long tmp = x * y - z - hull.query(y);
        ans = max(ans, tmp);
        hull.add(x, -tmp);
    }
    cout << ans;
    return 0;
}