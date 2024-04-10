#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;

int a[N];
bool use[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= 2 * n; ++i) {
        int ps = -1;
        for (j = 1; j <= n; ++j)
        if (!use[j] && (ps < 0 || a[j] < a[ps]))
            ps = j;
        if (ps < 0) {
            cout << i - 1;
            exit(0);
        }
        for (j = 1; j <= n; ++j)
        if (a[j] % a[ps] == 0)
            use[j] = 1;
    }
}