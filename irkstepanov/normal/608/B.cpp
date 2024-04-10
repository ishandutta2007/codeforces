#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");

    string a, b;
    cin >> a >> b;

    int n = sz(b), m = sz(a);

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i <= n - m; ++i) {
        if (b[i] == '0') {
            ++cnt0;
        } else {
            ++cnt1;
        }
    }

    ll ans = 0;

    for (int i = 0; i < m; ++i) {
        if (a[i] == '0') {
            ans += static_cast<ll>(cnt1);
        } else {
            ans += static_cast<ll>(cnt0);
        }
        if (b[i] == '0') {
            --cnt0;
        } else {
            --cnt1;
        }
        if (i != m - 1) {
            if (b[n - m + i + 1] == '0') {
                ++cnt0;
            } else {
                ++cnt1;
            }
        }
    }

    cout << ans << "\n";

}