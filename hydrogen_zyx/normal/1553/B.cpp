#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
char c1[N];
char c2[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        bool ok = 0;
        string tmp;
        for (int i = 0; i < s1.length(); i++) {
            for (int j = i; j < s1.length(); j++) {
                int len = j - i;
                if (len + j + 1 < s2.length()) continue;
                tmp.clear();
                for (int k = i; k <= j; k++) {
                    tmp.push_back(s1[k]);
                }
                int now = j - 1;
                while (tmp.length() < s2.length()) {
                    tmp.push_back(s1[now--]);
                }
                if (tmp == s2) ok = 1;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}