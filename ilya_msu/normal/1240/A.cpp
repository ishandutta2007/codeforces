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

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    sort(p.rbegin(), p.rend());
    int x, a;
    int y, b;
    cin >> x >> a >> y >> b;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    ll k;
    cin >> k;
    ll m = a / gcd(a, b) * b;
    ll up = n + 1, low = 0;
    while (up - low > 1) {
        ll mid = (up + low) / 2;
        ll x1 = mid / m;
        ll x2 = mid / a - x1;
        ll x3 = mid / b - x1;
        //cerr << mid << " " << x1 << " " << x2 << " " << x3 << endl;
        ll res = 0;
        for (int i = 0; i < x1; ++i) {
            res += p[i] / 100 * (x + y);
        }
        //cerr << res << endl;
        for (int i = x1; i < x1 + x2; ++i) {
            res += p[i] / 100 * x;
        }
        //cerr << res << endl;

        for (int i = x1 + x2; i < x1 + x2 + x3; ++i) {
            res += p[i] / 100 * y;
        }
        //cerr << res << endl;

        //cerr << mid << " " << res << endl;
        if (res >= k) {
            up = mid;
        }
        else 
            low = mid;
    }
    if (up == n + 1)
        cout << -1 << endl;
    else {
        cout << up << endl;
    }

    
}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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