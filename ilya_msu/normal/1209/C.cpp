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


void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = s[i] - '0';
    vector<int> c(n);
    for (int d = 0; d < 10; ++d) {
        c.assign(n, 0);
        int l1 = 0, l2 = 0;
        int first2 = n, last1 = -1;
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < d) {
                c[i] = 1;
                if (a[i] < l1) {
                    ok = 0;
                    break;
                }
                l1 = a[i];
                last1 = max(i, last1);
            }
            if (a[i] > d) {
                c[i] = 2;
                if (a[i] < l2) {
                    ok = 0;
                    break;
                }
                l2 = a[i];
                first2 = min(i, first2);
            }
        }
        if (!ok) {
            continue;
        }
        if (first2 == -1) {
            for (int i = 0; i < n; ++i) {
                cout << c[i];
            }
            cout << "\n";
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == d) {
                if (i > last1) {
                    c[i] = 1;
                }
                else {
                    if (i < first2) {
                        c[i] = 2;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << c[i];
            }
            cout << "\n";
            return;
        }
    }
    cout << "-\n";

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}