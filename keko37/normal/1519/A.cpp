#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, a, b, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> d;
        if (a > b) swap(a, b);
        int br = b / a;
        if (b % a != 0) br++;
        if (br - 1 <= d) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}