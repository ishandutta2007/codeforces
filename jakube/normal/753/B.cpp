#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s = "";
    for (char c = '0'; c <= '9'; c++) {
        cout << c << c << c << c << endl;
        int a, b;
        cin >> a >> b;
        if (a == 4) 
            return 0;
        for (int i = 0; i < a + b; i++) {
            s += c;
        }
    }

    do {
        cout << s << endl;
        int a, b;
        cin >> a >> b;
        if (a == 4) return 0;
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}