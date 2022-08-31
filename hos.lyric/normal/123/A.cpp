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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int LIM = 1005;
int isnp[1010];
void prpr() {
    int i, j;
    isnp[0] = isnp[1] = 1;
    for (i = 2; i * i < LIM; ++i) if (!isnp[i]) {
        for (j = i * i; j < LIM; j += i) isnp[j] = 1;
    }
}

int uf[1010];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

void gen(int n) {
    int p, i;
    memset(uf, ~0, n << 2);
    for (p = 2; p <= n; ++p) if (!isnp[p]) {
        for (i = 1; i <= n / p; ++i) {
            conn(p - 1, p * i - 1);
        }
    }
}

const int M = 0x100;

int N;
char S[1010];
char T[1010];

pint ps[1010];

int qsLen;
pint qs[1010];

int main() {
    int i;
    int c;
    
    prpr();
    
/*
for(int n=1;n<=1000;++n){
gen(n);
int cnt=0;for(i=0;i<n;++i)if(-uf[i]>1)++cnt;
if(cnt!=1)cout<<"n = "<<n<<endl;
if(n<=5){cout<<"uf : ";pv(uf,uf+n);}
}
//*/
    
    for (; ~scanf("%s", S); ) {
        N = strlen(S);
        gen(N);
        for (c = 0; c < M; ++c) {
            ps[c] = mp(0, c);
        }
        for (i = 0; i < N; ++i) {
            ++ps[S[i] - 0].first;
        }
        sort(ps, ps + M, greater<pint>());
        qsLen = 0;
        for (i = 0; i < N; ++i) if (uf[i] < 0) {
            qs[qsLen++] = mp(-uf[i], i);
        }
        sort(qs, qs + qsLen, greater<pint>());
        if (ps[0].first < qs[0].first) {
            puts("NO");
            continue;
        }
        for (i = 0; i < N; ++i) if (root(i) == qs[0].second) {
            T[i] = ps[0].second;
            --ps[0].first;
        }
        int j = 0;
        for (i = 0; i < N; ++i) if (root(i) != qs[0].second) {
            for (; ps[j].first == 0; ++j);
            T[i] = ps[j].second;
            --ps[j].first;
        }
        T[N] = 0;
        puts("YES");
        puts(T);
    }
    
    return 0;
}