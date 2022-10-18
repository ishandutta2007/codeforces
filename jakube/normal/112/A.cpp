#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s, t;
    cin >> s >> t;

    string S = "", T = "";
    for (char c : s) {
        if ('a' <= c && c <= 'z')
            S += c;
        else 
            S += c - 'A' + 'a';
    }

    for (char c : t) {
        if ('a' <= c && c <= 'z')
            T += c;
        else 
            T += c - 'A' + 'a';
    }

    if (S < T) cout << -1;
    if (S == T) cout << 0;
    if (S > T) cout << 1;
    cout << endl;

    return 0;
}