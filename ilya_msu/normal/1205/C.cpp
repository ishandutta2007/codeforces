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

void print(const vector<vector<int> >& a) {
    int n = a.size() - 1;
    cout << "!\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

bool check1(int x1, int y1, const vector<vector<int> >& a, const vector<vector<int> >& b) {
    int r;
    if (a[x1][y1] == a[x1 + 1][y1 + 2]) {
        if ((a[x1][y1 + 1] == a[x1][y1 + 2]) || (a[x1 + 1][y1] == a[x1 + 1][y1 + 1])) {
            cout << "? " << x1 << " " << y1 << " " << x1 + 1 << " " << y1 + 2 << endl;
            cin >> r;
            if (r)
                print(a);
            else
                print(b);
            return 1;
        }
    }
    return 0;
} 

bool check2(int x1, int y1, const vector<vector<int> >& a, const vector<vector<int> >& b) {
    int r;
    if (a[x1][y1] == a[x1 + 2][y1 + 1]) {
        if ((a[x1 + 1][y1] == a[x1 + 2][y1]) || (a[x1][y1 + 1] == a[x1 + 1][y1 + 1])) {
            cout << "? " << x1 << " " << y1 << " " << x1 + 2 << " " << y1 + 1 << endl;
            cin >> r;
            if (r)
                print(a);
            else
                print(b);
            return 1;
        }
    }
    return 0;
} 

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > a(n + 1, vector<int> (n + 1, -1)), 
    b(n + 1, vector<int>(n + 1, -1));
    a[1][1] = b[1][1] = 1;
    a[n][n] = b[n][n] = 0;
    a[1][2] = 0;
    b[1][2] = 1;
    int r;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j > 0; --j) {
            cout << "? " << i << " " << j << " " << i << " " << j + 2 << endl;
            cin >> r;
            a[i][j] = a[i][j + 2] ^ r ^ 1;
            b[i][j] = b[i][j + 2] ^ r ^ 1;
        }
        for (int j = i; j + 2 <= n; ++j) {
            cout << "? " << i << " " << j << " " << i << " " << j + 2 << endl;
            cin >> r;
            a[i][j + 2] = a[i][j] ^ r ^ 1;
            b[i][j + 2] = b[i][j] ^ r ^ 1;
        }
        if (i < n - 1) {
            cout << "? " << i << " " << i << " " << i + 1 << " " << i + 1 << endl;
            cin >> r;
            a[i + 1][i + 1] = a[i][i] ^ r ^ 1;
            b[i + 1][i + 1] = b[i][i] ^ r ^ 1;
            cout << "? " << i << " " << i + 1 << " " << i + 1 << " " << i + 2 << endl;
            cin >> r;
            a[i + 1][i + 2] = a[i][i + 1] ^ r ^ 1;
            b[i + 1][i + 2] = b[i][i + 1] ^ r ^ 1;
        }
        else {
            cout << "? " << i << " " << i - 1 << " " << i + 1 << " " << i << endl;
            cin >> r;
            a[i + 1][i] = a[i][i - 1] ^ r ^ 1;
            b[i + 1][i] = b[i][i - 1] ^ r ^ 1;
        }
    }
    for (int j = n - 2; j > 0; --j) {
        cout << "? " << n << " " << j << " " << n << " " << j + 2 << endl;
        cin >> r;
        a[n][j] = a[n][j + 2] ^ r ^ 1;
        b[n][j] = b[n][j + 2] ^ r ^ 1;
    }
    for (int i = 1; i < n - 1; ++i) {
        if (check1(i, i, a, b))
            return;
        if (check1(i, i, b, a))
            return;
        if (check2(i, i, a, b))
            return;
        if (check2(i, i, b, a))
            return;
    }
    for (int i = 2; i < n; ++i) {
        if (check1(i, i - 1, a, b))
            return;
        if (check1(i, i - 1, b, a))
            return;
        if (check2(i - 1, i, a, b))
            return;
        if (check2(i - 1, i, b, a))
            return;
    }
    return;

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