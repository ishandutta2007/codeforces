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


const int maxn = 1 << 7;
const int maxm = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int dp[maxn][2 * maxm];
int a[4], b[4], c[4], d[4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    while (cin >> n) {
        for (int i = 0; i < 4; i++) {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }
        bool ok = 0;
        for (int i = 0; i < 4; i++) {
            if (min(a[i], b[i]) + min(c[i], d[i]) <= n) {
                cout << i + 1 << " " << min(a[i], b[i]) << " " << n - min(a[i], b[i]) << endl;
                ok = 1;
                break;
            }
        }
        if (!ok) cout << -1 << endl;
    }
    
	return 0;
}