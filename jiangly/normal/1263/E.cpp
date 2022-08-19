
#include <bits/stdc++.h>
using namespace std;
struct Set {
    int mn, mx;
    int cnt[4000001];
    Set() : mn(0), mx(0), cnt{} {cnt[2000000] = 10000000;}
    void insert(int x) {
        ++cnt[x + 2000000];
        mn = min(mn, x);
        mx = max(mx, x);
    }
    void erase(int x) {
        --cnt[x + 2000000];
        while (cnt[mn + 2000000] == 0)
            ++mn;
        while (cnt[mx + 2000000] == 0)
            --mx;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), sum(n + 1);
    Set l, r;
    int offset = 0, p = 0, total = 0;
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'L') {
            if (p > 0) {
                l.erase(sum[p]);
                --p;
                r.insert(-offset);
                offset += a[p];
            }
        } else if (op == 'R') {
            offset -= a[p];
            r.erase(-offset);
            ++p;
            sum[p] = sum[p - 1] + a[p - 1];
            l.insert(sum[p]);
        } else {
            int v = op == '(' ? 1 : op == ')' ? -1 : 0;
            offset += v - a[p];
            total += v - a[p];
            a[p] = v;
        }
        if (total != 0 || min(l.mn, offset + sum[p] + r.mn) < 0)
            cout << -1 << " ";
        else
            cout << max(l.mx, offset + sum[p] + r.mx) << " ";
    }
    cout << endl;
    return 0;
}