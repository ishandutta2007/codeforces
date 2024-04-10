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
        int k;
        string s;
        cin >> s >> k;
        int n = s.size();

        string p;
        int mask = 0;
        char hi = 0;
        bool gr = false;
        for (int i=0; i<n; i++) {
            for (char x='0'; x<='9'; x++) {
                if (!gr && x < s[i]) continue;
                int mask2 = mask | (1 << (x - '0'));
                int pc2 = __builtin_popcount(mask2);
                if (pc2 > k) continue;
                char hi2 = max(hi, x);

                string q = p + x;
                char e = pc2 == k ? hi2 : '9';
                for (int j=i+1; j<n; j++) q += e;
                if (q >= s) {
                    p += x;
                    mask = mask2;
                    hi = hi2;
                    gr |= x > s[i];
                    break;
                }
            }
        }

        cout << p << '\n';
    }
}