#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(12);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int allnumber = n * (n - 1) / 2;
    allnumber *= allnumber * allnumber;

    unordered_map<int, int> d;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            d[abs(a[i] - a[j])]++;;
        }
    }

    int cnt = n * (n - 1) / 2;
    int number = 0;
    for (int sum = 1; sum <= 5000; sum++) {
        cnt -= d[sum];
        for (int i = 1; i <= sum; i++) {
            int j = sum - i;
            number += d[i] * d[j] * cnt;
        }
    }

    cout << number / (long double) allnumber << '\n';
}