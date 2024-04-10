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

    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }

    sort(all(a));
    reverse(all(a));
    int cnt = 0;
    while (m > 0) {
        m -= a[cnt];
        ++cnt;
    }

    cout << cnt << "\n";

}