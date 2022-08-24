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

char CS[] = "GR";

int M, N, K;
char A[110][110];

bool isFree(int x, int s) {
    int y;
    int cntS = 0, cntT = 0;
    for (y = 0; y < N; ++y) {
        if (A[x][y] == CS[s    ]) ++cntS;
        if (A[x][y] == CS[s ^ 1]) ++cntT;
    }
    return (cntT == 0 && 0 < cntS && cntS < N);
}
int isRoom(int x) {
    int y;
    int s;
    int pos[2];
    for (s = 0; s < 2; ++s) {
        pos[s] = -1;
    }
    for (y = 0; y < N; ++y) {
        for (s = 0; s < 2; ++s) {
            if (A[x][y] == CS[s]) {
                pos[s] = y;
            }
        }
    }
    if (!~pos[0] || !~pos[1]) return -1;
    return abs(pos[0] - pos[1]) - 1;
}

int solve() {
    int x;
    int s;
/*
cout<<"isFree0 : ";for(x=0;x<M;++x)cout<<isFree(x,0)<<" ";cout<<endl;
cout<<"isFree1 : ";for(x=0;x<M;++x)cout<<isFree(x,1)<<" ";cout<<endl;
cout<<"isRoom  : ";for(x=0;x<M;++x)cout<<isRoom(x  )<<" ";cout<<endl;
//*/
    bool win[2];
    for (s = 0; s < 2; ++s) {
        win[s] = 0;
    }
    for (x = 0; x < M; ++x) {
        for (s = 0; s < 2; ++s) {
            if (isFree(x, s)) {
                win[s] = 1;
            }
        }
    }
    if (win[0] && win[1]) return 0;
    if (win[0]) return +2;
    if (win[1]) return -2;
    int nim[20] = {};
    int i;
    for (x = 0; x < M; ++x) {
        int r = isRoom(x);
        if (~r) {
            for (i = 0; i < 10; ++i) if (r & 1 << i) ++nim[i];
        }
    }
    for (i = 0; i < 10; ++i) {
        if (nim[i] % (K + 1) != 0) {
            return +1;
        }
    }
    return -1;
}

int main() {
    int x;
    
    for (; ~scanf("%d%d%d", &M, &N, &K); ) {
        for (x = 0; x < M; ++x) {
            scanf("%s", A[x]);
        }
        int res = solve();
        puts((res > 0) ? "First" : (res < 0) ? "Second" : "Draw");
    }
    
    return 0;
}