#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e15;
const int N = 1e4 + 13;
mt19937 rnd;


void solve(int num) {
    string s;
    cin >> s;
    int mx = 0;
    for (auto c : s)
        mx = max(mx, (int)c - '0');
    cout << mx << "\n";

}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    int test = 1;
    cin >> test;
    int cnt = 0;
    while (test--) {
        ++cnt;
        solve(cnt);
    }

}