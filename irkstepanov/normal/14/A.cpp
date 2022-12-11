#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 100500;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    int xmin = inf, xmax = -inf;
    int ymin = inf, ymax = -inf;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
                xmin = min(xmin, i);
                xmax = max(xmax, i);
                ymin = min(ymin, j);
                ymax = max(ymax, j);
            }
        }
    }

    for (int i = xmin; i <= xmax; ++i) {
        for (int j = ymin; j <= ymax; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }

}