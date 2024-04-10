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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n, k;
    while (cin >> n >> k) {
        if (k < n / 2 || k != 0 && n == 1) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans(n, 1);
        k -= n / 2;
        k++;
        
        ans[0] = k * 2;
        ans[1] = k * 3;
        for (int i = 2; i < n; i++) ans[i] = 1e9 - (i - 2);
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
    }

	return 0;
}