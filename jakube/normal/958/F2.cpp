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

    int best = std::numeric_limits<int>::max();
    int sum = accumulate(k.begin(), k.end(), 0);
    int idx = 0;
    int good = 0;
    for (int x : k)
        good += !x;

    for (int i = 0; i < n; i++) {
        k[v[i]]--;
        if (k[v[i]] == 0)
            good++;

        while (good == m) {
            best = min(best, i - idx + 1 - sum);
            if (++k[v[idx++]] > 0)
                good--;
        }
    }

    cout << (best == std::numeric_limits<int>::max() ? -1 : best) << '\n';
}