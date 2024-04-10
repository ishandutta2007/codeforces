#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int M = 30;
int A[M][M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int h, w; cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                A[i][j] = 0;
                if (i != 1 && i != h && j != 1 && j != w) continue;

                int f = 1;
                for (int k = 0; k < 8; k++) {
                    if (A[i + dx[k]][j + dy[k]] == 1) {
                        f = 0; break;
                    }
                }
                if (f == 1) A[i][j] = 1;
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << A[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) A[i][j] = 0;
        }
    }
}