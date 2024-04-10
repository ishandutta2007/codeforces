//  Codeforces Beta Round #86

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

const int LIM = 20000;
int isnp[20010];
int psLen, ps[20010];

const int LIM2 = 300000000;
const int K = 1000000;
int cnt[310];

void prpr() {
    int i, j;
    for (i = 2; i * i < LIM; ++i) if (!isnp[i]) {
        for (j = i * i; j < LIM; j += i) isnp[j] = 1;
    }
    for (i = 2; i < LIM; ++i) if (!isnp[i]) {
        ps[psLen++] = i;
    }
}
bool isLucky(int n) {
    if (n < 2) return 0;
    if (n != 2 && n % 4 != 1) return 0;
    int i;
    for (i = 0; i < psLen && ps[i] < n; ++i) if (n % ps[i] == 0) return 0;
    return 1;
}

/*
int main() {
    int i;
    
    prpr();
    
    ++cnt[0];
    for (i = 5; i < LIM2; i += 4) {
        if (isLucky(i)) {
            ++cnt[i / K];
        }
    }
    for (i = 0; i < LIM2 / K; ++i) {
        printf("%d,", cnt[i]);
    }
    puts("");
    
    return 0;
}
//*/

//*
int prec[] = { 
39176,35241,33867,33219,32691,32139,31928,31499,31341,31080,30899,30913,30576,30405,30301,30139,30087,30002,29854,29814,29600,29719,29406,29422,29436,29274,29336,29150,29172,29094,29091,28875,28873,28902,28653,28729,28749,28687,28754,28595,28584,28417,28392,28489,28355,28315,28386,28313,28256,28258,28169,28080,28070,28052,28033,28035,27971,28017,27892,27899,27976,27713,27847,27868,27831,27821,27783,27794,27716,27699,27611,27660,27723,27534,27588,27680,27510,27458,27448,27443,27498,27578,27454,27448,27327,27347,27304,27472,27326,27266,27219,27227,27345,27189,27308,27228,27199,27167,27086,27143,27101,27097,27178,27021,27107,27013,26975,27086,27143,27133,26917,27074,26976,26792,26905,26928,26827,26892,26881,26925,26796,26823,26879,26934,26831,26788,26788,26857,26912,26781,26706,26816,26714,26709,26784,26590,26671,26605,26625,26836,26539,26668,26606,26717,26639,26632,26642,26559,26499,26563,26417,26555,26338,26617,26477,26456,26642,26415,26339,26483,26470,26399,26468,26593,26352,26354,26345,26398,26378,26469,26346,26372,26390,26434,26306,26359,26331,26390,26348,26469,26168,26342,26128,26258,26390,26251,26268,26241,26223,26395,25941,26110,26293,26226,26247,26183,26099,26034,26139,26190,26168,26268,26107,26223,26137,26001,26145,26052,25999,26168,26038,26225,26168,26057,26095,26173,26094,25948,25966,25999,25994,26045,26114,25971,26158,25913,26090,25813,25930,25903,25956,26020,26001,25825,25939,25950,26045,25925,26008,25808,26013,25938,25712,25883,25989,25900,25794,25760,25943,25783,25953,25667,25756,25915,25963,25824,25858,25833,25905,25729,25951,25770,25971,25767,25859,25928,25627,25767,25863,25623,25772,25706,25657,25806,25819,25724,25712,25735,25587,25726,25606,25780,25597,25743,25704,25615,25592,25770,25735,25588,25755,25680,25519,25692,25737,25552,25616,25639,25521,25530,
};

int A, B;

int main() {
    int i;
    
    prpr();
    
    for (; ~scanf("%d%d", &A, &B); ) {
        int a = A, b = B;
        int ans = 0;
        for (; a <= b && a % K != 0; ++a) {
            if (isLucky(a)) {
                ++ans;
            }
        }
        for (; a <= b && (b + 1) % K != 0; --b) {
            if (isLucky(b)) {
                ++ans;
            }
        }
        if (a <= b) {
            for (i = a / K; i <= b / K; ++i) {
                ans += prec[i];
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
//*/