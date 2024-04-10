#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 300300;
const int inf = 1000000009;
const int mod = 1000000009;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct matrix {
    int a[3][3];
    
    matrix operator* (const matrix &m) {
        matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    res.a[i][j] = (res.a[i][j] + 1LL * a[i][k] * m.a[k][j]) % mod;
                }
            }
        }
        return res;
    }
};

int n, m;
int a[maxn];
int t[4 * maxn];
int b[4 * maxn][2];
int fib[maxn];
matrix mtrx[maxn];

int T[maxn], L[maxn], R[maxn];

void build(int v, int tl, int tr) {
    b[v][0] = b[v][1] = 0;
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
}


void push(int v, int tl, int tr) {
    if (b[v][0] != 0 || b[v][1] != 0) {
        //int c = (1LL * b[v][0] * mtrx[tr - tl + 2].a[0][0] + 1LL * b[v][1] * mtrx[tr - tl + 2].a[1][0] - 1LL + mod) % mod;
        int len = tr - tl + 1;
        int c = (1LL * b[v][0] * mtrx[len].a[0][2] + 1LL * b[v][1] * mtrx[len].a[1][2]) % mod;
        t[v] = (t[v] + c) % mod;
        if (tl != tr) {
            for (int k = 0; k < 2; k++) {
                b[v * 2][k] = (b[v * 2][k] + b[v][k]) % mod;
            }
            int c[2];
            int len = (tl + tr) / 2 - tl + 1;
            c[0] = (1LL * b[v][0] * mtrx[len].a[0][0] + 1LL * b[v][1] * mtrx[len].a[1][0]) % mod;
            c[1] = (1LL * b[v][0] * mtrx[len].a[0][1] + 1LL * b[v][1] * mtrx[len].a[1][1]) % mod;
            for (int k = 0; k < 2; k++) {
                b[v * 2 + 1][k] = (b[v * 2 + 1][k] + c[k]) % mod;
            }
        } //else a[tl] = (a[tl] + b[v][0]) % mod;
        b[v][0] = b[v][1] = 0;
    }
}

void upd(int v, int tl, int tr, int l, int r, int x, int y) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
        b[v][0] += x;
        b[v][1] += y;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v * 2, tl, tm, l, min(r, tm), x, y);
            int c[2];
            int len = max(0, tm - l + 1);
            c[0] = (1LL * x * mtrx[len].a[0][0] + 1LL * y * mtrx[len].a[1][0]) % mod;
            c[1] = (1LL * x * mtrx[len].a[0][1] + 1LL * y * mtrx[len].a[1][1]) % mod;
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, c[0], c[1]);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
}

int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) >> 1;
    return (get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % mod;
}

void dopush(int v, int tl, int tr) {
    push(v, tl, tr);
    if (tl == tr) return;
    int tm = (tl + tr) >> 1;
    dopush(v * 2, tl, tm);
    dopush(v * 2 + 1, tm + 1, tr);
}

bool reading() {
    if (!(cin >> n >> m)) return 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> T[i] >> L[i] >> R[i], L[i]--, R[i]--;
    return 1;
}

void print(vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++) cout << v[i] << endl;
}

vector<int> fastsolve() {
    vector<int> ans;
    build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        if (T[i] == 1) {
            upd(1, 0, n - 1, L[i], R[i], 1, 1);
        }
        if (T[i] == 2) {
            ans.push_back(get(1, 0, n - 1, L[i], R[i]));
        }
        //dopush(1, 0, n - 1);
        //for (int j = 0; j < n; j++) cout << a[j] << " \n"[j + 1 == n];
    }
    return ans;
}

int A[maxn];

vector<int> slowsolve() {
    for (int i = 0; i < n; i++) A[i] = a[i];
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (T[i] == 1) {
            for (int j = L[i]; j <= R[i]; j++) {
                A[j] = (A[j] + fib[j - L[i]]) % mod;
            }
        }
        if (T[i] == 2) {
            int res = 0;
            for (int j = L[i]; j <= R[i]; j++) {
                res = (A[j] + res) % mod;
            }
            ans.push_back(res);
        }
    }
    return ans;
}

void gen() {
    n = 300000;
    m = 300000;
    for (int i = 0; i < n; i++) a[i] = rand() % 1;
    for (int i = 0; i < m; i++) {
        T[i] = rand() % 2 + 1;
        L[i] = rand() % n;
        R[i] = rand() % n;
        if (L[i] > R[i]) swap(L[i], R[i]);
    }
}

void stress(bool f) {
    if (!f) return;
    for (int it = 0;; it++) {
        cerr << " " << it << endl;
        if (it == 8) {
            it--;
            it++;
        }
        gen();
        vector<int> ans1 = fastsolve();
        //vector<int> ans2 = slowsolve();
        vector<int> ans2 = ans1;
        if (ans1 != ans2) {
            print(ans1);
            print(ans2);
            cout << n << " " << m << endl;
            for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
            for (int i = 0; i < m; i++) cout << T[i] << " " << L[i] << " " << R[i] << endl;
            break;
        }
    }
    exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) mtrx[0].a[i][j] = i == j;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) mtrx[1].a[i][j] = i != 0 || j != 0;
    mtrx[1].a[1][2] = mtrx[1].a[2][0] = mtrx[1].a[2][1] = 0;
    mtrx[1].a[0][2] = mtrx[1].a[2][2] = 1;
    
    for (int i = 2; i < maxn; i++) mtrx[i] = mtrx[i - 1] * mtrx[1];
    fib[0] = fib[1] = 1;
    for (int i = 2; i < maxn; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    ios_base::sync_with_stdio(0);
    
    stress(0);
    
    while (reading()) print(fastsolve());
    
    return 0;
}