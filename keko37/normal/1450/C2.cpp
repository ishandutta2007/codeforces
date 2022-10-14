#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 305;

int t, n;
int cntx[3], cnty[3];
char c[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cntx[0] = cntx[1] = cntx[2] = 0;
        cnty[0] = cnty[1] = cnty[2] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
                if (c[i][j] == 'X') cntx[(i + j) % 3]++;
                if (c[i][j] == 'O') cnty[(i + j) % 3]++;
            }
        }
        int uk = cntx[0] + cntx[1] + cntx[2] + cnty[0] + cnty[1] + cnty[2];
        int a = -1, b = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j && (cntx[i] + cnty[j]) * 3 <= uk) {
                    a = i; b = j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] == 'X') {
                    if ((i + j) % 3 == a) c[i][j] = 'O';
                } else if (c[i][j] == 'O') {
                    if ((i + j) % 3 == b) c[i][j] = 'X';
                }
                cout << c[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}