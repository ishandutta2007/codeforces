// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int stot(const string& s) {
    return (s[0]-'0') * 600 + (s[1]-'0')*60 + (s[3]-'0')*10 + (s[4]-'0');
}

string ttos(int x) {
    string s = "00:00";
    s[4] = x % 10;
    s[3] = x / 10 % 6;
    s[1] = x / 60 % 10;
    s[0] = x / 600;
    return s;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;

        int tm = stot(s);
        int z = 0;
        for (int i=0; i<1440/gcd(1440, x); i++) {
            int y = (tm + i*x) % 1440;
            string ys = ttos(y);
            if (R::equal(ys, R::reverse_view(ys))) {
                z++;
            }
        }

        cout << z << '\n';                
    }
}