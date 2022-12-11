#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        a[n / 2][i] = a[i][n / 2] = 1;
    }
    int put = 2 * n - 1;
    int req = (n * n + 1) / 2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (put < req && !a[i][j]) {
                a[i][j] = a[n - 1 - i][j] = a[i][n - 1 - j] = a[n - 1 - i][n - 1 - j] = 1;
                put += 4;
            }
        }
    }

    vector<int> odd, even;
    for (int i = 1; i <= n * n; ++i) {
        if (i & 1) {
            odd.pb(i);
        } else {
            even.pb(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) {
                cout << odd.back();
                odd.pop_back();
            } else {
                cout << even.back();
                even.pop_back();
            }
            cout << " ";
        }
        cout << "\n";
    }

}