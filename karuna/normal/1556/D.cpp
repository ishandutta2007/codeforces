#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 10010;
int n, k, A[30][M];

int main() {
    cin >> n >> k;
    auto And = [&](int a, int b) {
        cout << "and " << a << ' ' << b << endl;
        int x; cin >> x;
        return x;
    };
    auto Or = [&](int a, int b) {
        cout << "or " << a << ' ' << b << endl;
        int x; cin >> x;
        return x;
    };
    memset(A, -1, sizeof A);
    
    for (int i = 1; i < n; i++) {
        int x = And(i, i + 1);
        int y = Or(i, i + 1);
        for (int j = 0; j < 30; j++) {
            if (x >> j & 1) A[j][i] = A[j][i + 1] = 1;
            if (~y >> j & 1) A[j][i] = A[j][i + 1] = 0;
        }
    }
    for (int j = 0; j < 30; j++) {
        for (int i = 1; i <= n; i++) if (A[j][i] != -1) {
            int p = i - 1;
            while (p >= 1 && A[j][p] == -1) {
                A[j][p] = 1 - A[j][p + 1];
                p -= 1;
            }
        }
        for (int i = n; i >= 1; i--) if (A[j][i] != -1) {
            int p = i + 1;
            while (p <= n && A[j][p] == -1) {
                A[j][p] = 1 - A[j][p - 1];
                p += 1;
            }
        }
    }
    int x = And(1, 3);
    for (int j = 0; j < 30; j++) if (A[j][1] == -1) {
        if (x >> j & 1) {
            for (int i = 1; i <= n; i++) {
                if (i & 1) A[j][i] = 1;
                else A[j][i] = 0;
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (i & 1) A[j][i] = 0;
                else A[j][i] = 1;
            }
        }
    }

    vector<int> V;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = 0; j < 30; j++) {
            if (A[j][i] == 1) x ^= 1 << j;
        }
        V.push_back(x);
    }
    sort(V.begin(), V.end());

    cout << "finish " << V[k - 1] << endl;
}