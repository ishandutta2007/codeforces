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


void solve() {
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = ((((((a[i] * a[i]) % p) * a[i]) % p) * a[i]) % p) - ((a[i] * k) % p);
        b[i] = (b[i] + p) % p;
    }
    sort(b.begin(), b.end());
    ll res = 0;
    ll c = 1;
    for (int i = 1; i < n; ++i) {
        if (b[i] == b[i - 1]) {
            ++c;
        }
        else {
            res += c * (c - 1) / 2;
            c = 1;
        }
    }
    res += c * (c - 1) / 2;
    cout << res << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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