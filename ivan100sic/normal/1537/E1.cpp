// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

string brut(string s, int k) {
    int n = s.size();
    string z = "\x7f";
    for (int i=1; i<=n; i++) {
        string t;
        for (int j=0; j<k; j++) {
            t += s[j%i];
        }
        z = min(z, t);
    }
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << brut(s, k);
}