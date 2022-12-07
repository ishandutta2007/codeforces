#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> station(n);
    while (m--) {
        int a, b; scanf("%d%d", &a, &b);
        --a; --b;
        if (b >= a) station[a].push_back(b - a);
        else station[a].push_back(n + b - a);
    }
    for (int i = 0; i < n; ++i) {
        sort(begin(station[i]), end(station[i]));
        reverse(begin(station[i]), end(station[i]));
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (station[j].empty()) continue;
            int to_here = j - i;
            if (to_here < 0) to_here += n;
            ans = max(ans, to_here + int(station[j].size() - 1) * n + *station[j].rbegin());
        }
        printf("%d ", ans);
    }
    cout << endl;

    return 0;
}