#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (n % 2 == 0) {
            bool ok = 0;
            for (int i = 1; i < n; i += 2) {
                int val = s[i] - '0';
                if (val % 2 == 0) ok = 1;
            }
            if (ok) cout << "2\n"; else cout << "1\n";
        } else {
            bool ok = 0;
            for (int i = 0; i < n; i += 2) {
                int val = s[i] - '0';
                if (val % 2 == 1) ok = 1;
            }
            if (ok) cout << "1\n"; else cout << "2\n";
        }
    }
    return 0;
}