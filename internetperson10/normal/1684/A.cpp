#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.size() == 2) cout << s[1] << '\n';
        else {
            sort(s.begin(), s.end());
            cout << s[0] << '\n';
        }
    }
}