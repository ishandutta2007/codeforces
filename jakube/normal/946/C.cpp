#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    char cur = 'a';
    for (char& c : s) {
        if (c <= cur && cur <= 'z') {
            c = cur;
            cur++;
        }
    }
    if (cur <= 'z')
        cout << -1 << endl;
    else
        cout << s << endl;
}