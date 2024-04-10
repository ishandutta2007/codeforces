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
const ll mod = 998244353;

vector<int> v;
vector<ll> h1, h2;


ll solve(const vector<int>& a, int st, int en) {
    ll res = 0;

    if (en - st < 10) {
        for (int i = st; i < en; ++i) {
            v.clear();
            for (int j = i; j < en; ++j) {
                if ((v.empty()) || (v.back() != a[j])) {
                    v.push_back(a[j]);
                }
                else {
                    v.pop_back();
                }
                if (v.empty())
                    ++res;
            }
        }
        return res;
    }
    int mid = (en + st) / 2;
    res = solve(a, st, mid) + solve(a, mid, en);
    ll r1 = 78123468723;
    ll r2 = 23402092711;
    h1.clear();
    h2.clear();
    h1.push_back(0);
    h2.push_back(0);
    v.clear();
    map<pair<int, pll>, ll> mp1;
    for (int i = mid; i < en; ++i) {
        if ((v.empty()) || (v.back() != a[i])) {
            v.push_back(a[i]);
            h1.push_back(h1.back() * r1 + a[i]);
            h2.push_back(h2.back() * r2 + a[i]);
        }
        else {
            v.pop_back();
            h1.pop_back();
            h2.pop_back();
        }
        pair<int, pll> pp = make_pair(v.size(), pll(h1.back(), h2.back()));
        if (mp1.find(pp) == mp1.end())
            mp1[pp] = 1;
        else 
            mp1[pp] += 1;
    }
    h1.clear();
    h2.clear();
    h1.push_back(0);
    h2.push_back(0);
    v.clear();
    for (int i = mid - 1; i >= st; --i) {
        if ((v.empty()) || (v.back() != a[i])) {
            v.push_back(a[i]);
            h1.push_back(h1.back() * r1 + a[i]);
            h2.push_back(h2.back() * r2 + a[i]);
        }
        else {
            v.pop_back();
            h1.pop_back();
            h2.pop_back();
        }
        pair<int, pll> pp = make_pair(v.size(), pll(h1.back(), h2.back()));
        res += mp1[pp];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    v.reserve(n);
    h1.reserve(n);
    h2.reserve(n);
    cout << solve(a, 0, n) << "\n";

}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
int q;
cin >> q;
for (int i = 0; i < q; ++i)
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}