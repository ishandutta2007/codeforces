#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    a.insert(a.end(), a.begin(), a.end());
    int cur = 0;
    int max = 0;
    for (int c : a) {
        if (c == 1) {
            cur++;
            max = std::max(cur, max);
        } else {
            cur = 0;
        }
    }
    cout << max << '\n';
}