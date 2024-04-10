#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long power(long long base, int e, int M=MOD)
{
    long long result = 1;
    base %= M;
    while (e) {
        if (e & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

struct Q
{
    int l, x;
    int ans;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    auto hsb_slow = [](int x) {
        for (int i = 19; i >= 0; i--) {
            if (x & (1 << i))
                return i;
        }
        return 0;
    };
    vector<int> hsb(1 << 20, 0);
    for (int i = 1; i < (1 << 20); i++) {
        hsb[i] = hsb_slow(i);
    }

    vector<Q> queries(q);
    for (int i = 0; i < q; i++) {
        auto& qq = queries[i];
        cin >> qq.l >> qq.x;
        qq.idx = i;
    }
    sort(queries.begin(), queries.end(), [](auto p, auto q) {
        return p.l < q.l;
    });

    
    vector<int> leading(20, 0);
    int other = 0;
    int idx = 0;
    while (idx < q && queries[idx].l == 0) {
        auto& qq = queries[idx];
        if (qq.x == 0)
            qq.ans = 1;
        else
            qq.ans = 0;
        idx++;
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x && leading[hsb[x]]) {
            x ^= leading[hsb[x]];
        }
        if (x) {
            leading[hsb[x]] = x;
        } else 
            other++;

        while (idx < q && queries[idx].l == i + 1) {
            auto& qq = queries[idx];
            int y = qq.x;
            while (y && leading[hsb[y]]) {
                y ^= leading[hsb[y]];
            }
            if (y) {
                qq.ans = 0;
            } else {
                qq.ans = power(2, other);
            }

            idx++;
        }
    }

    sort(queries.begin(), queries.end(), [](auto p, auto q) {
        return p.idx < q.idx;
    });
    for (auto qq : queries) {
        cout << qq.ans << '\n';
    }
}