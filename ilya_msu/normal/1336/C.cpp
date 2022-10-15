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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    //reverse(s.begin(), s.end());
    //vector<vector<ll> > d(n + 1, vector<ll>(n + 1, 0));
    vector<int> d1(n + 1, 1);
    vector<int> d2;
    //for (int i = 0; i <= n; ++i)
    //    d[i][i] = 1;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        d2.assign(n + 1, 0);
        for (int st = 0; st <= n; ++ st) {
            int end = st + i;
            if ((st > 0) && ((st - 1 >= m) || (t[st - 1] == s[i]))) {
                d2[st - 1] = (d2[st - 1] + d1[st]) % mod;
            }
            if ((end < n) && ((end >= m) || (t[end] == s[i]))) {
                d2[st] = (d2[st] + d1[st]) % mod;
            }
        }
        if (i >= m - 1)
            res = (res + d2[0]) % mod;
        swap(d1, d2);
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