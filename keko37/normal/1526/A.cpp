#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 60;

int t, n;
int a[MAXN], sol[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a, a + 2 * n);
        for (int i = 0; i < n; i++) {
            sol[2 * i] = a[i];
            sol[2 * n - 1 - i * 2] = a[n + i];
        }
        for (int i = 0; i < 2 * n; i++) {
            cout << sol[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}