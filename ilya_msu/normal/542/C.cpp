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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 10000;
//const int M = 10000000;



ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
    }
    ll low = 1;
    ll t = 1;
    for (int i = 0; i < n; ++i) {
        vector<ll> first(n, -1);
        first[i] = 0;
        int cur = i;
        int c = 0;
        int tt;
        while (true) {
            cur = f[cur];
            ++c;
            if (first[cur] == -1) {
                first[cur] = c;
            }
            else {
                t = lcm(t, c - first[cur]);
                low = max(low, first[cur]);
                break;
            }
        }
    }
    ll res = (low / t) * t;
    if (res < low)
        res += t;
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