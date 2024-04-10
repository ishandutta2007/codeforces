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

int M, N;
int A[110][110], AA[110][110];
int B[3];

int sum[110];

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    int i;
    int x, y;
    int xa, xb;
    
    for (; ~scanf("%d%d", &M, &N); ) {
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            A[x][y] = in();
        }
        for (i = 0; i < 3; ++i) {
            B[i] = in();
        }
        sort(B, B + 3);
        int ans = 0;
        for (int phase = 0; phase < 2; ++phase) {
            for (x = 0; x < M; ++x) {
                sum[x + 1] = sum[x] + accumulate(A[x], A[x] + N, 0);
            }
            for (xa = 1; xa < M; ++xa) for (xb = xa + 1; xb < M; ++xb) {
                int bs[] = { sum[xa], sum[xb] - sum[xa], sum[M] - sum[xb] };
                sort(bs, bs + 3);
                for (i = 0; i < 3; ++i) if (B[i] != bs[i]) break;
                if (i == 3) ++ans;
            }
            for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) AA[x][y] = A[x][y];
            swap(M, N);
            for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) A[x][y] = AA[y][x];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}