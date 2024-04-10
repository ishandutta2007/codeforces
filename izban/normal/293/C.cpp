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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 16;
const int inf = 1000000007;
const int mod = 1000000007;

ll n;

int calc(int a, int b, int c) {
    if (a <= 0) return 0;
    if (a == c) return 1;
    if (a == b || b == c) return 3;
    return 6;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        if (n % 3) {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        n /= 3;
        vector<ll> v;
        //for (int i = 2; 1LL * i * i * i <= 10 * n; i++) if (n % i == 0) {
        for (int i = 2; 1LL * i * i <= n; i++) if (n % i == 0) {
            v.push_back(i);
        }
        //cout << v.size() << endl;
        for (int i = 0; i < (int)v.size(); i++) {
            int x = v[i];
            for (int j = i; j < v.size(); j++) {
                int y = v[j];
                if (n / x % y) continue;
                int z = n / x / y;
                if (z < y || 1LL * x * y * z != n) continue;
                int a = x + y - z, b = x + z - y, c = y + z - x;
                if (a <= b && b <= c && !(a % 2) && !(b % 2) && !(c % 2)) ans += calc(a / 2, b / 2, c / 2);
            }
        }
        cout << ans << endl;
    }

    return 0;
}