#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    string t = "";
    for (int i = 0; i < s.size(); i+=2) {
        t += s[i];
    }

    sort(t.begin(), t.end());

    cout << t[0];
    for (int i = 1; i < t.size(); i++) {
        cout << "+" << t[i];
    }
    cout << endl;


    return 0;
}