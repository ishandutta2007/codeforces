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
        ll r, b, d;
        cin >> r >> b >> d;
        if (r < b) swap(r, b);
        if (r > b*(d+1)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}