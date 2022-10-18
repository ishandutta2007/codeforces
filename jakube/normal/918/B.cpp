#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, string> map;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        map[t] = s;
    }
    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        cout << s << " " << t << " #" << map[t.substr(0, t.size() - 1)] << '\n';
    }
}