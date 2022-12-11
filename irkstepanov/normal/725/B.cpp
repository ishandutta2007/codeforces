#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    string s;
    cin >> s;
    ll n = 0;
    for (int i = 0; i < sz(s) - 1; ++i) {
        n *= 10;
        n += s[i] - '0';
    }

    char c = s[sz(s) - 1];
    int d;
    if (c == 'f') {
        d = 1;
    } else if (c == 'e') {
        d = 2;
    } else if (c == 'd') {
        d = 3;
    } else if (c == 'a') {
        d = 4;
    } else if (c == 'b') {
        d = 5;
    } else {
        d = 6;
    }

    ll ans = d;
    if (n % 4 == 1 || n % 4 == 2) {
        ll cnt = (n - 1) / 4;
        ans += ll(16) * cnt;
        if (n % 4 == 2) {
            ans += 7;
        }
    } else {
        ll cnt = (n - 3) / 4;
        ans += ll(16) * cnt;
        if (n % 4 == 0) {
            ans += 7;
        }
    }

    cout << ans << "\n";

}