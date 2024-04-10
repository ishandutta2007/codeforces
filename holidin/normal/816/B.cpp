#include <bits/stdc++.h>
using namespace std;

const int N = 420000;

int main() {
    vector <pair<int, int> > m;
    int i, j, n, k, q, a, b, l, r, x, pr[N];
    cin >> n >> k >> q;
    for (i = 1; i <= n; i++) {
        cin >> l >> r;
        m.push_back(make_pair(l, 1));
        m.push_back(make_pair(r + 1, -1));
    }
    sort(m.begin(), m.end());
    j = 0;
    x = 0;
    pr[0] = 0;
    for (i = 1; i < N; i++) {
        while ((j < m.size()) && (m[j].first == i)) {
            x += m[j].second;
            j++;
        }
        if (x >= k)
            pr[i] = pr[i - 1] + 1;
        else
            pr[i] = pr[i - 1];
    }
    for (i = 1; i <= q; i++) {
        cin >> a >> b;
        cout << pr[b] - pr[a - 1] << endl;
    }
}