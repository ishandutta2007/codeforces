#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, odd, even;
map <pi, char> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char tip;
        cin >> tip;
        if (tip == '+') {
            int a, b; char c;
            cin >> a >> b >> c;
            mp[{a, b}] = c;
            if (mp.find({b, a}) != mp.end()) {
                odd++;
                if (mp[{b, a}] == c) even++;
            }
        } else if (tip == '-') {
            int a, b;
            cin >> a >> b;
            if (mp.find({b, a}) != mp.end()) {
                odd--;
                if (mp[{b, a}] == mp[{a, b}]) even--;
            }
            mp.erase({a, b});
        } else {
            int k;
            cin >> k;
            if (k % 2 == 1) {
                if (odd) cout << "YES\n"; else cout << "NO\n";
            } else {
                if (even) cout << "YES\n"; else cout << "NO\n";
            }
        }
    }
    return 0;
}