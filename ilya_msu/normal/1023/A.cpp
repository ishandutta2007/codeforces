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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int pos = s.find('*');
    if (pos == -1) {
        if (s == t) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        return;
    }
    if (n > m + 1) {
        cout << "NO\n";
        return;
    }
    if (s.substr(0, pos) != t.substr(0, pos)) {
        cout << "NO\n";
        return;
    }
    if (s.substr(pos + 1, n - pos - 1) != t.substr(m - n + pos + 1, n - pos - 1)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

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