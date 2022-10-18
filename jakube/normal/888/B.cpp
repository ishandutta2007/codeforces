#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (char c : s)
        m[c]++;
    cout << 2 * (min(m['L'], m['R']) + min(m['U'], m['D'])) << endl;
}