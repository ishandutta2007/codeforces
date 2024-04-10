#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<long long>> b(60);

bool f(vector<long long> & a) {
    vector<int> used(60, 0);

    long long all = 0;
    for (auto bs : b)
        for (auto x : bs)
            all ^= x;

    int idx = n - 1;
    while (idx >= 0) {
        for (int i = 0; i <= 60; i++) {
            if (i == 60) {
                return false;
            }
            if ((all & (1LL << i)) && (int)b[i].size() > used[i]) {
                a[idx] = b[i][used[i]++];
                all ^= a[idx];
                idx--;
                break;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::random_device rd;
    std::mt19937 g(rd());

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        for (int k = 59; k >= 0; k--) {
            if (x & (1LL << k)) {
                b[k].push_back(x);
                break;
            }
        }
    }

    vector<long long> a(n);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
    do {
        for (auto& x : b) {
            shuffle(x.begin(), x.end(), g);
        }

        if (f(a)) {
            cout << "Yes" << '\n';
            long long y = 0;
            for (auto x : a) {
                // y ^= x;
                cout << x << ' ';
            }
            cout << '\n';
            return 0;
        }


        t2 = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
    } while (duration.count() <= 1'500'000);

    cout << "No" << '\n';
}