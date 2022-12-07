#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

const int N = 311111;
int a[N], b[N], whb[N], wha[N], n;

int isLeft(int val, int shift) {
    int posa = wha[val] + shift;
    int posb = whb[val];

    if (posb < shift) posb += n;
    return posb <= posa;
}

int getit(int val, int shift) {
    int posa = wha[val] + shift;
    int posb = whb[val];

    if (posb < shift) posb += n;

    return abs(posa - posb);
}

struct cell {
    int val, dis;

    cell(int adis, int aval) : val(aval), dis(adis) {}

    bool operator <(const cell& A) const {
        return dis > A.dis;
    }
};


priority_queue<cell> ql, qr;
int addl = 0, addr = 0;


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        wha[ a[i] ] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        b[n + i] = b[i];
        whb[ b[i] ] = i;
    }

    for (int i = 0; i < n; ++i)
        if (isLeft(a[i], 0)) {
            ql.push(cell(i - whb[ a[i] ], a[i]));
        } else {
            qr.push(cell(whb[ a[i] ] - i, a[i]));
        }          

    for (int sh = 0; sh < n; ++sh) {
        int ans = 1e9;
        cell tmp(0,0);
        while (ql.size() > 0) {
            tmp = ql.top();
            ans = min(ans, getit(tmp.val, sh));

            if (isLeft(tmp.val, sh)) {
                break;
            } else ql.pop();
        }

        while (qr.size() > 0) {
            tmp = qr.top();
            ans = min(ans, getit(tmp.val, sh));
            if (!isLeft(tmp.val, sh)) {
                break;
            } else {
                ql.push(cell(getit(tmp.val, sh) - addl,tmp.val));
                qr.pop();
            }
        }

        printf("%d\n", ans);

        ++addl;
        --addr;

        if (sh + 1 != n) {
            int nval = b[n + sh];
            int cdis = getit(nval, sh + 1);
            if (isLeft(nval, sh + 1)) {
                ql.push(cell(cdis - addl, nval));
            } else {
                qr.push(cell(cdis - addr, nval));
            }
        }
    }
    
    return 0;
}