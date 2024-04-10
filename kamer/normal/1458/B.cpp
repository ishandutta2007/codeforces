#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

const int N = 101, C = 20001;

bool possib[N][C];
int maxB[N][C];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sumB = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i] = 2 * a[i] - b[i];
        sumB += b[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < C; j++) {
            possib[i][j] = false;
            maxB[i][j] = 0;
        }
    }

    possib[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            for (int c = 0; c < C; c++) {
                if (possib[j - 1][c]) {
                    possib[j][c + a[i - 1]] = true;
                    maxB[j][c + a[i - 1]] = max(maxB[j][c + a[i - 1]], maxB[j - 1][c] + b[i - 1]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int result = 0;
        for (int c = 0; c < C; c++) {
            if (possib[i][c]) {
                result = max(result, min(c, sumB) + maxB[i][c]);
            }
        }
        cout << result * 0.5 << " ";
    }
    cout << "\n";
}