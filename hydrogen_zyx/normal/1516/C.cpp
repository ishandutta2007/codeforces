#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll N2 = 5005;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const double PI = cos(-1.0);
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[N];
int b[N], tot;
int dp[100005];

bool check() {
    int sum = 0;
    for (int i = 1; i <= tot; i++) sum += b[i];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= tot; i++) {
        for (int j = 100000; j > 0; j--) {
            if (j < b[i]) break;
            dp[j] |= dp[j - b[i]];
        }
    }
    if (sum % 2 == 0 && dp[sum / 2] == 1) return 0;
    else return 1;
}

int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = a[i];
    tot = n;
    if (check()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        tot = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            b[++tot] = a[j];
        }
        if (check()) {
            cout << 1 << endl;
            cout << i << endl;
            return 0;
        }
    }
}