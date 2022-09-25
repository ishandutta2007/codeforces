#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        cout << ranges::max_element(a) - a.begin() + 1 << " " << ranges::min_element(a) - a.begin() + 1 << "\n";
    }
    return 0;
}