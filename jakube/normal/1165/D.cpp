#include <bits/stdc++.h>
using namespace std;

std::vector<int> largest;

void computePrimesLargest(int n) {
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

long long test(vector<int> xs, vector<int> divs) {
    map<int, int> cnt;
    for (int x : xs) {
        while (x > 1) {
            int p = largest[x];
            int c = 0;
            while (largest[x] == p) {
                c++;
                x /= p;
            }
            cnt[p] += c;
        }
    }

    long long divisors = 1;
    for (auto [p, c] : cnt) {
        divisors *= 1 + c;
    }
    if (divs.size() + 2 == divisors) {
        long long res = xs[0] * (long long)xs[1];
        for (int x : divs) {
            if (res % x)
                return -1;
        }
        return res;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    computePrimesLargest(1'000'000);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& x : v)
            cin >> x;
        sort(v.begin(), v.end());
        vector<int> xs;
        xs.push_back(v[0]);
        xs.push_back(v.back());
        cout << test(xs, v) << '\n';
    }
}