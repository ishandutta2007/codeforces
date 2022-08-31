#include <bits/stdc++.h>
using namespace std;
constexpr int N = 200000;
struct BIT {
    long long fen[N + 1];
    BIT() {
        memset(fen, 0, sizeof(fen));
    }
    void add(int x, int y) {
        for (int i = x + 1; i <= N; i += i & -i)
            fen[i] += y;
    }
    long long sum(int x) {
        long long ans = 0;
        for (int i = x; i > 0; i -= i & -i)
            ans += fen[i];
        return ans;
    }
    long long sum(int l, int r) {
        return sum(r) - sum(l);
    }
    int kth(int k) {
        int x = 0;
        for (int i = 17; i >= 0; --i) {
            if ((x + (1 << i)) <= N && fen[x + (1 << i)] <= k) {
                x += 1 << i;
                k -= fen[x];
            }
        }
        return x;
    }
} t1, t2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        a[x] = i;
    }
    long long c = 0;
    for (int i = 0; i < n; ++i) {
        c += i - t2.sum(a[i]);
        t2.add(a[i], 1);
        t1.add(a[i], a[i]);
        int p = i / 2;
        int m = t2.kth(p);
        long long mv = t1.sum(m + 1, n) - t1.sum(m + i % 2) - 1LL * p * (p + 1) / 2 - 1LL * (i - p) * (i - p + 1) / 2;
        cout << c + mv << " \n"[i == n - 1];
    }
    return 0;
}