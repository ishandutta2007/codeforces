#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int tt, n;
string s, t;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> n >> s >> t;
        v.clear();
        for (int i = 0; i < n; i++) {
            int pos;
            if (i % 2 == 0) pos = i / 2; else pos = n-1 - i / 2;
            if ((t[n-1 - i] - '0') ^ (s[pos] - '0') ^ (i % 2) == 0) {
                v.push_back(1);
            }
            v.push_back(n - i);
        }
        cout << v.size() << " ";
        for (auto x : v) cout << x << " "; cout << '\n';
    }
    return 0;
}