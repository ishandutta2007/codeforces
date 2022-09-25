#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 19;
int a[maxn], sum[maxn], ans[maxn];
#define A {if (sum[m - 1] - (l ? sum[l - 1] : 0)) r = m; else l = m;}
#define B {if (sum[r - 1] - sum[m - 1]) l = m; else r = m;}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int k, n;
    cin >> n >> k;
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
        sum[a[i]] += 1;
    }
    int m = 1 << k;
    for (int i = 0; i < m; i += 1) ans[i] = m;
    for (int i = 1; i < m; i += 1) sum[i] += sum[i - 1];
    for (int i = 1; i <= k; i += 1) {
        for (int x = 0; x < (1 << i); x += 1) {
            int pans = m, h = 1 << (i - 1);
            for (int j = 0; j < m; j += (1 << i)) {
                //cout << i << " " << j << " " << h << " " << x << "\n";
                if (sum[j + h - 1] == (j ? sum[j - 1] : 0)) continue;
                if (sum[j + 2 * h - 1] == sum[j + h - 1]) continue;
                int L = 0, R = 0;
                if ((x >> (i - 1)) & 1) {
                    {
                        int l = j, r = j + h, y = i - 2;
                        while (l + 1 < r) {
                            int m = (l + r) >> 1;
                            if ((x >> y --) & 1) B
                            else A
                        }
                        L = l;
                    }
                    {
                        int l = j + h, r = j + h * 2, y = i - 2;
                        while (l + 1 < r) {
                            int m = (l + r) >> 1;
                            if ((x >> y --) & 1) A
                            else B
                        }
                        R = l;
                    }
                }
                else {
                    {
                        int l = j, r = j + h, y = i - 2;
                        while (l + 1 < r) {
                            int m = (l + r) >> 1;
                            if ((x >> y --) & 1) A
                            else B
                        }
                        L = l;
                    }
                    {
                        int l = j + h, r = j + h * 2, y = i - 2;
                        while (l + 1 < r) {
                            int m = (l + r) >> 1;
                            if ((x >> y --) & 1) B
                            else A
                        }
                        R = l;
                    }
                }
                pans = min(pans, abs((L ^ x) - (R ^ x)));
                //cout << x << " " << L << " " << R << "\n";
            }
            for (int y = x; y < m; y += (1 << i)) ans[y] = min(ans[y], pans);
        }
    }
    for (int i = 0; i < m; i += 1) cout << ans[i] << " ";
    return 0;
}