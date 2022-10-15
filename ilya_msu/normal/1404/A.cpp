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
const ll mod = 998244353;


void solve() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int k, n;
        string s;
        cin >> n >> k >> s;
        bool ok = 1;
        int a0 = 0, a1 = 0;
        for (int i = 0; i < k; ++i) {
            int c0 = 0, c1 = 0, cq = 0;
            for (int j = i; j < n; j += k) {
                if (s[j] == '0')
                    ++c0;
                if (s[j] == '1')
                    ++c1;
                if (s[j] == '?')
                    ++cq;
            }
            if ((c0 > 0) && (c1 > 0)) {
                ok = 0;
                break;
            }
            a0 += (c0 > 0);
            a1 += (c1 > 0);
        }
        if ((a1 > k / 2) || (a0 > k / 2))
            ok = 0;
        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

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