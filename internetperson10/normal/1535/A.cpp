#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(min(a, b) > max(c, d) || min(c, d) > max(a, b)) cout << "NO\n";
        else cout << "YES\n";
    }
}