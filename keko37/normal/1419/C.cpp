#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, x;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int sum = 0, br = 0;
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            if (val == x) br++;
            sum += val;
        }
        if (br == n) {
            cout << "0\n";
        } else if (br == 0 && sum == n * x || br >= 1) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}