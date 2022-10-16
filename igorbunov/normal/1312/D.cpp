#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
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
#define endl "\n"

vector<int> f(300000);
vector<int> f1(300000);
 
int MOD = 998244353;
 
int st(int a, int v) {
    if (v == 0) {
        return 1;
    }
 
    if (v % 2 == 0) {
        int c = st(a, v / 2);
        return (c * c) % MOD;
    } else {
        return (st(a, v - 1) * a) % MOD;
    }
}
 
void fill() {
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
 
    for (int i = 0; i <= 200000; i++) {
        f1[i] = st(f[i], MOD - 2);
    }
}
 
 
int c(int n, int k) {
    return (((f[n] * f1[k]) % MOD) * f1[n - k]) % MOD;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill();

    int n, m;
    cin >> n >> m;

    if (n == 2) {
    	cout << 0;
    	return 0;
    }

    int now = 1;

    for (int i = 0; i < n - 3; i++) {
    	now *= 2;
    	now %= MOD;
    }

    int ans = now;

    ans *= (n - 2);

    ans %= MOD;

    ans *= c(m, n - 1);

    ans %= MOD;

    cout << ans;

}