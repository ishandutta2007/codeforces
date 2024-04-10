//  Codeforces Beta Round #71

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

Int Abs(Int x) { return (x < 0) ? -x : x; }

int N, A, B, C;
int X[4], Y[4];
Int T;
char ans[400010];

Int calcSum(Int a, Int b) {
//cout<<"    calcSum "<<a<<" "<<b<<" : "<<(a + b) * (Abs(a - b) + 1) / 2 - a<<endl;
    return (a + b) * (Abs(a - b) + 1) / 2 - a;
}
void monotone(int ax, int ay, int bx, int by, Int ts[]) {
//cout<<"  monotone "<<ax<<" "<<ay<<" "<<bx<<" "<<by<<endl;
    int i;
    for (i = 0; i < 4; ++i) {
        ts[i] -= calcSum(Abs(X[i] - ax) + Abs(Y[i] - ay), Abs(X[i] - bx) + Abs(Y[i] - by));
    }
}
bool judge(Int ts[]) {
    int i;
    for (i = 0; i < 4; ++i) if (ts[i] < 0) return 0;
    return 1;
}
bool check2(int px, int py, Int ts[]) {
//cout<<"  check2 "<<px<<" "<<py<<"  ";pv(ts,ts+4);
    Int tRes[4];
    Int a, b, c, d, e;
    if (!judge(ts)) return 0;
    memset(tRes, 0, sizeof(tRes));
    monotone(px, py, X[3], Y[3], tRes);
    if (ts[0] + tRes[0] < 0) return 0;
    if (ts[3] + tRes[3] < 0) return 0;
    memset(tRes, 0, sizeof(tRes));
    monotone(px, py, X[3], py, tRes);
    monotone(X[3], py, X[3], Y[3], tRes);
    a = -tRes[1]; b = -tRes[2];
    memset(tRes, 0, sizeof(tRes));
    monotone(px, py, px, Y[3], tRes);
    monotone(px, Y[3], X[3], Y[3], tRes);
    c = -tRes[1]; d = -tRes[2];
    assert(a + b == c + d);
    if (ts[1] < c) return 0;
    if (ts[2] < b) return 0;
    e = ts[1]; if ((e - c) % 2 != 0) --e;
    if (e > a) e = a;
    if (ts[1] < e) return 0;
    if (ts[2] < a + b - e) return 0;
    return 1;
}
bool check(int px, int py, Int ts[]) {
//cout<<"check "<<px<<" "<<py<<"  ";pv(ts,ts+4);
    int i;
    Int tts[4];
    bool ret = 0;
    for (i = 0; i < 4; ++i) tts[i] = ts[i];
    if (!judge(tts)) return 0;
    if (px < X[0]) {
        if (py < Y[0]) {
            monotone(px, py, X[0], Y[0], tts);
            monotone(X[3], Y[3], N, N, tts);
            ret = check2(X[0], Y[0], tts);
        } else if (py < Y[3]) {
            monotone(px, py, X[0], py, tts);
            monotone(X[3], Y[3], N, N, tts);
            ret = check2(X[0], py, tts);
        } else {
            monotone(px, py, X[0], py, tts);
            monotone(X[0], py, X[3], py, tts);
            monotone(X[3], py, N, N, tts);
            ret = judge(tts);
        }
    } else if (px < X[3]) {
        if (py < Y[0]) {
            monotone(px, py, px, Y[0], tts);
            monotone(X[3], Y[3], N, N, tts);
            ret = check2(px, Y[0], tts);
        } else if (py < Y[3]) {
            monotone(X[3], Y[3], N, N, tts);
            ret = check2(px, py, tts);
        } else {
            monotone(px, py, X[3], py, tts);
            monotone(X[3], py, N, N, tts);
            ret = judge(tts);
        }
    } else {
        if (py < Y[0]) {
            monotone(px, py, px, Y[0], tts);
            monotone(px, Y[0], px, Y[3], tts);
            monotone(px, Y[3], N, N, tts);
            ret = judge(tts);
        } else if (py < Y[3]) {
            monotone(px, py, px, Y[3], tts);
            monotone(px, Y[3], N, N, tts);
            ret = judge(tts);
        } else {
            monotone(px, py, N, N, tts);
            ret = judge(tts);
        }
    }
//cout<<" ret = "<<ret<<endl;
    return ret;
}

int main() {
    int i, j;
    int px, py;
    Int ts[4];
    
    for (; ~scanf("%d", &N) && N; ) {
        T = In();
        A = in();
        B = in();
        C = in();
        for (i = 0; i < 4; ++i) {
            X[i] = A + (C - 1) * (i >> 1);
            Y[i] = B + (C - 1) * (i & 1);
            ts[i] = T;
        }
        px = py = 1;
        for (j = 0; j < N * 2 - 2; ++j) {
            ++px;
            for (i = 0; i < 4; ++i) ts[i] -= abs(X[i] - px) + abs(Y[i] - py);
            if (px <= N && check(px, py, ts)) { ans[j] = 'R'; continue; }
            for (i = 0; i < 4; ++i) ts[i] += abs(X[i] - px) + abs(Y[i] - py);
            --px;
            ++py;
            for (i = 0; i < 4; ++i) ts[i] -= abs(X[i] - px) + abs(Y[i] - py);
            if (py <= N && check(px, py, ts)) { ans[j] = 'U'; continue; }
            for (i = 0; i < 4; ++i) ts[i] += abs(X[i] - px) + abs(Y[i] - py);
            --py;
            puts("Impossible");
            goto failed;
        }
        ans[j] = 0;
        puts(ans);
    failed:;
    }
    
    return 0;
}