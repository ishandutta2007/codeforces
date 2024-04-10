#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j] != a[i][0]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i][0] == a[i - 1][0]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

}