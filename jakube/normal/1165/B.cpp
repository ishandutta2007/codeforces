#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());
    auto it = v.begin();
    int cur = 1;
    int c = 0;
    while (it != v.end()) {
        c++;
        ++it;

        cur++;
        while (it != v.end() && *it < cur)
            ++it;
    }
    cout << c << '\n';
}