//  Codeforces Beta Round 66

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

#define MAXN 100010

char buf[110];

int N, M, I;
map<string,int> tr;
string S[MAXN];
int A[MAXN];
int P[MAXN];

int pslen;
pair<int,string> ps[MAXN];

int solve_strong() {
    int i;
    pslen = 0;
    for (i = 0; i < N; ++i) if (i != I) {
        ps[pslen++] = mp(-A[i], S[i]);
    }
    sort(ps, ps + pslen);
    int score = A[I] + P[N - 1];
    multiset<int> pp;
    for (i = 0; i < N - 1; ++i) {
        pp.insert(-P[i]);
    }
    int cnt = 0;
    for (i = 0; i < pslen; ++i) {
        int allow = score - (-ps[i].first);
        if (ps[i].second < S[I]) --allow;
        multiset<int>::iterator it = pp.lower_bound(-allow);
        if (it == pp.end()) {
            ++cnt;
            pp.erase(pp.begin());
        } else {
            pp.erase(it);
        }
    }
    return cnt + 1;
}
int solve_weak() {
    int i;
    pslen = 0;
    for (i = 0; i < N; ++i) if (i != I) {
        ps[pslen++] = mp(A[i], S[i]);
    }
    sort(ps, ps + pslen);
    int score = A[I] + P[0];
    multiset<int> pp;
    for (i = 1; i < N; ++i) {
        pp.insert(P[i]);
    }
    int cnt = 0;
    for (i = 0; i < pslen; ++i) {
        int allow = score - ps[i].first;
        if (ps[i].second > S[I]) ++allow;
        multiset<int>::iterator it = pp.lower_bound(allow);
        if (it == pp.end()) {
            ++cnt;
            pp.erase(pp.begin());
        } else {
            pp.erase(it);
        }
    }
    return N - cnt;
}

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            scanf("%s%d", buf, &A[i]);
            S[i] = buf;
            tr[buf] = i;
        }
        
        M = in();
        for (i = 0; i < M; ++i) {
            P[i] = in();
        }
        for (i = M; i < N; ++i) {
            P[i] = 0;
        }
        sort(P, P + N);
        
        scanf("%s", buf);
        I = tr[buf];
        
        int ansS = solve_strong();
        int ansW = solve_weak();
        printf("%d %d\n", ansS, ansW);
        
    }
    
    return 0;
}