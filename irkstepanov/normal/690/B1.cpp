#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int nmax = 55;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    char a[nmax][nmax];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int xmin = nmax, xmax = -nmax, ymin = nmax, ymax = -nmax;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '4') {
                xmin = min(xmin, i);
                xmax = max(xmax, i);
                ymin = min(ymin, j);
                ymax = max(ymax, j);
            }
        }
    }

    if (xmax == nmax) {
        cout << "No\n";
        return 0;
    }

    for (int i = xmin; i <= xmax; ++i) {
        for (int j = ymin; j <= ymax; ++j) {
            if (a[i][j] != '4') {
                cout << "No\n";
                return 0;
            }
        }
    }

    if (xmin - 1 >= 0) {
        for (int j = ymin; j <= ymax; ++j) {
            if (a[xmin - 1][j] != '2') {
                cout << "No\n";
                return 0;
            }
        }
    }

    if (xmax + 1 < n) {
        for (int j = ymin; j <= ymax; ++j) {
            if (a[xmax + 1][j] != '2') {
                cout << "No\n";
                return 0;
            }
        }
    }

    if (ymin - 1 >= 0) {
        for (int i = xmin; i <= xmax; ++i) {
            if (a[i][ymin - 1] != '2') {
                cout << "No\n";
                return 0;
            }
        }
    }

    if (ymax + 1 < n) {
        for (int i = xmin; i <= xmax; ++i) {
            if (a[i][ymax + 1] != '2') {
                cout << "No\n";
                return 0;
            }
        }
    }

    if (ymin - 1 >= 0 && xmin - 1 >= 0 && a[xmin - 1][ymin - 1] != '1') {
        cout << "No\n";
        return 0;
    }


    if (ymin - 1 >= 0 && xmax + 1 < n && a[xmax + 1][ymin - 1] != '1') {
        cout << "No\n";
        return 0;
    }

    if (ymax + 1 < n && xmin - 1 >= 0 && a[xmin - 1][ymax + 1] != '1') {
        cout << "No\n";
        return 0;
    }

    if (ymax + 1 < n && xmax + 1 < n && a[xmax + 1][ymax + 1] != '1') {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i < xmin - 1 || i > xmax + 1 || j < ymin - 1 || j > ymax + 1) && a[i][j] != '0') {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";

}