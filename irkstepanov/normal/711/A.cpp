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

    vector<vector<char> > a(n, vector<char>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }

    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == 'O' && a[i][1] == 'O') {
            x = i, y = 0;
            break;
        }
        if (a[i][3] == 'O' && a[i][4] == 'O') {
            x = i, y = 3;
            break;
        }
    }
    if (x == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    a[x][y] = a[x][y + 1] = '+';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }

}