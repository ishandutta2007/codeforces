#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    int i;
    int a = 0, b = 0, c = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == 'a')
            a++;
        else
            break;
    }
    for (; i < n; i++) {
        if (s[i] == 'b')
            b++;
        else
            break;
    }
    for (; i < n; i++) {
        if (s[i] == 'c')
            c++;
        else
            break;
    }

    if (i == n && a && b && c && (a == c || b == c))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}