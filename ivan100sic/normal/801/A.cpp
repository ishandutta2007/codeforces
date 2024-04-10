#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        string s;
        int n, sol=0;
        cin >> s;
        n = s.size();

        auto eval = [&](string s) {
                int r = 0;
                for (int i=0; i<n-1; i++) {
                        if (s.substr(i, 2) == "VK") {
                                r++;
                        }
                }
                return r;
        };

        for (int i=0; i<n; i++) {
                string p = s;
                p[i] = 'V';
                sol = max(sol, eval(p));
                p[i] = 'K';
                sol = max(sol, eval(p));
        }

        cout << sol;
}