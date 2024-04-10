#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ind = -1;
        for (int i = 2; i < n; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                ind = i;
            }
        }
        if (ind == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ind - 1 << " " << ind << " " << ind + 1 << '\n';
        }
    }
    return 0;
}