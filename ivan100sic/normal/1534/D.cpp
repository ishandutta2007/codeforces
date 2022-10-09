// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;

vector<int> ask(int x) {
    x++;
    cout << "? " << x << '\n' << flush;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    return a;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    auto a0 = ask(0);
    int e0 = count_if(a0.begin(), a0.end(), [](int x) { return x % 2 == 0; });
    int o0 = n - e0;
    int r = 0;
    if (o0 + 1 < e0) {
        r = 1;
    }

    vector<pair<int, int>> ans;
    for (int i=0; i<n; i++) {
        if (a0[i] % 2 == r) {
            auto ai = i == 0 ? a0 : ask(i);
            for (int j=0; j<n; j++) {
                if (ai[j] == 1) {
                    ans.emplace_back(i, j);
                }
            }
        }
    }

    cout << "!\n";
    for (auto [x, y] : ans) {
        cout << x+1 << ' ' << y+1 << '\n';
    }
    cout << flush;
}