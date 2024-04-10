//  Codeforces Beta Round #72

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

int N;
Int K;
Int A[100010];
Int as[100010];

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        K = In();
        for (i = 0; i < N; ++i) {
            A[i] = In();
        }
        for (i = 0; i < N; ++i) {
            as[i] = A[i];
        }
        sort(as, as + N);
        Int d = 0;
        for (i = 0; i < N; ++i) {
            if (K > (as[i] - d) * (N - i)) {
                K -= (as[i] - d) * (N - i);
                d = as[i];
            } else {
                break;
            }
        }
        if (i == N) {
            puts("-1");
            continue;
        }
//cout<<"d = "<<d<<", "<<"i = "<<i<<endl;
//cout<<"K = "<<K<<endl;
        d += K / (N - i);
        K %= N - i;
        queue<int> q;
        for (i = 0; i < N; ++i) {
            if (A[i] > d) {
                q.push(i);
            }
        }
        for (; K--; ) {
            i = q.front();
            q.pop();
            if (A[i] > d + 1) {
                q.push(i);
            }
        }
        int ou = 0;
        for (; !q.empty(); ) {
            if (ou++) putchar(' ');
            printf("%d", q.front() + 1);
            q.pop();
        }
        puts("");
    }
    
    return 0;
}