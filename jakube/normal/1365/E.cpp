#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto& x : v)
        cin >> x;
    
    long long ma = 0;
    for (auto x : v) {
        for (auto y : v) {
            for (auto z : v) {
                ma = max(ma, x | y | z);
            }
        }
    }
    cout << ma << '\n';
}