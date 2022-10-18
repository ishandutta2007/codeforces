#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    
    int r = 0;
    for (int i = 0; i < x; i++) {
        char e = '0';
        if (i == y)
            e = '1';
        if (s[n-1-i] != e)
            r++;
    }
    cout << r << endl;
}