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

const int INF = 1001001001;

int N;
struct Matrix {
    int v[310][310];
    Matrix &operator*=(const Matrix &a) {
        Matrix b;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
            b.v[i][j] = (i != j) ? INF : 0;
        }
        for (int i = 0; i < N; ++i) for (int k = 0; k < N; ++k) for (int j = 0; j < N; ++j) {
            chmin(b.v[i][j], v[i][k] + a.v[k][j]);
        }
        return *this = b;
    }
    Matrix operator*(const Matrix &a) const { return Matrix(*this) *= a; }
};
ostream &operator<<(ostream &os, const Matrix &a) {
    os << "[";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) os << " " << a.v[i][j];
        os << ";";
    }
    os << " ]";
    return os;
}

int M;
Matrix D;
Matrix Ds[10];

int main() {
    int i, u, v;
    int c;
    int k, x;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
            D.v[u][v] = (u != v) ? INF : 0;
        }
        for (i = 0; i < M; ++i) {
            u = in() - 1;
            v = in() - 1;
            c = -in();
            chmin(D.v[u][v], c);
            c = -in();
            chmin(D.v[v][u], c);
        }
        Ds[0] = D;
        for (k = 1; k <= 8; ++k) Ds[k] = Ds[k - 1] * Ds[k - 1];
        Matrix d, dd;
        for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
            d.v[u][v] = (u != v) ? INF : 0;
        }
        x = 0;
        for (k = 8; k >= 0; --k) {
            dd = d * Ds[k];
            for (u = 0; u < N; ++u) if (dd.v[u][u] < 0) break;
            if (u == N) {
                d = dd;
                x |= 1 << k;
            }
        }
        int ans = (x + 1 <= N) ? (x + 1) : 0;
        printf("%d\n", ans);
    }
    
    return 0;
}