#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int inter(int x) {
    int ans = 0;
    x ^= (x-1);
    for(int i = 5; i >= 0; i--) {
        if(x & (1 << i)) return (1 << (2*i));
    }
}

int ans[32][32];

int main() {
    int n, q;
    cin >> n >> q;
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            cout << inter(j) << ' ';
        }
        cout << '\n';
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << 2 * inter(i) << ' ';
        }
        cout << '\n';
    }
    for(int i = 1; i < n; i++) {
        ans[i][0] = ans[i-1][0] ^ (2 * inter(i));
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            ans[i][j] = ans[i][j-1] ^ (inter(j));
        }
    }
    int x = 0, y = 0;
    while(q--) {
        cin >> y;
        x ^= y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == x) cout << i+1 << ' ' << j+1 << '\n';
            }
        }
    }
}