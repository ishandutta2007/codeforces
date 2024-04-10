#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 10;
LL sum[maxn + 10], cnt[maxn + 10], k[maxn + 10], b[maxn + 10];
void modify(LL sum[], int x, LL y) {
    for (; x <= maxn; x += x & -x) sum[x] += y;
}
LL query(LL sum[], int x){
    LL res = 0;
    for (;x; x -= x & -x) res += sum[x];
    return res;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    LL ans = 0;
    for (int j = 1, x; j <= n; j += 1){
        cin >> x;
        ans += query(k, x) * x + query(b, x);
        for (int i = 1; i <= maxn; i += x) {
            LL R = min(i + x - 2, maxn);
            ans += query(sum, R) - query(sum, i - 1);
            ans -= (query(cnt, R) - query(cnt, i - 1)) * (i - 1);
        }
        modify(sum, x, x);
        modify(cnt, x, 1);
        for (int i = 1; i <= maxn; i += x) {
            LL R = min(i + x - 1, maxn + 1);
            modify(k, i, 1);
            modify(k, R, -1);
            modify(b, i, -i + 1);
            modify(b, R, i - 1);
        }
        cout << ans << " ";
    }

    return 0;
}