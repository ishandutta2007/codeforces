#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 200222;
ll ans[N];

int main() {
    int n, b;
    scanf("%d%d", &n, &b);
    memset(ans, -1, sizeof(ans));

    queue<pair<int, int>> q;
    ll can = 0;
    for (int i = 0; i < n; ++i) {
        int t, d;
        scanf("%d%d", &t, &d);
        
        while (!q.empty() && can + q.front().second <= t) {
            can += q.front().second;
            ans[q.front().first] = can;
            q.pop();
        }

        if (int(q.size()) <= b) {
            q.emplace(i, d);
            if (q.size() == 1) can = max(can, ll(t));
        }
    }
    while (!q.empty()) {
        can += q.front().second;
        ans[q.front().first] = can;
        q.pop();
    }

    for (int i = 0; i < n; ++i) {
        printf("%I64d ", ans[i]);
    }
    cout << endl;

    return 0;
}