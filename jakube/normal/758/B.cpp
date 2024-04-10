#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    
    int r = 0, b = 0, y = 0, g = 0;

    // which color
    vector<int> v(4, 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '!') {
            v[i%4]++;
        }
        else {
            if (s[i] == 'R')
                r = i % 4;
            if (s[i] == 'G')
                g = i % 4;
            if (s[i] == 'Y')
                y = i % 4;
            if (s[i] == 'B')
                b = i % 4;
        }
    }

    cout << v[r] << ' ' << v[b] << ' ' << v[y] << ' ' << v[g] << endl;
    return 0;
}