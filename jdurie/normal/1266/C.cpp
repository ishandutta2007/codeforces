#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll mat[600][600];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll r, c;
    cin >> r >> c;
    if(r == 1 && c == 1) cout << 0 << endl;
    else if(r == 1) {
        for(ll j = 0; j < c; j++) cout << j + 2 << " ";
        cout << endl;
    } else if(c == 1)
        for(ll i = 0; i < r; i++) cout << i + 2 << endl;
    else {
        for(ll i = 1; i <= r; i++) {
            for(ll j = 1; j <= c; j++)
                cout << i * (r + j) << " ";
            cout << endl;
        }
    }
}