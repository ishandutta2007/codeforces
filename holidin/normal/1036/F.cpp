#include <bits/stdc++.h>
using namespace std;

set <unsigned long long> s;
vector <unsigned long long> kek;

int main() {
    unsigned long long i, j, a, n, u;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unsigned long long x;
    for (i = 2; i <= 1000000; ++i) {
        x = i;
        while ((long double) x * (long double) i <= 1.1e18 ) {
            x *= i;
            u = sqrt(x) + 0.5;
            if (u * u != x)
                s.insert(x);
        }
    }
    cin >> n;
    for (set <unsigned long long> :: iterator it = s.begin(); it != s.end(); ++it)
        kek.push_back((*it));
    for (i = 0; i < n; ++i) {
        cin >> a;
        unsigned long long ans = a - 1, l = 1, r = 1e9 + 1;
        while (r - l > 1) {
            x = (l + r) / 2;
            if (x * x > a)
                r = x;
            else
                l = x;
        }
        ans -= (l - 1);
        l = -1, r = kek.size();
        while (r - l > 1) {
            x = (l + r) / 2;
            if (kek[x] > a)
                r = x;
            else
                l = x;
        }
        ans -= l + 1;
        cout << ans << "\n";
    }
}