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

    int n;
    cin >> n;

    vector<char> row(n + 1, false), col(n + 1, false);

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        row[x] = true;
        col[y] = true;
    }

    int ans = 0;
    for (int i = 2; i < n - i + 1; ++i) {
        int x = 0;
        if (!row[i]) {
            ++x;
        }
        if (!row[n - i + 1]) {
            ++x;
        }
        if (!col[i]) {
            ++x;
        }
        if (!col[n - i + 1]) {
            ++x;
        }
        ans += x;
    }

    if (n % 2) {
        if (!row[(n + 1) / 2]) {
            ++ans;
        } else if (!col[(n + 1) / 2]) {
            ++ans;
        }
    }

    cout << ans << "\n";

}