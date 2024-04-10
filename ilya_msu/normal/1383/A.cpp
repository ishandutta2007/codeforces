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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                cout << -1 << "\n";
                f = 1;
                break;
            }
        }
        if (f)
            continue;
        int res = 0;
        for (int i = 0; i < 20; ++i) {
            char x = 'z';
            for (int j = 0; j < n; ++j) {
                if (a[j] == b[j])
                    continue;
                if (a[j] == 'a' + i) {
                    x = min(x, b[j]);
                }
            }
            if (x == 'z')
                continue;
            ++res;
            for (int j = 0; j < n; ++j) {
                if (a[j] == b[j])
                    continue;
                if (a[j] == 'a' + i) {
                    a[j] = x;
                }
            }
        }
        cout << res << "\n";
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