#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        for (auto x : s) {
            if (x == '(') a++;
            if (x == '[') b++;
            if (x == ')' && a) c++, a--;
            if (x == ']' && b) c++, b--;
        }
        cout << c << endl;
    }
}