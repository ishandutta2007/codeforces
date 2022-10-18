#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;

long long diff(int A, long long B) {
    // from B-1 to B
    return A - 3*B*(B+1) - 1;
}

long long fill_b(long long limit) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int L = 0;        // possible (difference is greater)
        int R = a[i] + 1; // not possible
        while (L + 1 < R) {
            long long B = (L + R) / 2;
            if (diff(a[i], B) >= limit)
                L = B;
            else
                R = B;
        }
        total += L;
        b[i] = L;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    long long k;
    cin >> k;
    a.resize(n);
    b.resize(n);
    for (auto& x : a)
        cin >> x;

    /* i128 maxx = 1'000'000'000; */
    // diff is a - 3x^2 - 3x - 1
    // >= 1 - 3*maxx^2 -3*maxx -1 >= -3*maxx(maxx+1)
    // <= maxx - 0 - a - 1
    long long L = std::numeric_limits<long long>::min() / 4 * 3.5; // not possible (with 0)
    long long R = std::numeric_limits<int>::max();  // possible (to many)
    while (L + 1 < R) {
        long long M = L + (R - L) / 2;
        long long cnt = fill_b(M);
        if (cnt > k)
            L = M;
        else
            R = M;
    }

    long long cnt = fill_b(R);

    set<pair<long long, int>> s;
    for (int i = 0; i < n; i++) {
        if (b[i] < a[i]) {
            s.insert({diff(a[i], b[i]+1), i});
        }
    }

    while (cnt < k) {
        auto it = --s.end();
        auto [val, i] = *it;
        s.erase(it);
        b[i]++;
        cnt++;

        if (b[i] < a[i]) {
            s.insert({diff(a[i], b[i]+1), i});
        }
    }

    for (auto x : b) {
        cout << x << ' ';
    }
    cout << '\n';
}