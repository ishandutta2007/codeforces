#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
int a, b, c;
string s;

bool check () {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') sum += a;
        if (s[i] == 'B') sum += b;
        if (s[i] == 'C') sum += c;
        if (sum < 0) return 0;
    }
    if (sum != 0) return 0;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        bool naso = 0;
        for (a = -1; a <= 1; a += 2) {
            for (b = -1; b <= 1; b += 2) {
                for (c = -1; c <= 1; c += 2) {
                    if (check()) naso = 1;
                }
            }
        }
        if (naso) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}