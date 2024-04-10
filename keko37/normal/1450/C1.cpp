#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 305;

int t, n;
int cnt[3];
char c[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
                if (c[i][j] == 'X') cnt[(i + j) % 3]++;
            }
        }
        int mn = 1e9, ind = -1;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] < mn) {
                mn = cnt[i];
                ind = i;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] == 'X' && (i + j) % 3 == ind) c[i][j] = 'O';
                cout << c[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}