#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 505;

int n;
int sol[MAXN][MAXN];

void upd (int row) {
    int mn = 1e9, ind = -1;
    for (int i = 1; row + i <= n; i++) {
        if (sol[row + i][i] < mn) {
            mn = sol[row + i][i];
            ind = i;
        }
    }
    for (int i = 1; row + i <= n; i++) {
        if (i < ind) {
            sol[row + i + 1][i] = sol[row + i][i];
        } else if (i > ind) {
            sol[row + i][i - 1] = sol[row + i][i];
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sol[i][i];
    }
    for (int i = 0; i < n - 1; i++) upd(i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << sol[i][j] << " ";
        cout << '\n';
    }
    return 0;
}