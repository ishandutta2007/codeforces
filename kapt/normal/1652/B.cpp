#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin>> tst;
    while (tst--) {
        string s;
        cin >> s;
        int n = s.size();
        int ind = n;
        vector<int> used(26, 0);
        for (int i = n - 1; i >= 0; --i) {
            if (!used[s[i] - 'a']) {
                ind = i;
                used[s[i] - 'a'] = 1;
            }
        }
        for (int i = ind; i < n;++i) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}