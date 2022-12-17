#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k, n;
    string s;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    int ans = 0;
    for (i = 0; i < n / 2; ++i)
    if (s[2*i] == s[2*i + 1]) {
        ++ans;
        if (s[2 * i] == 'a')
            s[2 * i] = 'b';
        else {
            s[2 * i] = 'a';
        }
    }
    cout << ans << endl;
    cout << s;
}