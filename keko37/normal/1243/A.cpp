#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int t, n;
int a[MAXN];

int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int sol = 0;
        for (int i = n-1; i >= 0; i--) {
            sol = max(sol, min(n - i, a[i]));
        }
        cout << sol << '\n';
    }
    return 0;
}