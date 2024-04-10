#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    int d = 0;
    for (char c : s) 
        if (c <= 'Z') d++;

    for (char c : s)  {
        if (d > s.size()/2) {
            if (c <= 'Z') cout << c;
            else cout << (char)(c - 'a' + 'A');
        }
    else {
        if (c <= 'Z') cout << (char)(c - 'A' + 'a');
        else cout << c;
    }
    }


    return 0;
}