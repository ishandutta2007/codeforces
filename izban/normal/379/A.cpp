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




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int a, b;
    while (cin >> a >> b) {
        int cur = a, ost = 0;
        int ans = 0;
        while (1) {
            ans += cur;
            ost += cur;
            cur = 0;
            if (ost >= b) {
                cur += ost / b;
                ost %= b;
            } else break;
        }
        cout << ans << endl;
    }

	return 0;
}