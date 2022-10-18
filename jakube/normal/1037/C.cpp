#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == t[i]) continue;
        if (s[i+1] != t[i+1] && s[i] != s[i+1]) {
            swap(s[i], s[i+1]);
            cnt++;
        } else {
            s[i] = t[i];
            cnt++;
        }
    }
    if (s.back() != t.back())
        cnt++;
    cout << cnt << endl;
}