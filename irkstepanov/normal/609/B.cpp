#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;

    vector<int> cnt(m);
    forn(i, n) {
        int a;
        cin >> a;
        ++cnt[a - 1];
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            ans += cnt[i] * cnt[j];
        }
    }

    cout << ans << "\n";

}