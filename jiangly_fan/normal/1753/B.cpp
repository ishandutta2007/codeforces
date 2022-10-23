#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto no = [&]() {
        cout << "No";
        exit(0);
    };
    int n, x;
    cin >> n >> x;
    vector<int> c(x + 1);
    for (int i = 0, ai; i < n; i += 1) {
        cin >> ai;
        c[ai] += 1;
    }
    int k = 0;
    for (int i = 1; i <= x; i += 1) {
        if (k % i) no();
        k = k / i + c[i];
    }
    cout << "Yes";
}