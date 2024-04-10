#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, val, ind = 1, mx;
int a[MAXN], c[MAXN], p[MAXN], s[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = ~a[i];
        if (i == 1) p[i] = c[i]; else p[i] = p[i - 1] & c[i];
    }
    for (int i = n; i >= 1; i--) {
        if (i == n) s[i] = c[i]; else s[i] = s[i + 1] & c[i];
    }
    for (int i = 1; i <= n; i++) {
        int ost = a[i];
        if (i > 1) ost &= p[i - 1];
        if (i < n) ost &= s[i + 1];
        if (ost > mx) {
            mx = ost;
            ind = i;
        }
    }
    cout << a[ind] << " ";
    for (int i = 1; i <= n; i++) if (i != ind) cout << a[i] << " ";
    return 0;
}