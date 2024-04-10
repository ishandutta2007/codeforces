#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int cr = 0, cs = 0, cp = 0;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') cr++;
            if (s[i] == 'S') cs++;
            if (s[i] == 'P') cp++;
        }
        char c;
        if (cr >= cs && cr >= cp)
            c = 'P';
        else if (cs >= cr && cs >= cp)
            c = 'R';
        else
            c = 'S';
        for (int i = 0; i < s.length(); i++) cout << c;
        cout << endl;
    }
}