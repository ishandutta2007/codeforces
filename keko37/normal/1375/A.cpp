#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

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
            if (a[i] < 0) a[i] *= -1;
        }
        for (int i = 1; i < n; i += 2) {
            if (a[i - 1] <= a[i]) a[i + 1] *= -1; else a[i] *= -1;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}