#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int LogN = 11;
const int TN = 1024;
const int inf = 1e9;
int t[LogN];
int mn[TN], sm[TN], m[N];
int c[N];

int main() {
    int i, j, k, n, x, p;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 0; i < n; ++i) {
        cin >> p;
        for (j = 0; j < p; ++j) {
            cin >> x;
            m[i] += t[x - 1];
        }
    }
    for (i = 0; i < TN; ++i)
    for (j = 0; j < N; ++j)
    if ((m[j] | i) == i)
        ++c[i];
    for (i = 0; i < TN; ++i)
        sm[i] = -1;
    int ansc = -1, anscost, i1 = -1, j1 = -1;
    for (i = 0; i < k; ++i) {
        int cost, y = 0;
        cin >> cost;
        cin >> p;
        for (j = 0; j < p; ++j) {
            cin >> x;
            y += t[x - 1];
        }
        if (sm[y] > 0 && (c[y] > ansc || (c[y] == ansc && mn[y] + cost < anscost))) {
            ansc = c[y];
            anscost = mn[y] + cost;
            i1 = sm[y];
            j1 = i + 1;
        }
        if (sm[y] < 0 || mn[y] > cost) {
            sm[y] = i + 1;
            mn[y] = cost;
        }
    }
    for (i = 0; i < TN; ++i)
    for (j = i + 1; j < TN; ++j)
    if (sm[i] > 0 && sm[j] > 0 && (c[(i | j)] > ansc || (c[(i | j)] == ansc && mn[i] + mn[j] < anscost))) {
        ansc = c[(i | j)];
        anscost = mn[i] + mn[j];
        i1 = sm[i];
        j1 = sm[j];
    }
    cout << i1 << ' ' << j1;
}