#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>
#include<unordered_set>
#include<chrono>
#include<random>



using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;

vector<int> nums;

int init() {
    int N = 100;// *1000 * 1000;
    for (int i = 1; i < N; ++i) {
        int j = sqrt(1.0 * i);
        if (i % j == 0)
            nums.push_back(i);
    }
    for (auto x : nums)
        cout << x << endl;
    return 0;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll l1 = sqrt(1.0 * l);
    ll r1 = sqrt(1.0 * r);
    while (l1 * l1 > l)
        --l1;
    while ((l1 + 1) * (l1 + 1) <= l)
        ++l1;
    while (r1 * r1 > r)
        --r1;
    while ((r1 + 1) * (r1 + 1) <= r)
        ++r1;
    vector<ll> a;
    a.push_back(l1 * l1);
    a.push_back(l1 * l1 + l1);
    a.push_back(l1 * l1 + 2 * l1);
    a.push_back(r1 * r1);
    a.push_back(r1 * r1 + r1);
    a.push_back(r1 * r1 + 2 * r1);
    ll res = 0;
    for (auto x : a) {
        if ((x >= l) && (x <= r))
            ++res;
    }
    if (l1 == r1) {
        cout << res / 2 << "\n";
        return;
    }
    res += 3 * (r1 - l1 - 1);
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}