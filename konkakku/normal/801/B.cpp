#include <bits/stdc++.h>
using namespace std;

string s, t;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < t[i]) {
            return cout << -1, 0;
        }
    }
    cout << t;
}