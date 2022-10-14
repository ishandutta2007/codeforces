#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n;
int a[MAXN], b[MAXN], c[MAXN], sol[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        sol[0] = a[0];
        for (int i = 1; i < n-1; i++) {
            if (a[i] != sol[i - 1]) {
                sol[i] = a[i];
            } else {
                sol[i] = b[i];
            }
        }
        if (a[n - 1] != sol[n - 2] && a[n - 1] != sol[0]) {
            sol[n - 1] = a[n - 1];
        } else if (b[n - 1] != sol[n - 2] && b[n - 1] != sol[0]) {
            sol[n - 1] = b[n - 1];
        } else {
            sol[n - 1] = c[n - 1];
        }
        for (int i = 0; i < n; i++) cout << sol[i] << " "; cout << '\n';
    }
    return 0;
}