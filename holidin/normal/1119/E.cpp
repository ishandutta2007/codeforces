#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N  = 4e5 + 1;
long long a[N];
bool flag = 0;

int main() {
    int i, j, k, n, m, b, q;
    long long l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0, cntf = 0, ls = 0, ls1 = 0;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        while (a[i] >= 2 && ls > 0) {
            ++ans;
            a[i] -= 2;
            --ls;
        }
        if (cntf > 0)
            if (a[i] % 3 == 1 && a[i] > 1) {
                --cntf;
                ++ans;
                a[i] -= 4;
                ++ls;
            }

        ans += a[i] / 3;
        cntf += a[i] / 3;
        ls += a[i] % 3;
    }
    cout << ans;
}