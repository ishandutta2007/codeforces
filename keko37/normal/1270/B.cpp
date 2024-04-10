#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const int INF = 1000000000;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0, mn = INF;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool naso = 0;
        for (int i = 0; i < n-1; i++) {
            if (abs(a[i] - a[i+1]) >= 2) {
                naso = 1;
                cout << "YES\n";
                cout << i+1 << " " << i+2 << '\n';
                break;
            }
        }
        if (!naso) cout << "NO\n";
    }
    return 0;
}