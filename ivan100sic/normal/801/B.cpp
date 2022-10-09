#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        string s, p;
        int n, c=0;

        cin >> s >> p;
        n = s.size();

        for (int i=0; i<n; i++) {
                if (min(s[i], p[i]) != p[i]) {
                        cout << -1;
                        return 0;
                }
        }
        cout << p;
}