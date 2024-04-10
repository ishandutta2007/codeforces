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

ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<string> q(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i] >> c[i];
    }
    map<int, int> mp;
    vector<int> a;
    int cnt = 0;
    int lst = -1;
    for (int i = 0; i < n; ++i) {
        if (q[i] == "ADD") {
            a.push_back(c[i]);
            ++cnt;
        }
        else {
            int x = c[i];
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] > x) {
                    mp[a[j]] = 1;
                }
                else {
                    if (a[j] < x) {
                        mp[a[j]] = -1;
                    }
                }
            }
            a.resize(0);
            lst = i;
        }
    }
    if (lst == -1) {
        cout << cnt + 1 << endl;
        return;
    }
    ll res = power(2, cnt - mp.size() - a.size());
    //cerr << res << endl;
    priority_queue<int> buy, sell;
    int x = -1;
    ll mul = 0;
    for (int i = 0; i < n; ++i) {
        if (q[i] == "ADD") {
            if (mp.find(c[i]) == mp.end()) {
                if (i > lst) {
                    if (((buy.empty()) || (buy.top() < c[i])) &&
                        ((sell.empty()) || (-sell.top() > c[i])))
                        ++mul;
                    continue;
                }
                else {
                x = c[i];
                if ((!buy.empty()) && (buy.top() >= x))
                    res = 0;
                if ((!sell.empty()) && (-sell.top() <= x))
                    res = 0;
                continue;
                }
            }
            if (mp[c[i]] == 1) {
                sell.push(-c[i]);
                if ((x != -1) && (c[i] <= x))
                    res = 0;
                if ((!buy.empty()) && (buy.top() >= c[i]))
                    res = 0;
            }
            else {
                buy.push(c[i]);
                if ((x != -1) && (c[i] >= x))
                    res = 0;
                if ((!sell.empty()) && (-sell.top() <= c[i]))
                    res = 0;
            }
        }
        else {
            if (x == c[i]) {
                x = -1;
                continue;
            }
            if (x != -1) {

            }
            int ok = 0;
            if ((!buy.empty()) && (buy.top() == c[i])) {
                buy.pop();
                ok = 1;
            }
            else {
                if ((!sell.empty()) && (sell.top() == -c[i])) {
                    sell.pop();
                    ok = 1;
                }
            }
            if (!ok)
                res = 0;
        }
    }
    res = (res * (mul + 1)) % mod;
    cout << res << endl;
    
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}