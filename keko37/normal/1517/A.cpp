#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2050 != 0) {
            cout << "-1\n";
        } else {
            llint sum = 0;
            n /= 2050;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            cout << sum << '\n';
        }
    }
    return 0;
}