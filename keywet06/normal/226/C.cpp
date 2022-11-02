#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int m[N][N] = {0};
int p[N][N] = {0};

void mpow(long long pw, int n, int mmod) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) m[i][j] = (i == j);
    }
    for (int bt = 62; bt >= 0; bt--) {
        {
            int q[N][N] = {0};
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        q[i][j] =
                            (q[i][j] + m[i][k] * (long long)m[k][j]) % mmod;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) m[i][j] = q[i][j];
            }
        }
        if (pw & (1LL << bt)) {
            int q[N][N] = {0};
            for (int i = 0; i < n; ++i) {
                for (int k = 0; k < n; ++k) {
                    for (int j = 0; j < n; ++j) {
                        q[i][j] =
                            (q[i][j] + m[i][k] * (long long)p[k][j]) % mmod;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) m[i][j] = q[i][j];
            }
        }
    }
}

int main() {
    int mm;
    long long l, r, k;
    cin >> mm >> l >> r >> k;
    long long mmin = 1;
    long long mmax = r;
    while (mmin < mmax) {
        long long mmid = (mmin + mmax + 1) / 2;
        long long cnt = r / mmid - (l - 1) / mmid;
        if (cnt >= k) {
            mmin = mmid;
        } else {
            mmax = mmid - 1;
        }
    }
    while (r / mmin > 1) {
        int ok = 0;
        for (int trial = min(10LL, r / mmin - 1); trial >= 1; trial--) {
            long long next = r / (r / mmin - trial);
            if (next > mmin && r / next - (l - 1) / next >= k) {
                mmin = next;
                ok = 1;
                break;
            }
        }
        if (!ok) break;
    }
    p[0][0] = p[0][1] = p[1][0] = 1;
    p[1][1] = 0;
    mpow(mmin, 2, mm);
    cout << m[1][0] << endl;
    return 0;
}