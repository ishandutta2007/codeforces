#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

typedef vector< vector<int> > Matrix;

Matrix multiply(const Matrix &A, const Matrix &B) {
    assert(A[0].size() == B.size());
    Matrix C(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < B.size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

Matrix power(const Matrix &A, int p) {
    assert(p >= 1);
    if (p == 1) return A;
    if (p % 2 == 1) return multiply(power(A, p - 1), A);
    return power(multiply(A, A), p / 2);
}


int n, m;

vector<char> used(20, false);
void delcat(Matrix &mat, int x, int y) {
    int pos = m * x + y;
    used[pos] = false;
    for (int i = 0; i < n * m; i++) {
        int nx = i / m, ny = i % m;
        if (abs(nx - x) + abs(ny - y) <= 1 && !used[i]) {
            mat[pos][i] = mat[i][pos] = 1;
        }
    }
}

void addcat(Matrix &mat, int x, int y) {
    int pos = m * x + y;
    used[pos] = true;
    for (int i = 0; i < n * m; i++) {
        mat[pos][i] = mat[i][pos] = 0;
    }
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> n >> m >> q;

    Matrix v(n * m, vector<int>(1));
    v[0][0] = 1;

    Matrix mat(n * m, vector<int>(n * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            delcat(mat, i, j);
        }
    }

    int prevt = 1;
    for (int times = 0; times < q; times++) {
        int tp, x, y, curt;
        cin >> tp >> x >> y >> curt;
        x--; y--;
        if (curt > prevt) {
            v = multiply(power(mat, curt - prevt), v);
            prevt = curt;
        }
        if (tp == 1) {
            cout << v[x * m + y][0] << '\n';
        } else if (tp == 2) {
            addcat(mat, x, y);
        } else {
            delcat(mat, x, y);
        }
    }
}