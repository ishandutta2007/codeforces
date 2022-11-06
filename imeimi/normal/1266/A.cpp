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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

char in[105];
bool solve() {
    cin >> in;
    int cnt[10] = {};
    int sum = 0;
    for (int i = 0; in[i]; ++i) {
        ++cnt[in[i] - '0'];
        sum += in[i] - '0';
    }
    if (sum % 3 > 0 || cnt[0] == 0) return 0;
    --cnt[0];
    for (int i = 0; i < 10; i += 2) {
        if (cnt[i] > 0) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf(solve() ? "red\n" : "cyan\n");
    return 0;
}