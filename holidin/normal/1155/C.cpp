#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

long long a[N], x[N];

long long nod(long long a, long long b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

int main() {
    int i, j, k, n, cnt = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long nd = 0;
    for (i = 0; i < n; ++i) {
        cin >> x[i];
        if (i > 0)
            nd = nod(nd, x[i] - x[i - 1]);
    }
    for (i = 0; i < k; ++i) {
        cin >> a[i];
        if (nd % a[i] == 0) {
            cout << "YES\n";
            cout << x[0] << ' ' << i + 1 << endl;
            exit(0);
        }
    }
    cout << "NO";
}