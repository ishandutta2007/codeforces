#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    vector<int> k(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
    }

    int sum = accumulate(k.begin(), k.end(), 0);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        k[v[i]]--;
        sum--;
        if (sum < 0) {
            k[v[idx++]]++;
            sum++;
        }

        if (all_of(k.begin(), k.end(), [](int x){return !x;})) {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';
}