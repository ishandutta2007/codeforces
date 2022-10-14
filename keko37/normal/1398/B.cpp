#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        v.clear();
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                len++;
            } else {
                if (len) v.push_back(len);
                len = 0;
            }
        }
        if (len) v.push_back(len);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int sol = 0;
        for (int i = 0; i < v.size(); i += 2) {
            sol += v[i];
        }
        cout << sol << '\n';
    }
    return 0;
}