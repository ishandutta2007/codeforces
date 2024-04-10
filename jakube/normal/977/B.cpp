#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> m;
    for (int i = 0; i < n-1; i++) {
        m[s.substr(i, 2)]++;
    }

    string best = "";
    int ma = 0;
    for (auto p : m) {
        if (p.second > ma) {
            ma = p.second;
            best = p.first;
        }
    }
    cout << best << '\n';
}