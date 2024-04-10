#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 12;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxN = 2e7 + 1;

int cnt[maxN];
int ct[maxN];
int val[maxN];
int f1[N], f2[N];
void run() {
    int n, x, m, i, j;
    cin >> n;
    for (i = 2; i < maxN; ++i)
    if (cnt[i] == 0) {
        for (j = 2; i * j < maxN; ++j) {
            ++cnt[i * j];
            if (cnt[i * j] == 1) {
                int t = j, cnt = 1;
                while (t % i == 0) {
                    t /= i;
                    ++cnt;
                }
                val[i * j] = i;
                ct[i * j] = cnt;
            }
        }
    }
    for (i = 0; i < n; ++i) {
        cin >> x;
        if (cnt[x] <= 1) {
            f1[i] = f2[i] = -1;
        } else {
            int t = 1;
            for (int j = 0; j < ct[x]; ++j)
                t *= val[x];
            f1[i] = val[x];
            if (t == 0)
                exit(0);
            f2[i] = x / t;
        }
    }
    for (i = 0; i < n; ++i)
        cout << f1[i] << ' ';
    cout << "\n";
    for (i = 0; i < n; ++i)
        cout << f2[i] << ' ';
    cout << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    run();
}