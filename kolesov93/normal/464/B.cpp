#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
ll ccoor[8][3];
ll cd[8][8];
ll coor[8][3], curd[8][8];
int sz[8], cur[8];
bool used[8];

inline ll sqr(ll x) {
    return x * x;
}
inline ll calc(int x, int y) {
    return sqr(coor[x][0] - coor[y][0]) + sqr(coor[x][1] - coor[y][1]) + sqr(coor[x][2] - coor[y][2]);
}

int nxt() {
    for (int i = 7; i >= 0; --i)
        if (cur[i] + 1 < sz[i]) {
            next_permutation(coor[i], coor[i] + 3);
            ++cur[i];
            for (int j = i + 1; j < 8; ++j) {
                sort(coor[j], coor[j] + 3);
                cur[j] = 0;
            }
            return i;
        }
    return -1;
}

int main() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 3; ++j)
            if (i & (1 << j)) ccoor[i][j] = 1;

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            for (int q = 0; q < 3; ++q) cd[i][j] += sqr(ccoor[i][q] - ccoor[j][q]);

    for (int i = 0; i < 8; ++i)  {
        for (int j = 0; j < 3; ++j) {
            int x;
            scanf("%d", &x);
            coor[i][j] = x;
        }
        sort(coor[i], coor[i] + 3);
        sz[i] = 1;
        while (next_permutation(coor[i], coor[i] + 3)) sz[i]++;
    }

    int from = 0;
    //int iter = 0;
    do {
        //++iter;
        vector<int> pos;
        pos.push_back(0);

        for (int i = 0; i < 8; ++i)
            for (int j = max(from, i + 1); j < 8; ++j)
                curd[i][j] = curd[j][i] = calc(i, j);
        ll d = curd[0][1];
        for (int j = 2; j < 8; ++j)
            d = min(d, curd[0][j]);
        if (d == 0) continue;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        for (int i = 0; i < 8; ++i)
            for (int j = i + 1; j < 8; ++j)
                if (curd[i][j] == d) ++c1;
                else if (curd[i][j] == d + d) ++c2;
                else if (curd[i][j] == d + d + d) ++c3;
        if (c1 != 12 || c2 != 12 || c3 != 4) continue;
        memset(used, 0, sizeof(used));
        used[0] = true;

        bool found = true;
        for (int it = 1; it < 8; ++it) {
            for (int i = 0; int(pos.size()) - 1 != it && i < 8; ++i)
                if (!used[i]) {
                    bool cool = true;
                    for (int j = 0; j < pos.size(); ++j)
                        if (d * cd[it][j] != curd[ pos[j] ][i]) {
                            cool = false;
                        }
                    if (cool) {
                        pos.push_back(i);
                        used[i] = true;
                        break;
                    }
                }

            if (pos.size() != it + 1) {
                found = false;
                break;
            }
        }

        if (found) {
            puts("YES");
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 3; ++j) {
                    printf("%d ", int(coor[i][j]));
                }
                puts("");
            }
            return 0;
        }
    } while ((from = nxt()) != -1);
//    cerr << iter << endl;

    puts("NO");

    return 0;
}