#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

//#pragma GCC_OPTIMIZE("ofast")
using namespace std;
 
 
#define int long long

bool comp(int a, int b) {
    return (a % 2) < (b % 2);
}

int mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int kek = (1 << 30) - 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        kek &= arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == kek) {
            cnt++;
        }
    }
    int lol = 1;
    for (int i = 1; i <= n - 2; i++) {
        lol *= i;
        lol %= mod;
    }
    cnt *= cnt - 1;
    cnt %= mod;
    cout << (cnt * lol) % mod << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
    }
}