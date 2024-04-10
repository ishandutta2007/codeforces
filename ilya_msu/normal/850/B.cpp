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
const int N = 1000 * 1000 + 5;

vector<int> genPrimes(int N) {
    vector<int> p(N + 1, 1);
    vector<int> res;
    for (int i = 2; i < p.size(); ++i) {
        if (p[i]) {
            res.push_back(i);
            for (int j = i + i; j < p.size(); j += i)
                p[j] = 0;
        }
    }
    return res;
}

vector<int> getDiv(int N) {
    vector<int> p(N + 1);
    for (int i = 0; i < p.size(); ++i)
        p[i] = i;
    for (int i = 2; i < p.size(); ++i) {
        if (p[i] == i) {
            for (int j = i + i; j < p.size(); j += i)
                p[j] = i;
        }
    }
    return p;
}

void solve() {
    //vector<int> primes = genPrimes(N);
    vector<int> div = getDiv(N);
    vector<int> count(N, 0);
    int n;
    ll x, y;
    cin >> n >> y >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll res = y * n;
    int odd = 0;
    for (int i = 0; i < n; ++i)
        odd += a[i] & 1;
    res = min(res, min(x, y) * odd);
    for (int i = 0; i < n; ++i) {
        int b = a[i];
        int lst = -1;
        while (b != 1) {
            if (div[b] != lst)
                count[div[b]]++;
            lst = div[b];
            b /= lst;
        }
    }
    vector<pii> p;
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] > 0) {
            p.emplace_back(count[i], i);
        }
    }
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < p.size(); ++i) {
        int d = p[i].second;
        ll cur = min(x, y) * (n - p[i].first);
        for (int j = 0; (j < n) && (cur < res); ++j) {
            int r = a[j] % d;
            if (r)
                cur += min(y, x * (d - r)) - min(x, y);            
        }
        res = min(res, cur);
    }
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