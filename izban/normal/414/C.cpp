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


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, mxh;
ll inv[30], ainv[30];
int A[maxn], X[maxn];
int a[maxn], b[maxn];

void mySort(int l, int r, int h) {
    mxh = max(mxh, h);
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    mySort(l, m, h + 1);
    mySort(m + 1, r, h + 1);
    
    ll cinv = 0;
    int i = l, j = m + 1, cnt = 0;
    while (i <= m || j <= r) {
        if (j <= r && (i == m + 1 || a[j] < a[i])) {
            cinv += m - i + 1;
            b[cnt++] = a[j++];
        } else {
            b[cnt++] = a[i++];
        }
    }
    
    ll all = 1LL * (cnt / 2) * (cnt / 2);
    int j1 = m + 1, j2 = m + 1;
    for (int i = l; i <= m; i++) {
        while (j1 <= r && a[j1] < a[i]) j1++;
        while (j2 <= r && a[j2] <= a[i]) j2++;
        int k = j2 - j1;
        all -= k;
    }
    
    for (int i = l; i <= r; i++) a[i] = b[i - l];
    inv[h] += cinv;
    ainv[h] += all - cinv;
}

vector<ll> fastsolve() {
    vector<ll> res;
    for (int i = 0; i < n; i++) a[i] = A[i];
    memset(inv, 0, sizeof(inv));
    memset(ainv, 0, sizeof(ainv));
    mxh = 0;
    mySort(0, n - 1, 0);
    for (int i = 0; i < m; i++) {
        int x = X[i];
        x = mxh - x;
        for (int j = x; j <= mxh; j++) {
            swap(inv[j], ainv[j]);
        }
        ll ans = 0;
        for (int j = 0; j <= mxh; j++) ans += inv[j];
        res.push_back(ans);
    }
    return res;
}

void print(vector<ll> a) {
    for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
}

ll calc() {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res += a[i] > a[j];
        }
    }
    return res;
}

vector<ll> slowsolve() {
    vector<ll> res;
    for (int i = 0; i < n; i++) a[i] = A[i];
    for (int i = 0; i < m; i++) {
        int o = 1 << X[i];
        for (int j = 0; j < n; j += o) {
            reverse(a + j, a + j + o);
        }
        res.push_back(calc());
    }
    return res;
}

void gen() {
    n = rand() % 6;
    m = rand() % 3 + 1;
    for (int i = 0; i < m; i++) X[i] = rand() % (n + 1);
    
    n = 1 << n;
    for (int i = 0; i < n; i++) {
        A[i] = rand() % n;
    }
    random_shuffle(A, A + n);
}

int F(int n) {
    for (int i = 0; i < 30; i++) if ((1 << i) == n) return i;
    return -1;
}

void stress(bool f) {
    if (!f) return; 
    for (int it = 0; it < 1e9; it++) {
        gen();
        vector<ll> res1 = fastsolve();
        vector<ll> res2 = slowsolve();
        if (res1 != res2) {
            print(res1);
            print(res2);
            cout << F(n) << endl;
            for (int i = 0; i < n; i++) cout << A[i] << " \n"[i + 1 == n];
            cout << m << endl;
            for (int i = 0; i < m; i++) cout << X[i] << " \n"[i + 1 == m];
            break;
        }
        if (it % 100 == 0)
            cerr << it << endl;
    }
    exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    stress(0);

    while (cin >> n) {
        n = 1 << n;
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", &X[i]);
        
        //print(slowsolve());
        print(fastsolve());
    }

	return 0;
}