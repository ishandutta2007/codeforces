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
//#include<unordered_map>




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
const int negINF = numeric_limits<int>::min();

const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

ll n, d, b;
vector<int> a;
vector<int> pref, suf;

bool can(int r) {
    int m = n / 2;
    for (ll i = r; i < m; ++i) {
        ll j = min(n, i + 1 + (i + 1) * d);
        if (pref[j] < (i - r + 1) * b)
            return 0;
    }
    for (ll i = r; i < m; ++i) {
        ll j = min(n, i + 1 + (i + 1) * d);
        if (suf[j] < (i - r + 1) * b)
            return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> d >> b;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pref.assign(n + 1, 0);
    suf.assign(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + a[i];
    reverse(suf.begin(), suf.end());
    int low = -1, up = (n + 1) / 2;
    while (up - low > 1) {
        int mid = (up + low) / 2;
        if (can(mid))
            up = mid;
        else
            low = mid;
    }
    cout << up << endl;
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