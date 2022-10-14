#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x & 1) a++; else b++;
        }
        bool naso = 0;
        for (int i = 0; i <= k; i++) {
            if (i <= a && k - i <= b && i % 2 == 1) naso = 1;
        }
        if (naso) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}