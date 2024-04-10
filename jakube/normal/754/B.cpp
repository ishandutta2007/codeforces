#include <bits/stdc++.h>
using namespace std;

bool test(vector<char> v) {
    sort(v.begin(), v.end());
    return v[0] == '.' && v[1] == 'x' && v[2] == 'x';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<string> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }

    bool b = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            b |= test({v[i][j], v[i][j+1], v[i][j+2]});
            b |= test({v[j][i], v[j+1][i], v[j+2][i]});
            if (i < 2) {
                b |= test({v[i][j], v[i+1][j+1], v[i+2][j+2]});
            }
            if (i > 1) {
                b |= test({v[i][j], v[i-1][j+1], v[i-2][2+j]});
            }
        }
    }

    cout << (b ? "YES" : "NO") << endl;

    return 0;
}