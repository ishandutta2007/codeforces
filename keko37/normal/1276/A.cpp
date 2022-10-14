#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, len;
string s;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> s;
        len = s.size();
        for (int i = 0; i < len - 2; i++) {
            if (s.substr(i, 3) == "two") {
                if (s.substr(i + 2, 3) == "one") {
                    v.push_back(i + 3);
                    i += 2;
                } else {
                    v.push_back(i + 2);
                }
            } else if (s.substr(i, 3) == "one") {
                v.push_back(i + 2);
            }
        }
        cout << v.size() << endl;
        for (auto x : v) cout << x << " "; cout << endl;
    }
    return 0;
}