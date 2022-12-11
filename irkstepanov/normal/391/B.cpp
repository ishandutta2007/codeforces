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

    int n = sz(s);
    int ans = 1;

    for (int i = 0; i < n; ++i) {
        int prev = i;
        int cnt = 1;
        for (int curr = i + 1; curr < n; ++curr) {
            if (s[curr] == s[i] && (curr - prev) % 2 == 1) {
                ++cnt;
                prev = curr;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << "\n";

}