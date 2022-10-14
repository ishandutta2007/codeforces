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
        int ind = -1, mn = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] < mn) {
                mn = a[i];
                ind = i;
            }
        }
        cout << n - 1 << '\n';
        int br = 0;
        for (int i = ind - 1; i >= 1; i--) {
            br++;
            cout << ind << " " << i << " " << mn << " " << mn + br << '\n';
        }
        br = 0;
        for (int i = ind + 1; i <= n; i++) {
            br++;
            cout << ind << " " << i << " " << mn << " " << mn + br << '\n';
        }
    }
    return 0;
}