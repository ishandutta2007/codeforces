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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAX 1010

int N, T;
int A[MAX][2];
int B[MAX][2];
int M;
char S[MAX][MAX];
int C[MAX];

int d[MAX][MAX];

int ansLen[MAX];
int ans[MAX][MAX];

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    int i, j;
    int s;
    
    for (; ~scanf("%d%d", &N, &T); ) {
        for (i = 0; i < N; ++i) {
            A[i][0] = in();
            B[i][0] = in();
            A[i][1] = in();
            B[i][1] = in();
        }
        M = in();
        for (j = 0; j < M; ++j) {
            scanf("%s", S[j]);
            C[j] = in();
        }
        memset(d, 0, sizeof(d));
        memset(ansLen, 0, sizeof(ansLen));
        deque<int> q;
        for (j = 0; j < M; ++j) {
            q.push_back(j);
        }
        for (; ; ) {
            for (s = 0; s < 2; ++s) for (i = 0; i < N; ++i) {
                int t = T;
                for (; t; ) {
                    if (q.empty()) goto done;
                    j = q.front(); q.pop_front();
                    int tmp = max(1, C[j] - (A[i][s] + B[i][s ^ 1]) - d[i][j]);
//cout<<s<<" "<<i<<" "<<j<<" : "<<tmp<<endl;
                    if (t >= tmp) {
                        t -= tmp;
                        ans[i][ansLen[i]++] = j;
                    } else {
                        d[i][j] += t;
                        q.push_back(j);
                        break;
                    }
                }
            }
        }
    done:;
assert(accumulate(ansLen,ansLen+N,0)==M);
        for (i = 0; i < N; ++i) {
            printf("%d", ansLen[i]);
            for (j = 0; j < ansLen[i]; ++j) {
                printf(" %s", S[ans[i][j]]);
            }
            puts("");
        }
//break;
    }
    
    return 0;
}