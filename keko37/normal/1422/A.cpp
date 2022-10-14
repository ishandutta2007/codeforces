#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, a, b, c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << a + b + c - 1 << '\n';
    }
    return 0;
}