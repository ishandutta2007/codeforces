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
#define y1 _dfdfdfd
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

const int m[2][14] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 365}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 366}};

int y1, m1, d1, y2, m2, d2;

int f(int x) {
    return x % 400 == 0 ? 1 : x % 100 == 0 ? 0 : x % 4 == 0 ? 1 : 0;
}

int solve() {
    if (y1 > y2 || y1 == y2 && (m1 > m2 || m1 == m2 && (d1 > d2))) {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }
    
    int res = 0;
    for (int i = y1 + 1; i <= y2 - 1; i++) res += m[f(i)][13];
    int k1 = m[f(y1)][m1] - d1, k2 = d2;
    for (int i = m1 + 1; i <= 12; i++) k1 += m[f(y1)][i];
    for (int i = 1; i < m2; i++) k2 += m[f(y2)][i];
    if (y1 == y2) res += k1 + k2 - m[f(y1)][13];
    else res += k1 + k2;
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    char c;
    while (cin >> y1 >> c >> m1 >> c >> d1 >> y2 >> c >> m2 >> c >> d2) cout << solve() << endl;
    
	return 0;
}