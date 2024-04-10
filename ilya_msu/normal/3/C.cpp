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

bool firstWin(const vector<string>& a) {
    for (int i = 0; i < 3; ++i) {
        bool ok = 1;
        for (int j = 0; j < 3; ++j)
            if (a[i][j] != 'X')
                ok = 0;
        if (ok)
            return 1;
    }
    for (int i = 0; i < 3; ++i) {
        bool ok = 1;
        for (int j = 0; j < 3; ++j)
            if (a[j][i] != 'X')
                ok = 0;
        if (ok)
            return 1;
    }
    bool ok = 1;
    for (int i = 0; i < 3; ++i)
        if (a[i][i] != 'X')
            ok = 0;
    if (ok)
        return 1;
    ok = 1;
    for (int i = 0; i < 3; ++i)
        if (a[i][2 - i] != 'X')
            ok = 0;
    return ok;
}

bool secondWin(const vector<string>& a) {
    for (int i = 0; i < 3; ++i) {
        bool ok = 1;
        for (int j = 0; j < 3; ++j)
            if (a[i][j] != '0')
                ok = 0;
        if (ok)
            return 1;
    }
    for (int i = 0; i < 3; ++i) {
        bool ok = 1;
        for (int j = 0; j < 3; ++j)
            if (a[j][i] != '0')
                ok = 0;
        if (ok)
            return 1;
    }
    bool ok = 1;
    for (int i = 0; i < 3; ++i)
        if (a[i][i] != '0')
            ok = 0;
    if (ok)
        return 1;
    ok = 1;
    for (int i = 0; i < 3; ++i)
        if (a[i][2 - i] != '0')
            ok = 0;
    return ok;
}

void solve() {
    vector<string> a(3);
    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    int x = 0, y = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] == 'X')
                ++x;
            if (a[i][j] == '0')
                ++y;
        }
    }
    bool w1 = firstWin(a);
    bool w2 = secondWin(a);
    
    if (w1) {
        if (w2) {
            cout << "illegal\n";
            return;
        }
        if (x != y + 1) {
            cout << "illegal\n";
            return;
        }
        cout << "the first player won" << endl;
        return;
    }
    if (w2) {
        if (x != y) {
            cout << "illegal\n";
            return;
        }
        cout << "the second player won" << endl;
        return;
    }
    if ((x == 5) && (y == 4)) {
        cout << "draw\n";
        return;
    }
    if (x == y) {
        cout << "first" << endl;
        return;
    }
    if (x == y + 1) {
        cout << "second" << endl;
        return;
    }
    cout << "illegal" << endl;
    return;	
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