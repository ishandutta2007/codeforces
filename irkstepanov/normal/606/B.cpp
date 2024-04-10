#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define x first
#define y second

using namespace std;

int main()
{

    //ifstream cin("input.txt");

    int x, y;
    int x0, y0;
    cin >> x >> y >> x0 >> y0;
    --x0, --y0;

    vector<vector<char> > used(x, vector<char>(y, false));
    used[x0][y0] = true;

    string s;
    cin >> s;
    int n = sz(s);

    int ans = x * y - 1;
    cout << "1 ";
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'L') {
            y0 = max(0, y0 - 1);
        }
        if (s[i] == 'R') {
            y0 = min(y - 1, y0 + 1);
        }
        if (s[i] == 'U') {
            x0 = max(0, x0 - 1);
        }
        if (s[i] == 'D') {
            x0 = min(x - 1, x0 + 1);
        }
        if (!used[x0][y0]) {
            cout << "1 ";
            --ans;
        } else {
            cout << "0 ";
        }
        used[x0][y0] = true;
    }

    cout << ans << "\n";

}