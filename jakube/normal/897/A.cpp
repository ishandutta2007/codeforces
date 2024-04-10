#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        char c, d;
        cin >> c >> d;
        for (int j = l - 1; j < r; j++) {
            if (s[j] == c)
                s[j] = d;
        }
    }
    cout << s << endl;
}