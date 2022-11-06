#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n;
llong H[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> H[1];
    vector<int> I;
    for (int i = 2; i <= n; ++i) {
        cin >> H[i];
        while (!I.empty() && H[i - 1] + 2 <= H[i]) {
            int x = i - I.back();
            int m = min(x - 1ll, H[i] - H[i - 1] - 1);
            I.back() += m;
            H[i] -= m;
            if (H[i - 1] + 2 <= H[i]) I.pop_back(), ++H[i - 1], --H[i];
        }
        if (H[i - 1] + 2 <= H[i]) {
            llong cnt = (H[i] - H[i - 1] - 2) / i;
            H[i - 1] += cnt;
            H[i] -= cnt * (i - 1);
            if (H[i] - (i - 1) >= H[i - 1] + 1) ++H[i - 1], H[i] -= i - 1;
            else I.push_back(H[i] - H[i - 1]), H[i] = H[i - 1] + 1;
        }
        if (H[i - 1] == H[i]) I.push_back(i);
    }
    for (int i = n - 1; i > 0; --i) {
        if (!I.empty() && I.back() == i + 1) H[i] = H[i + 1], I.pop_back();
        else H[i] = H[i + 1] - 1;
    }
    for (int i = 1; i <= n; ++i) printf("%lld ", H[i]);
    return 0;
}