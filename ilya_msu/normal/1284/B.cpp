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


void solve() {
    ll n;
    vector<pll> a;
    cin >> n;
    ll res = n * n;
    vector<int> d;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> b(l);
        for (int j = 0; j < l; ++j) {
            cin >> b[j];
        }
        int ok = 1;
        for (int j = 1; j < l; ++j) {
            if (b[j] > b[j - 1]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0)
            continue;
        a.emplace_back(b[0], b[l - 1]);
        if (b[0] == b[l - 1])
            d.push_back(b[0]);

    }
    sort(a.begin(), a.end());
    vector<int> p;
    for (int i = 0; i < a.size(); ++i) {
        p.push_back(a[i].first);
        ll x = upper_bound(p.begin(), p.end(), a[i].second) - p.begin();
        res -= x;
    }
    sort(d.begin(), d.end());
    int c = 1;
    for (int i = 1; i < d.size(); ++i) {
        if (d[i] == d[i - 1]) {
            res -= c;
            ++c;
        }
        else {
            c = 1;
        }

    }
    cout << res << endl;
}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}