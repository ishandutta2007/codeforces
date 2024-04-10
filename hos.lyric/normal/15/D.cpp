//  Codeforces Beta Round #15
//  Problem D

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

const int bitn = 1005;
int bit[1010][1010];
void bit_incr(int idx, int idy) {
    for (int x = idx; x <= bitn; x += x & -x) for (int y = idy; y <= bitn; y += y & -y) {
        ++bit[x][y];
    }
}
int bit_cal(int idx, int idy) {
    int sum = 0;
    for (int x = idx; x > 0; x &= x - 1) for (int y = idy; y > 0; y &= y - 1) {
        sum += bit[x][y];
    }
    return sum;
}

int M, N, A, B;
Int P[1010][1010], S[1010][1010];
Int yoko[1010][1010], waku[1010][1010];

pair<Int,int> que[1010], *qb, *qe;

int L;
pair<Int,pint> es[1000010];
int len;
Int ans[1000010][3];

void Out(Int x) {
    if (x >= 10) Out(x / 10);
    putchar('0' + x % 10);
}

int main() {
    int x, y;
    Int c;
    
    M = in();
    N = in();
    A = in();
    B = in();
    for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
        P[x][y] = in();
        S[x + 1][y + 1] = S[x][y + 1] + S[x + 1][y] - S[x][y] + P[x][y];
    }
    for (x = 0; x < M; ++x) {
        qb = qe = que;
        for (y = 0; y < B; ++y) {
            for (; qe - qb >= 1 && (qe - 1)->first >= P[x][y]; --qe);
            *qe++ = mp(P[x][y], y);
        }
        for (y = 0; y <= N - B; ++y) {
            yoko[x][y] = qb->first;
            if (qb->second == y) ++qb;
            for (; qe - qb >= 1 && (qe - 1)->first >= P[x][y + B]; --qe);
            *qe++ = mp(P[x][y + B], y + B);
        }
    }
    for (y = 0; y <= N - B; ++y) {
        qb = qe = que;
        for (x = 0; x < A; ++x) {
            for (; qe - qb >= 1 && (qe - 1)->first >= yoko[x][y]; --qe);
            *qe++ = mp(yoko[x][y], x);
        }
        for (x = 0; x <= M - A; ++x) {
            waku[x][y] = qb->first;
            if (qb->second == x) ++qb;
            for (; qe - qb >= 1 && (qe - 1)->first >= yoko[x + A][y]; --qe);
            *qe++ = mp(yoko[x + A][y], x + A);
        }
    }
//for(x=0;x<M;++x)pv(yoko[x],yoko[x]+N-B+1);
//for(x=0;x<=M-A;++x)pv(waku[x],waku[x]+N-B+1);
    
    priority_queue< pair<Int,pint> > q;
    for (x = 0; x <= M - A; ++x) for (y = 0; y <= N - B; ++y) {
        es[L++] = mp((S[x + A][y + B] - S[x][y + B] - S[x + A][y] + S[x][y]) - waku[x][y] * A * B, mp(x, y));
    }
    sort(es, es + L);
    for (int j = 0; j < L; ++j) {
        c = es[j].first;
        x = es[j].second.first;
        y = es[j].second.second;
        if (bit_cal(x + A, y + B) - bit_cal(x, y + B) - bit_cal(x + A, y) + bit_cal(x, y) == 0) {
            bit_incr(x + 1, y + 1);
            bit_incr(x + 1, y + B);
            bit_incr(x + A, y + 1);
            bit_incr(x + A, y + B);
            ans[len][0] = x + 1;
            ans[len][1] = y + 1;
            ans[len][2] = c;
            ++len;
        }
    }
    
    printf("%d\n", len);
    for (int j = 0; j < len; ++j) {
        Out(ans[j][0]); putchar(' ');
        Out(ans[j][1]); putchar(' ');
        Out(ans[j][2]); puts("");
    }
    
    return 0;
}