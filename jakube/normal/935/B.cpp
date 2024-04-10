#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U')
            y++;
        else
            x++;
        
        if (x == y && i < n - 1 && s[i] == s[i + 1])
            cnt++;
    }
    cout << cnt << endl;
}