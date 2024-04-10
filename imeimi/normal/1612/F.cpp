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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n, m;
set<int> Q[200005];
int M[200005], T[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int q;
    cin >> n >> m >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (n > m) swap(a, b);
        Q[a].insert(b);
    }
    if (n > m) swap(n, m);
    M[1] = 1;
    for (int c = 0; ; ++c) {
        if (M[n] >= m) {
            printf("%d\n", c);
            break;
        }
        if (c > 100) {
            T[n] = M[n];
            M[n] = 0;
            int a = n, b = T[n];
            int P = a + b + Q[a].count(b);
            M[a] = max(M[a], min(P, m));
            M[min(P, n)] = max(M[min(P, n)], b);
            continue;
        }
        memcpy(T, M, sizeof(T));
        memset(M, 0, sizeof(M));
        for (int i = 1; i <= n; ++i) {
            int a = i, b = T[i];
            if (b == 0) continue;
            int P = a + b + Q[a].count(b);
            M[a] = max(M[a], min(P, m));
            M[min(P, n)] = max(M[min(P, n)], b);
        }
    }
    return 0;
}