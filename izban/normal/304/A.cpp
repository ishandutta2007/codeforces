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

int solve(int n) {
    int res = 0;
    for (int c = n; c >= 1; c--) {
        for (int b = c - 1; b >= 1; b--) {
            int aa = c * c - b * b;
            int a = sqrt(aa + 0.5);
            if (a > b) break;
            res += a * a == aa;
        }
    } 
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    while (cin >> n) cout << solve(n) << endl;
    
	return 0;
}