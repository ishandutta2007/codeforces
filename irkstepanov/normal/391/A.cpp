#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

const ll inf = 1e18;

int main()
{

    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    char c = '?', cnt = 0;
    int n = sz(s);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (c == '?') {
            c = s[i];
            cnt = 1;
            continue;
        }
        if (c != s[i]) {
            if (cnt % 2 == 0) {
                ++ans;
            }
            c = s[i];
            cnt = 1;
        } else {
            ++cnt;
        }
    }

    if (cnt % 2 == 0) {
        ++ans;
    }
    cout << ans << "\n";

}