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

int n, q;
int A[200001];
int B[200001];
map<int, int> mp[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    llong sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        sum += B[i] = A[i];
    }
    cin >> q;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        if (mp[s][t] != 0) {
            sum -= max(B[mp[s][t]], 0);
            sum += max(++B[mp[s][t]], 0);
        }
        mp[s][t] = u;
        if (mp[s][t] != 0) {
            sum -= max(B[mp[s][t]], 0);
            sum += max(--B[mp[s][t]], 0);
        }
        printf("%lld\n", sum);
    }
    return 0;
}