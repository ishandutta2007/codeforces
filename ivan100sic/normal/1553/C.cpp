// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int solve(string s) {
    int a=0, b=0;
    for (int i=0; i<10; i++) {
        if (s[i] == '1') (i % 2 ? b : a)++;

        if (a > b + (10-i) / 2) return i+1;
        if (b > a + (9-i) / 2) return i+1;
    }
    return 10;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int z = 10;
        for (int x=0; x<1024; x++) {
            string t = bitset<10>(x).to_string();
            int ok = 1;
            for (int j=0; j<10; j++) {
                if (s[j] != '?' && t[j] != s[j]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            z = min(z, solve(t));
        }
        cout << z << '\n';
    }
}