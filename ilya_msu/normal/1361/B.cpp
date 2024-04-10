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
#include<unordered_map>
#include<deque>
#include<cmath>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


ll power(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}



void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (p == 1) {
        cout << n % 2 << "\n";
        return;
    }
    vector<ll> mul(1, 1);
    ll m = p;
    while (m < 1000000 + 10) {
        mul.push_back(m);
        m *= p;
    }
    while (!a.empty()) {
        ll d = 1;
        int sz = a.size();
        ll dg = a[sz - 1];
        int ok = 0;
        int lst = sz - 1;
        for (int i = sz - 2; i >= 0; --i) {
                int dg1 = dg - a[i];
                if (dg1 >= mul.size()) {
                    ok = 0;
                    break;
                }
                d *= mul[dg1];
                if (d > 1000000 + 10) {
                    ok = 0;
                    break;
                }
                dg = a[i];
                d -= 1;
                if (d == 0) {
                    ok = 1;
                    lst = i;
                    break;
                }
        }
        //cerr << ok << " " << lst << endl;
        if (ok == 0) {
            ll res = power(p, a[sz - 1]);
            for (int i = 0; i < sz - 1; ++i) {
                res -= power(p, a[i]);
            }
            res %= mod;
            res += mod;
            res %= mod;
            cout << res << "\n";
            return;
        }
        while (a.size() > lst)
            a.pop_back();
    }
    cout << 0 << "\n";
    return;
}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}