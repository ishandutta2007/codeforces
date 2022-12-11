#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    vector<vector<ll> > a(n, vector<ll>(n));
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                x = i, y = j;
            }
        }
    }

    ll sum = 0;
    for (int i = 0; ; ++i) {
        if (i != x) {
            for (int j = 0; j < n; ++j) {
                sum += a[i][j];
            }
            break;
        }
    }

    ll sum1 = 0;
    for (int j = 0; j < n; ++j) {
        sum1 += a[x][j];
    }

    if (sum1 >= sum) {
        cout << "-1\n";
        return 0;
    }
    a[x][y] = sum - sum1;
    ll ans = sum - sum1;

    for (int i = 0; i < n; ++i) {
        ll curr = 0;
        for (int j = 0; j < n; ++j) {
            curr += a[i][j];
        }
        if (curr != sum) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int j = 0; j < n; ++j) {
        ll curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += a[i][j];
        }
        if (curr != sum) {
            cout << "-1\n";
            return 0;
        }
    }
    ll curr1 = 0, curr2 = 0;
    for (int i = 0; i < n; ++i) {
        curr1 += a[i][i];
        curr2 += a[i][n - 1 - i];
    }
    if (curr1 != sum || curr2 != sum) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";

}