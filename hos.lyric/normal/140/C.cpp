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

#define MAXN 100010

int N;
int R[MAXN];

int M, X;
int rs[MAXN], as[MAXN];
int ans[MAXN][3];

int main() {
    int i, j;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            R[i] = in();
        }
        sort(R, R + N);
        M = 0;
        for (i = 0; i < N; i = j) {
            for (j = i; j < N && R[i] == R[j]; ++j);
            rs[M] = R[i];
            as[M] = j - i;
            ++M;
        }
//cout<<"as : ";pv(as,as+M);
        int lo = 0, ho = N + 1;
        for (; lo + 1 < ho; ) {
            int mo = (lo + ho) / 2;
            int sum = 0;
            for (i = 0; i < M; ++i) {
                sum += min(as[i], mo);
            }
            (sum >= mo * 3) ? (lo = mo) : (ho = mo);
        }
        priority_queue<pint> q;
        for (i = 0; i < M; ++i) {
            q.push(mp(as[i], rs[i]));
        }
        for (i = 0; i < lo; ++i) {
            pint ps[3];
            for (j = 0; j < 3; ++j) {
                ps[j] = q.top();
                q.pop();
            }
            for (j = 0; j < 3; ++j) {
                --ps[j].first;
                ans[i][j] = ps[j].second;
            }
            for (j = 0; j < 3; ++j) {
                q.push(ps[j]);
            }
        }
        printf("%d\n", lo);
        for (i = 0; i < lo; ++i) {
            sort(ans[i], ans[i] + 3, greater<int>());
            for (j = 0; j < 3; ++j) {
                if (j) printf(" ");
                printf("%d", ans[i][j]);
            }
            puts("");
        }
    }
    
    return 0;
}