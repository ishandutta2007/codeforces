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

const int N = 511;
const int M = 33;
int n, k;
int a[N];
vector< pii> rs;
double A[N][N], C[N][N], B[N][N];

void mypow(int y, int n) {
    memset(C, 0, sizeof(C)); 
    for (int i = 0; i < n; ++i) C[i][i] = 1;
    
    while (y) {
        if (y & 1) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) B[i][j] = C[i][j];

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    C[i][j] = 0;
                    for (int k = 0; k < n; ++k) C[i][j] += A[i][k] * B[k][j];
                }
        }
        y >>= 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) B[i][j] = A[i][j];
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                A[i][j] = 0;
                for (int k = 0; k < n; ++k) A[i][j] += B[i][k] * B[k][j];
            }
    }
}

int num[M][M];
pii invnum[M*M];
const int K = 222;
ld f[K][M*M];

inline int go(int x, int l, int r) {
    if (x < l || x > r) return x;
    return r - (x - l);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    int cid = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            num[i][j] = cid;
            invnum[cid].first = i;
            invnum[cid].second = j;
            ++cid;
        }


    int cnt = n * (n + 1) / 2;
    ld inv = ld(1) / cnt;
    for (int i = 0; i < cid; ++i) {
        f[0][i] = 1;
    }
    for (int it = 1; it <= k; ++it) {
        for (int msk = 0; msk < cid; ++msk) {
            int x = invnum[msk].first;
            int y = invnum[msk].second;

            for (int l = 0; l < n; ++l) 
                for (int r = l; r < n; ++r) {
                    int xx = go(x, l, r);
                    int yy = go(y, l, r);
                    int flag = 0;
                    if (xx > yy) { 
                        swap(xx, yy);
                        flag = 1;
                    }
                    int nmsk = num[xx][yy];

                    if (!flag) {
                        f[it][msk] += f[it - 1][nmsk] * inv;
                    } else {
                        f[it][msk] += (1. - f[it - 1][nmsk]) * inv;
                    }
                }
        }
    }
    /*
    for (int i = 0; i < cid; ++i) {
        cout << invnum[i].first << " " << invnum[i].second << ": " << f[k][i] << endl; 
    }
    */
    
    ld ans = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = i + 1; j < n; ++j)
            if (a[i] < a[j]) {
                ans += 1. - f[k][num[i][j]];
            } else {
                ans += f[k][num[i][j]];
            }

    cout.precision(20);
    cout << fixed << ans << endl;
    
    return 0;
}