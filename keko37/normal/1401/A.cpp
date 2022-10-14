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
        int res = max(n - k, 0);
        if (res % 2 == 1) res++;
        res /= 2;
        cout << abs(res * 2 + k - n) << '\n';
    }
    return 0;
}