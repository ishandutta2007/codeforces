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
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 100000 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> c(N, 0);
    vector<ll> ans(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }
    vector<ll> pw;
    for (ll i = 1; ; ++i) {
        ll x = 1;
        for (int j = 1; j <= k; ++j) {
            x *= i;
            if (x >= N)
                break;
        }
        if (x < N)
            pw.push_back(x);
        else 
            break;
    }
    for (ll i = 1; i < N; ++i) {
        for (int j = 0; j < pw.size(); ++j) {
            ll id = i * pw[j];
            if (id >= N)
                break;
            ans[i] += c[id];
        }
    }
    vector<ll> nums;
    for (ll i = 1; ; ++i) {
        ll x = 1;
        for (int j = 1; j <= k; ++j) {
            x *= i;
            if (x >= N * N)
                break;
        }
        if (x < N * N)
            nums.push_back(x);
        else 
            break;
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll d = 1;
        ll x = a[i];
        for (ll j = 2; j * j <= x; ++j) {
            if ((x % j) != 0)
                continue;
            int cc = 0;
            while (x % j == 0) {
                ++cc;
                x /= j;
            }
            int l = k - (cc % k);
            if (l == k)
                l = 0;
            for (int ii = 0; ii < l; ++ii) {
                if (d >= N)
                    break;
                d *= j;
            }
        }
        if (x != 1) {
            for (int ii = 0; ii < k - 1; ++ii) {
                if (d >= N)
                    break;
                d *= x;
            }
        }
        if (d >= N)
            continue;
        //cerr <<  a[i] << " " << d << endl;
        ll y = a[i] * a[i];
        auto it = lower_bound(nums.begin(), nums.end(), y);
        if ((it != nums.end()) && ((*it) == y))
            --res;
        res += ans[d];
    }
    cout << res / 2 << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}