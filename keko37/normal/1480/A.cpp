#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == 'a') s[i] = 'b'; else s[i] = 'a';
            } else {
                if (s[i] == 'z') s[i] = 'y'; else s[i] = 'z';
            }
        }
        cout << s << '\n';
    }
    return 0;
}