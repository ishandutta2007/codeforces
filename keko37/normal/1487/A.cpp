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
        int mn = 1e9;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        int sol = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == mn) sol++;
        }
        cout << n- sol << '\n';
    }
    return 0;
}