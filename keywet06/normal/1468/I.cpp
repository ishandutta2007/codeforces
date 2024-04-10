#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using float32 = long double;
using int64 = long long;

int64 prod(pair<int64, int64>& a, pair<int64, int64>& b) {
    return a.first * b.first + a.second * b.second;
}

int main() {
    int n;
    cin >> n;
    pair<int64, int64> a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    if (a == make_pair(0LL, 0LL) || b == make_pair(0LL, 0LL)) {
        cout << "NO\n";
        return 0;
    }
    while (1) {
        if (a == make_pair(0LL, 0LL) || b == make_pair(0LL, 0LL)) {
            cout << "NO\n";
            return 0;
        }
        if (prod(a, a) > prod(b, b)) {
            swap(a, b);
        }
        int64 K = prod(a, b);
        int64 s = prod(a, a);
        K /= s;
        int64 res = (1LL << 60);
        pair<int64, int64> t;
        for (int64 i = K - 2; i <= K + 2; i++) {
            pair<int64, int64> X =
                make_pair(b.first - a.first * i, b.second - a.second * i);
            if (res > prod(X, X)) {
                t = X;
                res = prod(X, X);
            }
        }
        if (b == t) {
            break;
        }
        b = t;
    }
    if (a.first < 0) {
        a.first *= -1;
        a.second *= -1;
    }
    if (b.first < 0) {
        b.first *= -1;
        b.second *= -1;
    }
    if (a.first * b.second - b.first * a.second < 0) {
        swap(a, b);
    } else if (a.first * b.second - b.first * a.second == 0) {
        cout << "NO\n";
        return 0;
    }
    swap(a, b);
    int64 res = 0;
    for (int64 i = 0; i < a.first + b.first; i++) {
        float32 U, L;
        int64 u, l;
        if (i < a.first) {
            U = (float32)i * (a.second) / (float32)a.first;
            u = floor(U);
            for (int64 k = u - 5; k <= u + 5; k++) {
                if (a.first * k <= i * a.second) {
                    u = k;
                }
            }
        } else {
            U = (float32)(i - a.first) * (b.second) / (float32)b.first;
            u = floor(U);
            for (int64 k = u - 5; k <= u + 5; k++) {
                if (k * b.first < (i - a.first) * (b.second)) {
                    u = k;
                }
            }
            u += a.second;
        }
        if (i < b.first) {
            L = (float32)i * (b.second) / (float32)b.first;
            l = ceil(L);
            for (int64 k = l - 5; k <= l + 5; k++) {
                if (k * b.first < i * (b.second)) {
                    l = k + 1;
                }
            }
        } else {
            L = (float32)(i - b.first) * (a.second) / (float32)a.first;
            l = ceil(L);
            for (int64 k = l - 5; k <= l + 5; k++) {
                if (k * a.first <= (i - b.first) * (a.second)) {
                    l = k + 1;
                }
            }
            l += b.second;
        }
        res += u - l + 1;
    }
    if (n == res) {
        cout << "YES\n";
        vector<pair<int64, int64> > ans;
        for (int64 i = 0; i < a.first + b.first; i++) {
            float32 U, L;
            int64 u, l;
            if (i < a.first) {
                U = (float32)i * (a.second) / (float32)a.first;
                u = floor(U);
                for (int64 k = u - 5; k <= u + 5; k++) {
                    if (a.first * k <= i * a.second) {
                        u = k;
                    }
                }
            } else {
                U = (float32)(i - a.first) * (b.second) / (float32)b.first;
                u = floor(U);
                for (int64 k = u - 5; k <= u + 5; k++) {
                    if (k * b.first < (i - a.first) * (b.second)) {
                        u = k;
                    }
                }
                u += a.second;
            }
            if (i < b.first) {
                L = (float32)i * (b.second) / (float32)b.first;
                l = ceil(L);
                for (int64 k = l - 5; k <= l + 5; k++) {
                    if (k * b.first < i * (b.second)) {
                        l = k + 1;
                    }
                }
            } else {
                L = (float32)(i - b.first) * (a.second) / (float32)a.first;
                l = ceil(L);
                for (int64 k = l - 5; k <= l + 5; k++) {
                    if (k * a.first <= (i - b.first) * (a.second)) {
                        l = k + 1;
                    }
                }
                l += b.second;
            }
            for (int j = l; j <= u; j++) {
                ans.push_back(make_pair(i, j));
            }
        }
        for (auto x : ans) {
            cout << x.first << " " << x.second << "\n";
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}