#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int f(int l, int r) {
    if (is_sorted(v.begin() + l, v.begin() + r))
        return r - l;

    int m = (l + r) / 2;
    return max(f(l, m), f(m, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v.resize(n);
    for (auto& x : v)
        cin >> x;
    cout << f(0, n) << endl;
}