#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 111;
int f[N][N], p[N][N];

void update(int x, int y, int val, int prev) {
    if (f[x][y] < val) {
        return;
    }
    f[x][y] = val;
    p[x][y] = prev;
}

int myabs(int x) {
    if (x < 0) return -x;
    return x;
}

vector<int> doit(vector<int> a) {
    if (a.size() <= 3) return a;

    sort(begin(a), end(a));
    int n = a.size();
    memset(f, 63, sizeof(f));

    int bi = -1, bj = -1, best = a[n - 1] - a[0] + 1;
    f[n - 1][n - 1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int nxt = min(i, j) - 1;
            if (nxt < 0) {
                f[i][j] = max(f[i][j], myabs(a[i] - a[j]));
                if (f[i][j] < best) {
                    bi = i; bj = j;
                    best = f[i][j];
                }
                continue;
            }

            update(nxt, j, max(f[i][j], a[i] - a[nxt]), i);
            update(i, nxt, max(f[i][j], a[j] - a[nxt]), -j);
        }
    }

    vector<int> left, right;
    while (bi != n - 1 || bj != n - 1) {
        if (p[bi][bj] > 0) {
            left.push_back(bi);
            bi = p[bi][bj];
        } else {
            right.push_back(bj);
            bj = -p[bi][bj];
        }
    }

    left.push_back(n - 1);
    left.insert(left.end(), right.rbegin(), right.rend());
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = a[left[i]];
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a = doit(a);
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;



    return 0;
}