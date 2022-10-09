// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int z = 0;

        int n = s.size();
        for (int i=0; i<n; i++) {
            set<char> q, p;
            for (int j=i-2; j<=i+2; j++) {
                if (j >= 0 && j < n) {
                    q.insert(s[j]);
                    if (j < i) p.insert(s[j]);
                }
            }

            if (p.count(s[i])) {
                char c = 'a';
                while (q.count(c)) {
                    c++;
                }
                s[i] = c;
                z++;
            }
        }

        cout << z << '\n';
    }
}