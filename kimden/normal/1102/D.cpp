#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    vector<char> from, to;
    for (int i = 0; i < n; ++i) {
        ++mp[s[i]];
    }
    int f[3][3];



    f[0][1] = min(max(0, mp['0'] - n / 3), max(0, n / 3 - mp['1']));
    f[0][2] = min(max(0, mp['0'] - n / 3), max(0, n / 3 - mp['2']));
    f[1][0] = min(max(0, mp['1'] - n / 3), max(0, n / 3 - mp['0']));
    f[1][2] = min(max(0, mp['1'] - n / 3), max(0, n / 3 - mp['2']));
    f[2][0] = min(max(0, mp['2'] - n / 3), max(0, n / 3 - mp['0']));
    f[2][1] = min(max(0, mp['2'] - n / 3), max(0, n / 3 - mp['1']));
    f[0][0] = mp['0'] - f[0][1] - f[0][2];
    f[1][1] = mp['1'] - f[1][0] - f[1][2];
    f[2][2] = mp['2'] - f[2][0] - f[2][1];

    from.push_back('#');
    to.push_back('#');
    int ptr = 0;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (f[s[i] - '0'][j]) {
                --f[s[i] - '0'][j];
                s[i] = j + '0';
                break;
            }
        }
    }
    cout << s << endl;
}