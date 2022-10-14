#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (a[0] + a[1] <= a[n - 1]) {
            cout << 1 << " " << 2 << " " << n << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}