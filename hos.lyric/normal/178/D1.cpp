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

int N;
int A[20];
int S;
int B[20][20];

int main() {
    int i;
    int x, y, z;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N * N; ++i) {
            A[i] = in();
        }
        sort(A, A + N);
        S = accumulate(A, A + N * N, 0) / N;
        if (N <= 3) {
            do {
                for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
                    B[x][y] = A[x * N + y];
                }
                for (x = 0; x < N; ++x) {
                    int sum = 0;
                    for (y = 0; y < N; ++y) sum += B[x][y];
                    if (sum != S) goto failed;
                }
                for (y = 0; y < N; ++y) {
                    int sum = 0;
                    for (x = 0; x < N; ++x) sum += B[x][y];
                    if (sum != S) goto failed;
                }
                for (z = 0; z < 2; ++z) {
                    int sum = 0;
                    for (x = 0; x < N; ++x) sum += B[x][z ? (N - 1 - x) : x];
                    if (sum != S) goto failed;
                }
                break;
            failed:;
            } while (next_permutation(A, A + N * N));
        } else {
            
        }
        printf("%d\n", S);
        for (x = 0; x < N; ++x) {
            for (y = 0; y < N; ++y) {
                if (y) printf(" ");
                printf("%d", B[x][y]);
            }
            puts("");
        }
    }
    
    return 0;
}