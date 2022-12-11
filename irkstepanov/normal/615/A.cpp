#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    vector<char> on(m, false);

    while (n--) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            on[x - 1] = true;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (!on[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

}