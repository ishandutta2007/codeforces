#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = 2 * abs(a-b);
        if(x < max(a, max(b, c))) cout << -1 << '\n';
        else {
            if(c + x/2 <= x) cout << c + x/2 << '\n';
            else cout << c - x/2 << '\n';
        }
    }
}