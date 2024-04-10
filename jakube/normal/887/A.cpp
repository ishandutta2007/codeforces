#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int i = 0;
    while (i < (int)s.size() && s[i] == '0') {
        i++;
    }

    int cnt = 0; 
    while (i < (int)s.size()) {
        if (s[i] == '0')
            cnt++;
        i++;
    }

    if (cnt >= 6)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}