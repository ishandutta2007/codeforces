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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        vector<int> b(k);
        for (int i = 0; i < n; i++) cin >> a[i], b[i % k] += a[i];
        int ans = 1e9, pans = -1;
        for (int i = 0; i < k; i++) {
            if (ans > b[i]) {
                ans = b[i];
                pans = i + 1;
            }
        }
        cout << pans << endl;
    }
    
	return 0;
}