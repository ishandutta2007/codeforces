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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const Int INF = 9001001001001001001LL;

typedef pair< pair<Int,Int>,pair<Int,Int> > answer_t;
map<Int,answer_t> cache;

int K;
Int P[110];
int E[110];

int dsLen;
Int ds[110010];
Int V;

void dfs(int i, Int d) {
    if (i == K) {
        ds[dsLen++] = d;
        return;
    }
    int j;
    for (j = 0; j <= E[i]; ++j) {
        dfs(i + 1, d);
        d *= P[i];
    }
}

Int es[110010];
int buckets[0x1000a];
void mySort() {
    int i, j;
    memset(buckets, 0, sizeof(buckets));
    for (i = 0; i < dsLen; ++i) ++buckets[(ds[i] & 0xffff) + 1];
    for (j = 0; j < 0x10000; ++j) buckets[j + 1] += buckets[j];
    for (i = 0; i < dsLen; ++i) es[buckets[(ds[i] & 0xffff)]++] = ds[i];
    memset(buckets, 0, sizeof(buckets));
    for (i = 0; i < dsLen; ++i) ++buckets[((es[i] >> 16) & 0xffff) + 1];
    for (j = 0; j < 0x10000; ++j) buckets[j + 1] += buckets[j];
    for (i = 0; i < dsLen; ++i) ds[buckets[((es[i] >> 16) & 0xffff)]++] = es[i];
    memset(buckets, 0, sizeof(buckets));
    for (i = 0; i < dsLen; ++i) ++buckets[((ds[i] >> 32) & 0xffff) + 1];
    for (j = 0; j < 0x10000; ++j) buckets[j + 1] += buckets[j];
    for (i = 0; i < dsLen; ++i) es[buckets[((ds[i] >> 32) & 0xffff)]++] = ds[i];
    memset(buckets, 0, sizeof(buckets));
    for (i = 0; i < dsLen; ++i) ++buckets[(es[i] >> 48) + 1];
    for (j = 0; j < 0x10000; ++j) buckets[j + 1] += buckets[j];
    for (i = 0; i < dsLen; ++i) ds[buckets[(es[i] >> 48)]++] = es[i];
}

int ysLen;
int ys[110010];

int main() {
    int i, j;
    int x, y, y2, y3;
    Int sm, am, bm, cm;
    
    for (int TC = in(); TC--; ) {
// if(!K){
        K = in();
        for (i = 0; i < K; ++i) {
            P[i] = In();
            E[i] = in();
        }
// }
        dsLen = 0;
        dfs(0, 1);
        V = ds[dsLen - 1];
        if (!cache.count(V)) {
            // sort(ds, ds + dsLen);
            mySort();
// cout<<"dsLen = "<<dsLen<<endl;
// cout<<"ds : ";pv(ds,ds+dsLen);
            sm = INF;
            am = bm = cm = -1;
            for (y = 0; ds[y] <= V / ds[y] / ds[y]; ++y);
            y3 = y;
            for (y = y3; ds[y] <= V / ds[y]; ++y);
            y2 = y;
            int yA = y3 - 1, yB = y3;
            ysLen = 0;
            for (; yA >= 0 || yB < y2; ) {
                if (yA >= 0) ys[ysLen++] = yA--;
                if (yB < y2) ys[ysLen++] = yB++;
            }
            for (j = 0; j < ysLen; ++j) {
                y = ys[j];
                Int b = ds[y];
                Int ac = ds[dsLen - 1 - y];
                for (x = y; x >= 0; --x) {
                    Int a = ds[x];
                    Int c = ac / a;
                    Int s = b * (a + c) + ac;
                    if (sm <= s) {
                        break;
                    }
                    if (ac % a == 0) {
                        if (sm > s) {
                            sm = s;
                            am = a;
                            bm = b;
                            cm = c;
                            break;
                        }
                    }
                }
            }
            cache[V] = mp(mp(sm * 2, am), mp(bm, cm));
        }
        answer_t res = cache[V];
        cout  
            << res.first.first   << " " 
            << res.first.second  << " " 
            << res.second.first  << " " 
            << res.second.second << endl;
    }
    
    return 0;
}