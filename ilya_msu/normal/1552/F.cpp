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
#include<iterator>
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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;


void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> a[i];
    vector<ll> first(n), deact(n);
    first[0] = x[0];
    deact[0] = x[0] - y[0];
    vector<ll> sm(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        sm[i] = sm[i - 1] + deact[i - 1];
        sm[i] %= mod;
        first[i] = (first[i - 1] + deact[i - 1] * a[i - 1] + x[i] - x[i - 1]) % mod;
        deact[i] = x[i] - y[i];
        int pos = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
        //cout << i << " " << pos << " " << sm[i] - sm[pos] << endl;
        deact[i] += sm[i] - sm[pos] + mod;
        deact[i] %= mod;
    }
    ll res = (first[n - 1] + deact[n - 1] * a[n - 1] + 1) % mod;
    
    cout << res << endl;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i)
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}