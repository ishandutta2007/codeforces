#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define LL long long
#define MOD (1000000007)
const int MAXN = 500000 + 5;
char op[MAXN];
void operation(char c, int &x, int &y) {
    if (c == 'R')
        y--;
    else if (c == 'L')
        y++;
    else if (c == 'U')
        x++;
    else
        x--;
}
int Type(char c) {
    if (c == 'R' || c == 'L')
        return 0;
    else
        return 1;
}
struct D {
    LL num;
    int type;
    D() {}
    D(int _type, LL _num) { num = _num, type = _type; }
};
vector<D> v1, v2, v11, v22;
int main() {
    int n, r, c;
    while (scanf("%d%d%d", &n, &r, &c) != EOF) {
        scanf("%s", op);
        v1.clear();
        v11.clear();
        v2.clear();
        v22.clear();
        int minx, miny, maxx, maxy;
        minx = miny = maxx = maxy = 0;
        int nowx = 0, nowy = 0;
        for (int i = 0; i < n; i++) {
            operation(op[i], nowx, nowy);
            int type = Type(op[i]);
            if (type == 0) {
                if (maxy < nowy)
                    maxy = nowy;
                else if (miny > nowy)
                    miny = nowy;
                else
                    continue;
                v1.push_back(D(type, i + 1));
            } else {
                if (maxx < nowx)
                    maxx = nowx;
                else if (minx > nowx)
                    minx = nowx;
                else
                    continue;
                v2.push_back(D(type, i + 1));
            }
        }
        for (int i = 0; i < n; i++) {
            operation(op[i], nowx, nowy);
            int type = Type(op[i]);
            if (type == 0) {
                if (maxy < nowy)
                    maxy = nowy;
                else if (miny > nowy)
                    miny = nowy;
                else
                    continue;
                v11.push_back(D(type, i + 1 + n));
            } else {
                if (maxx < nowx)
                    maxx = nowx;
                else if (minx > nowx)
                    minx = nowx;
                else
                    continue;
                v22.push_back(D(type, i + 1 + n));
            }
        }
        if (v11.size()) {
            while (v1.size() < c) {
                for (int j = 0; j < (int)v11.size(); j++) {
                    v1.push_back(v11[j]);
                    v11[j].num += n;
                    if (v1.size() >= c) break;
                }
            }
        }
        if (v22.size()) {
            while (v2.size() < r) {
                for (int j = 0; j < (int)v22.size(); j++) {
                    v2.push_back(v22[j]);
                    v22[j].num += n;
                    if (v2.size() >= r) break;
                }
            }
        }
        LL ans = 0;
        int f1 = 0, f2 = 0;
        while (f1 < v1.size() || f2 < v2.size()) {
            int flag = 0;
            if (f2 == v2.size())
                flag = 1;
            else if (f1 < v1.size() && v1[f1].num < v2[f2].num)
                flag = 1;
            if (flag) {
                ans = (ans + v1[f1++].num * r % MOD) % MOD;
                c--;
            } else {
                ans = (ans + v2[f2++].num * c % MOD) % MOD;
                r--;
            }
            if (r <= 0 || c <= 0) break;
        }
        if (r && c)
            printf("-1\n");
        else
            printf("%I64d\n", ans);
    }
    return 0;
}