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
    cin >> n;
    string r1 = "", r2 = "";
    int x = n, y = n;
    string s;
    while (x + y > n + 1) {
        cout << "? 1 1 " << y << " " << x - 1 << endl;
        cin >> s;
        if (s == "BAD") {
            return;
        }
        if (s == "YES") {
            r2 += "R";
            --x;
        }
        else {
            r2 += "D";
            --y;
        }
    }
    x = y = 1;
    while (x + y < n + 1) {
        cout << "? " << y + 1 << " " << x << " " << n << " " << n << endl;
        cin >> s;
        if (s == "BAD") {
            return;
        }
        if (s == "YES") {
            r1 += "D";
            ++y;
        }
        else {
            r1 += "R";
            ++x;
        }
    }
    reverse(r2.begin(), r2.end());
    cout << "! " << r1 << r2 << endl;
}

//#define LOCAL

int main() {
    //ios_base::sync_with_stdio(0);
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