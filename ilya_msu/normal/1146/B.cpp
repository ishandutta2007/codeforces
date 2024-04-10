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
    string s;
    cin >> s;
    int n = s.size();
    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a')
            ++a;
    }
    int m = (n - a) / 2 + a;
    string s1 = s.substr(0, m);
    string s2 = "";
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != 'a')
            s2 += s1[i];
    }
    if (s1 + s2 == s) {
        cout << s1 << endl;
    }
    else
        cout << ":(\n";
    


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