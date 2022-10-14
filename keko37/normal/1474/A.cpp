#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int last = -1;
        for (auto c : s) {
            last = c - '0' + (c - '0' + 1 != last);
            cout << last - (c - '0');
        }
        cout << '\n';
    }
    return 0;
}