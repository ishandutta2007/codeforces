#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        cout << *max_element(s.begin(), s.end()) - '0' << "\n";
    }
    return 0;
}