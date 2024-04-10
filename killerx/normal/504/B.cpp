#include <bits/stdc++.h>
using namespace std;
struct Bit {
    int sum[200005];
    void clr() {memset(sum, 0, sizeof(sum));}
    void add(int x, int v) {for (++ x; x <= 200000; x += x & -x) sum[x] += v;}
    int qry(int x) {int ans = 0; for (++ x; x; x -= x & -x) ans += sum[x]; return ans;}
} bit;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <int> a, b;
    bit.clr();
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        a.push_back(x - bit.qry(x));
        bit.add(x, 1);
    }
    bit.clr();
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        b.push_back(x - bit.qry(x));
        bit.add(x, 1);
    }
    // for (int x : a) cout << x << " "; cout << endl;
    // for (int x : b) cout << x << " "; cout << endl;
    vector <int> c(n);
    for (int i = 0; i < n; ++ i) {
        c[i] = a[i] + b[i];
    }
    for (int i = n - 1; i; -- i) {
        if (c[i] >= n - i) {
            c[i] -= n - i;
            ++ c[i - 1];
        }
    }
    c[0] %= n;
    // for (int x : c) cout << x << " "; cout << endl;
    bit.clr();
    for (int i = 0; i < n; ++ i) {
        int lb = 0, rb = n;
        while (lb < rb) {
            int md = (lb + rb) >> 1;
            if (md - bit.qry(md) < c[i]) lb = md + 1;
            else rb = md;
        }
        bit.add(lb, 1);
        cout << lb << " \n"[i + 1 == n];
    }
    return 0;
}