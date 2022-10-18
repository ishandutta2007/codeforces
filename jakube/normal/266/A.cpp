#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == s[i+1]) c++;
    }
    cout << c << endl;

    return 0;
}