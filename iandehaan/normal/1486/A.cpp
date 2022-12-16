#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool good = true;
        ll sm = 0;
        ll needed = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sm += x;
            needed += i;
            if (needed > sm) {
                good = false;
            }
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}