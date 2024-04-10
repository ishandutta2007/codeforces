#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    if (k > n) {
        cout << s;
        sort(s.begin(), s.end());
        for (int i = 0; i < k - n; i++) {
            cout << s[0];
        }
        cout << endl;
    } else {
        set<char> se(s.begin(), s.end());
        vector<char> v(se.begin(), se.end());
        auto next = [&v](char c) {
            for (int i = 1; i < (int)v.size(); i++) {
                if (v[i-1] == c)
                    return v[i];
            }
            return v[0];
        };

        string t = s.substr(0, k);
        for (int i = k-1; i >= 0; i--) {
            char old = t[i];
            char ne = next(old);
            t[i] = ne;
            if (ne > old) break;
        }
        cout << t << endl;
    }
}