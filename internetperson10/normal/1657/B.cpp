#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, b, x, y, a = 0, sum = 0;
        cin >> n >> b >> x >> y;
        while(n--) {
            if(a + x <= b) {
                a += x;
            }
            else {
                a -= y;
            }
            sum += a;
        }
        cout << sum << '\n';
    }
}