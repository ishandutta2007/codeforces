#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, q, k;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int lo, hi;
        cin >> lo >> hi;
        cout << 2 * k - 2 * (hi - lo + 1) - (a[lo] - 1) - (k - a[hi]) << '\n';
    }
    return 0;
}