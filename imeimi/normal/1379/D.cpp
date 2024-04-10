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

int n, h, m, k;
int H[100001], M[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> h >> m >> k;
    vector<int> V;
    for (int i = 1; i <= n; ++i) {
        cin >> H[i] >> M[i];
        V.emplace_back(M[i] % (m / 2));
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < n; ++i) V.push_back(V[i] + m / 2);
    int mnv = n + 1, mnt = 0;
    for (int i = 0, j = 1; i < n; ++i) {
        if (V[i + 1] - V[i] >= k) return printf("0 %d\n", (V[i] + k) % (m / 2)), 0;
        j = max(i + 1, j);
        while (j < i + n && V[j] - V[i] < k) ++j;
        int v = j - i - 1, t = (V[i] + k) % (m / 2);
        if (v < mnv) mnv = v, mnt = t;
    }
    printf("%d %d\n", mnv, mnt);
    for (int i = 1; i <= n; ++i) {
        int v = (mnt - M[i] % (m / 2) + m / 2) % (m / 2);
        if (0 < v && v < k) printf("%d ", i);
    }
    return 0;
}