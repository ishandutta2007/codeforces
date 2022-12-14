#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int fen[600005];
int mn[300005], mx[300005];

void update(int i, int x) {
    while (i <= 600004) {
        fen[i] += x;
        i += i & -i;
    }
}

int sum(int i) {
    int ans = 0;
    while (i) {
        ans += fen[i];
        i -= i & -i;
    }
    return ans;
}

int idx[300005];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        mn[i] = mx[i] = i;
        update(idx[i] = m + i, 1);
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        mn[x] = 1;
        mx[x] = max(mx[x], sum(idx[x]));
        update(idx[x], -1);
        update(idx[x] = m - i + 1, 1);
    }
    for (int i = 1; i <= n; ++i) {
        mx[i] = max(mx[i], sum(idx[i]));
        cout << mn[i] << ' ' << mx[i] << '\n';
    }
}