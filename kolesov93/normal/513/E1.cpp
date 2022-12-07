#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const ld PI = acos(-1.);
const int K = 51;
const int N = 404; 
const int M = N*N/2;
int lmx[K][M], rmx[K][M]; 

int prv(int x) {
    return x & (x - 1);
}
int nxt(int x) {
    return x + x - prv(x);
}

void lmodify(int k, int x, int val) {
    ++x;
    while (x < M) {
        lmx[k][x] = max(lmx[k][x], val);
        x = nxt(x);
    }
}
int lfindmax(int k, int x) {
    ++x;
    int res = -1e9;
    while (x) {
        res = max(res, lmx[k][x]);
        x = prv(x);
    }
    return res;
}

void rmodify(int k, int x, int val) {
    ++x;
    while (x) {
        rmx[k][x] = max(rmx[k][x], val);
        x = prv(x);
    }
}
int rfindmax(int k, int x) {
    ++x;
    int res = -1e9;
    while (x < M) {
        res = max(res, rmx[k][x]);
        x = nxt(x);
    }
    return res;
}

int a[N];
int sums[M];
int cumsum[N][N];
int ksums;

struct cell {
    int pos, value1, value2;
};
vector<cell> evs[N], nevs[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; ++i) {
        cumsum[i][i] = a[i];
        for (int j = i; j < n; ++j) {
            sums[ksums++] = cumsum[i][j];
            cumsum[i][j + 1] = cumsum[i][j] + a[j + 1];
        }
    }
    sort(sums, sums + ksums);
    ksums = unique(sums, sums + ksums) - sums;

    memset(lmx, 128+63, sizeof(lmx));
    memset(rmx, 128+63, sizeof(rmx));
    int ans = -1e9;
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i < n; ++i) {
            evs[i] = nevs[i];
            nevs[i].clear();
        }

        for (int l = 0; l < n; ++l) {
            for (auto x : evs[l]) {
                lmodify(j, x.pos, x.value1);
                rmodify(j, x.pos, x.value2);
            }
            for (int r = l; r < n; ++r) {
                int sum = cumsum[l][r];
                int pos = lower_bound(sums, sums + ksums, sum) - sums;
                
                int value = max(lfindmax(j, pos - 1) + sum, rfindmax(j, pos + 1) - sum);
                if (j == 1) {
                    value = 0;
                }
                if (j == k) {
                    ans = max(ans, value);
                }
                //cout << j << " " << l << " " << r << " " << value << endl; 

                nevs[r + 1].push_back({pos, value - sum, value + sum});
            }
        }
    }

    cout << ans << endl;

    return 0;
}