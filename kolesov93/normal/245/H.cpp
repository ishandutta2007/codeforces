#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

const int N = 5022;

int s[N][N];
int f[N][N];
int n;
int sqrtn;

struct cell {
    int l, r, id;

    cell(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}

    bool operator <(const cell& A) const {
        return make_pair(l / sqrtn, r) < make_pair(A.l / sqrtn, A.r);
    }
} queries[1111111];

int anses[1111111];
int m;

string w;

int main() {
    //freopen("in", "r", stdin);
    //cerr << sizeof(w) << endl;
    
    cin >> w;
    n = w.size();
    sqrtn = sqrt(double(n)) + 1;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        queries[i] = cell(x - 1, y - 1, i);
    }
    sort(queries, queries + m);

    for (int c = 0; c < n; ++c) {
        s[c][c] = f[c][c] = 1;
        for (int l = 1; l < n; ++l)
            if (c - l < 0 || c + l >= n || w[c - l] != w[c + l]) {
                break;
            } else {
                s[c - l][c + l] = 1;
                f[c + l][c - l] = 1;
            }
        for (int l = 0; l < n; ++l)
            if (c - l < 0 || c + l + 1 >= n || w[c - l] != w[c + l + 1]) {
                break;
            } else {
                s[c - l][c + l + 1] = 1;
                f[c + l + 1][c - l] = 1;
            }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) s[i][j] += s[i][j - 1];
        for (int j = n - 1; j >= 0; --j) f[i][j] += f[i][j + 1];
    }
    
    int l = 0, r = 0, cur = 1;
    for (int i = 0; i < m; ++i) {
        while (l < queries[i].l) { 
            cur -= s[l][r];
            ++l;
        }
        while (l > queries[i].l) { 
            cur += s[l - 1][r];
            --l;
        }
        while (r < queries[i].r) { 
            cur += f[r + 1][l];
            ++r;
        }
        while (r > queries[i].r) { 
            cur -= f[r][l];
            --r;
        }
        anses[queries[i].id] = cur;
    }

    for (int i = 0; i < m; ++i) {
        printf("%d\n", anses[i]);
    }

    return 0;
}