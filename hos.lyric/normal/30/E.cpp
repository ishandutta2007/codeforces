//  Codeforces Beta Round #30
//  Problem E

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

namespace SA {
    #define MAXN 400010
    int n;
    char t[MAXN];
    int ki[MAXN], ik[MAXN], is[MAXN], hh;
    bool cmp(const int &a, const int &b) {
        return (a == b) ? 0 : (ik[a] != ik[b]) ? (ik[a] < ik[b]) : (ik[a + hh] < ik[b + hh]);
    }
    void makesa() {
        n = strlen(t);
        int i;
        for (i = 0; i <= n; ++i) ik[ki[i] = i] = t[i];
        is[0] = is[n] = hh = 0;
        sort(ki, ki + n + 1, cmp);
        for (hh = 1; is[n] != n; hh <<= 1) {
            sort(ki, ki + n + 1, cmp);
            for (i = 0; i < n; ++i) is[i + 1] = is[i] + (cmp(ki[i], ki[i + 1]) ? 1 : 0);
            for (i = 0; i <= n; ++i) ik[ki[i]] = is[i];
        }
    }
    int lcp[MAXN];
    void makeha() {
        int h = 0, i, j;
        for (i = 0; i < n; ++i) {
            for (j = ki[ik[i] - 1]; t[j + h] == t[i + h]; ++h);
            lcp[ik[i] - 1] = h;
            if (h) --h;
        }
    }
}

int palindrome(char t[], int r[]) {
    int nn = strlen(t) << 1;
    int i, j, k;
    for (i = j = 0; i < nn; i += k, j = max(j - k, 0)) {
        for (; 0 <= i - j && i + j + 1 < nn && t[i - j >> 1] == t[i + j + 1 >> 1]; ++j);
        r[i] = j;
        for (k = 1; 0 <= i - k && 0 <= j - k && r[i - k] != j - k; ++k) {
            r[i + k] = min(r[i - k], j - k);
        }
    }
    return nn;
}

int L;
int top[MAXN];
int r[MAXN], R[MAXN];

int segn, seg[MAXN];
void seg_init() {
    int i;
    for (segn = 1; segn < L; segn <<= 1);
    for (i = 0; i < segn; ++i) {
        seg[i + segn] = i;
    }
    for (i = segn; --i; ) {
        seg[i] = (R[seg[i << 1]] >= R[seg[i << 1 | 1]]) ? seg[i << 1] : seg[i << 1 | 1];
    }
}
int seg_range_max(int a, int b) {
    int ret = a;
    for (a += segn, b += segn; a <= b; a >>= 1, b >>= 1) {
        if ( a & 1) { if (R[ret] < R[seg[a]]) ret = seg[a]; ++a; }
        if (~b & 1) { if (R[ret] < R[seg[b]]) ret = seg[b]; --b; }
    }
    return ret;
}

int main() {
    using namespace SA;
    
    int i, j;
    int back;
    int now;
    
    scanf("%s", t);
    L = strlen(t);
    
    palindrome(t, r);
    
    t[L] = 1;
    for (i = 0; i < L; ++i) {
        t[L * 2 - i] = t[i];
    }
    makesa();
    makeha();
//for(i=0;i<=n;++i)cout<<t+ki[i]<<endl;
//pv(lcp,lcp+n);
    
    back = ik[L + 1];
//cout<<t+ki[back]<<endl;
    
    for (i = 0; i <= L; ++i) {
        top[i] = L;
    }
    now = L / 2;
    for (i = back - 1; i >= 0; --i) {
        chmin(now, lcp[i]);
        chmin(top[now], ki[i]);
    }
    now = L / 2;
    for (i = back + 1; i <= n; ++i) {
        chmin(now, lcp[i - 1]);
        chmin(top[now], ki[i]);
    }
    for (i = L; i--; ) {
        chmin(top[i], top[i + 1]);
    }
//pv(top,top+L);
    
    for (i = 0; i < L; ++i) {
        R[i] = r[i * 2] / 2;
    }
    seg_init();
//pv(R,R+L);
//pv(seg,seg+segn*2);
    
    int ans = 0, tmp;
    int ans0, ans1, ans2, ans3, ans4, ans5;
    int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
    ans0 = ans1 = ans2 = ans3 = ans4 = ans5 = 0;
        
    for (i = 0; i <= L; ++i) if (top[i] < L - i) {
        tmp0 = top[i];
        tmp1 = top[i] + i;
        tmp4 = L - i;
        tmp5 = L;
        int a = tmp1, b = tmp4 - 1;
        if (a <= b) {
            int lo = 0, ho = (b - a) / 2 + 1;
            for (; lo + 1 < ho; ) {
                int mo = (lo + ho) >> 1;
                j = seg_range_max(a + mo, b - mo);
//cout<<"range_max "<<a+mo<<" "<<b-mo<<" : "<<j<<endl;
                (R[j] >= mo) ? lo = mo : ho = mo;
            }
            j = seg_range_max(a + lo, b - lo);
            tmp2 = j - lo;
            tmp3 = j + lo + 1;
            tmp = (tmp1 - tmp0) + (tmp3 - tmp2) + (tmp5 - tmp4);
//cout<<"i = "<<i<<endl;
//cout<<tmp0<<" "<<tmp1<<" . "<<tmp2<<" "<<tmp3<<" . "<<tmp4<<" "<<tmp5<<endl;
            if (ans < tmp) {
                ans = tmp;
                ans0 = tmp0;
                ans1 = tmp1;
                ans2 = tmp2;
                ans3 = tmp3;
                ans4 = tmp4;
                ans5 = tmp5;
            }
        }
    }
    
    if (ans0 < ans1) {
        puts("3");
        printf("%d %d\n", ans0 + 1, ans1 - ans0);
        printf("%d %d\n", ans2 + 1, ans3 - ans2);
        printf("%d %d\n", ans4 + 1, ans5 - ans4);
    } else {
        puts("1");
        printf("%d %d\n", ans2 + 1, ans3 - ans2);
    }
    
    return 0;
}