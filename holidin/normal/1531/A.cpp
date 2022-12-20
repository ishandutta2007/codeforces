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
const int inf = 1e9;
const int N = 3e5 + 13;
vector<int> e[N];
int d[N];

void solve() {
    int n, k,a, b;
    string s;
    cin >> n;
    string color = "blue";
    bool locked = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "lock")
            locked = 1;
        else
        if (s == "unlock")
            locked = 0;
        else if (!locked)
            color = s;
    }
    cout << color;
}



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    solve();


}