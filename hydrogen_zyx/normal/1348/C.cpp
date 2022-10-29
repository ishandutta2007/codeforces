#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cin >> s;
        sort(s.begin(), s.end());
        set<char> se;
        set<char> all;
        for (int i = 0; i < k; i++) {
            se.insert(s[i]);
        }
        for (int i = k; i < s.length(); i++) {
            all.insert(s[i]);
        }
        if (se.size() > 1) {
            cout << s[k - 1] << endl;
        } else if (all.size() == 1) {
            cout << s[0];
            for (int i = 1; i <= (n - 1) / k; i++) cout << s[k];
            cout << endl;
        } else {
            for (int i = k - 1; i < s.length(); i++) {
                cout << s[i];
            }
            cout << endl;
        }
    }
}