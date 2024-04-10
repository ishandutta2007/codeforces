#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct pt {
    int x = 0, y = 0, z = 0, i = 0;
    bool operator < (const pt& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        if (y != rhs.y) return y < rhs.y;
        return z < rhs.z;

    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pt> p(n + 2);
    vector<int> l(n + 2), r(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].i = i;
    }
    sort(p.begin() + 1, p.begin() + n + 1);
    for (int i = 0; i <= n + 1; ++i) {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    vector<pii> ans;
    for (int i = r[0]; i != n + 1; ) {
        if (r[i] != n + 1 && p[r[i]].x == p[i].x && p[r[i]].y == p[i].y) {
            ans.emplace_back(p[i].i, p[r[i]].i);
            int le = l[i];
            int ri = r[r[i]];
            r[le] = ri;
            l[ri] = le;
            i = ri;
        } else {
            i = r[i];
        }
    }
    for (int i = r[0]; i != n + 1; ) {
        if (r[i] != n + 1 && p[r[i]].x == p[i].x) {
            ans.emplace_back(p[i].i, p[r[i]].i);
            int le = l[i];
            int ri = r[r[i]];
            r[le] = ri;
            l[ri] = le;
            i = ri;
        } else {
            i = r[i];
        }
    }

    for (int i = r[0]; i != n + 1; ) {
        ans.emplace_back(p[i].i, p[r[i]].i);
        int le = l[i];
        int ri = r[r[i]];
        r[le] = ri;
        l[ri] = le;
        i = ri;
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}