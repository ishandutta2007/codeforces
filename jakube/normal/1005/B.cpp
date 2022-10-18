#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    
    int cnt = 0;
    for (int i = 0; i < s.size() && i < t.size(); i++) {
        if (s[i] == t[i])
            cnt++;
        else
            break;
    }
    cout << s.size() + t.size() - 2*cnt << '\n';
}