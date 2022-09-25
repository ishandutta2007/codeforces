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
#include <assert.h>
#include <memory.h>

using namespace std;

#define ll long long


#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17, maxk = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n, a, b;
    cin >> a >> b >> n;
    int cur = a % b;
    string ans = "";
    for (int i = 1; i <= n; i++) {
        cur = cur * 10 % b;
        for (int k = 0; k < 10; k++) {
            if ((cur + k) % b == 0) {
                ans += (char)('0' + k);
                cur += k;
                break;
            }
        }
        if (ans.length() != i) {
            cout << -1;
            return 0;
        }
    }
    cout << a << ans;
    return 0;
}