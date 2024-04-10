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
        int sol = 0;
        int cnt = 0;
        for (auto c : s) {
            if (c == '0') cnt++;
        }
        cnt /= 2;
        if (n % 2 == 1 && s[n / 2] == '0') {
            if (cnt == 0) cout << "BOB\n"; else cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }
    return 0;
}