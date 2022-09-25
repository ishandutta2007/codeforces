#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int ok = 1;
        for (char c : {'r', 'g', 'b'})
            if (ranges::find(s, c - 'a' + 'A') < ranges::find(s, c))
                ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}