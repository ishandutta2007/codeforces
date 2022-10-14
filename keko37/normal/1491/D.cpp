#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, a, b;
vector <int> va, vb;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        va.clear(); vb.clear();
        cin >> a >> b;
        for (int i = 30; i >= 0; i--) {
            if (a & (1 << i)) va.push_back(i);
        }
        for (int i = 30; i >= 0; i--) {
            if (b & (1 << i)) vb.push_back(i);
        }
        if (va.size() < vb.size() || a > b) {
            cout << "NO\n";
        } else {
            int siza = va.size(), sizb = vb.size();
            bool ok = 1;
            for (int i = 0; i < sizb; i++) {
                if (va[siza - 1 - i] > vb[sizb - 1 - i]) ok = 0;
            }
            if (ok) cout << "YES\n"; else cout << "NO\n";
        }
    }
    return 0;
}