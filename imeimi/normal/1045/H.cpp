#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int mod = 1e9 + 7;

void fail(int i) {
    printf("0\n", i);
    exit(0);
}

int n;
char A[100005];
char B[100005];
int c00, c01, c10, c11;

int fc[300000];

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = (llong)r * x % mod;
        x = (llong)x * x % mod;
        p >>= 1;
    }
    return r;
}

int nHr(int n, int r) {
    if (r == 0) return 1;
    n += r - 1;
    return (llong)fc[n] * pw((llong)fc[r] * fc[n - r] % mod, mod - 2) % mod;
}

int counts(char c, int c00, int c01, int c10, int c11) {
    if (c00 < 0) return 0;
    if (c01 < 0) return 0;
    if (c10 < 0) return 0;
    if (c11 < 0) return 0;
    if (c == '0') {
        if (c01 == 0 && c11 != 0) return 0;
        if (c01 != c10 && c01 != c10 + 1) return 0;
        int C1 = c01;
        int C0 = c10 + 1;
        return (llong)nHr(C0, c00) * nHr(C1, c11) % mod;
    }
    else {
        if (c10 == 0 && c00 != 0) return 0;
        if (c01 != c10 && c01 + 1 != c10) return 0;
        int C1 = c01 + 1;
        int C0 = c10;
        return (llong)nHr(C0, c00) * nHr(C1, c11) % mod;
    }
}

int solveAtoinf(int s, int c00, int c01, int c10, int c11) {
    if (c01 != c10 && c01 != c10 + 1) return 0;
    char c = '0';
    int ret = 0;
    for (int i = s; i < n; ++i) {
        if (A[i] == '0') {
            ret += counts('1', c00, c01 - (c == '0'), c10, c11 - (c == '1'));
            ret %= mod;
            if (c == '0') --c00;
            else --c10;
            c = '0';
        }
        else {
            if (c == '0') --c01;
            else --c11;
            c = '1';
        }
    }
    if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) return ret;
    return ret + 1;
}

int solveinftoB(int s, int c00, int c01, int c10, int c11) {
    if (c01 != c10 && c01 + 1 != c10) return 0;
    char c = '1';
    int ret = 0;
    for (int i = s; i < n; ++i) {
        if (B[i] == '0') {
            if (c == '0') --c00;
            else --c10;
            c = '0';
        }
        else {
            ret += counts('0', c00 - (c == '0'), c01, c10 - (c == '1'), c11);
            ret %= mod;
            if (c == '0') --c01;
            else --c11;
            c = '1';
        }
    }
    if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) return ret;
    return ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fc[0] = 1;
	for (int i = 1; i < 300000; ++i) fc[i] = (llong)fc[i - 1] * i % mod;
	
	cin >> A >> B >> c00 >> c01 >> c10 >> c11;
	if (c00 + c01 + c10 + c11 + 1 < strlen(A)) fail(-2);
	{
	    int v = strlen(B) - strlen(A);
	    for (int i = strlen(A); i--; ) A[i + v] = A[i];
	    for (int i = 0; i < v; ++i) A[i] = '0';
	}
	
	n = strlen(B);
	char s = '1';
	int i = n - c00 - c01 - c10 - c11 - 1;
	if (i < 0) fail(-1);
	if (i > 0) for (int j = i; j < n; ++j) B[j] = '1';
	if (A[i] == '0') for (int j = i; j < n; ++j) A[j] = '0';
	++i;
	while (i < n && A[i] == B[i]) {
        if (A[i] == '0') {
            if (s == '0') {
                if (--c00 < 0) fail(0);
            }
            else {
                if (--c10 < 0) fail(1);
                s = '0';
            }
        }
        else {
            if (s == '0') {
                if (--c01 < 0) fail(2);
                s = '1';
            }
            else {
                if (--c11 < 0) fail(3);
            }
        }
        ++i;
	}
	if (i == n) {
        printf("1\n");
        return 0;
	}
	
	int ans = 0;
	if (s == '0') {
        if (c00) ans += solveAtoinf(i + 1, c00 - 1, c01, c10, c11);
        if (c01) ans += solveinftoB(i + 1, c00, c01 - 1, c10, c11);
	}
	else {
        if (c10) ans += solveAtoinf(i + 1, c00, c01, c10 - 1, c11);
        if (c11) ans += solveinftoB(i + 1, c00, c01, c10, c11 - 1);
	}
	printf("%d\n", ans % mod);
	return 0;
}