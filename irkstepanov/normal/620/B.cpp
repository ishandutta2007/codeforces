#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int l, r;
    cin >> l >> r;
    int ans = 0;

    for (int i = l; i <= r; ++i) {
        int x = i;
        while (x) {
            int c = x % 10;
            if (c == 0 || c == 6 || c == 9) {
                ans += 6;
            } else if (c == 1) {
                ans += 2;
            } else if (c == 2 || c == 3 || c == 5) {
                ans += 5;
            } else if (c == 4) {
                ans += 4;
            } else if (c == 7) {
                ans += 3;
            } else if (c == 8) {
                ans += 7;
            }
            x /= 10;
        }
    }

    cout << ans << "\n";

}