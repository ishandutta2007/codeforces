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


struct moves {
    int i, r, c;
    moves(int ii, int rr, int cc) : i(ii), r(rr), c(cc) {}
};

vector<moves> res;
int cnt = 0;

bool move(vector<vector<int> >& a) {
    
    int n = a[0].size();
    for (int i = 0; i < n; ++i) {
        if ((a[0][i] == a[1][i]) && (a[0][i] > 0)) {
            res.push_back(moves(a[0][i], 1, i + 1));
            a[1][i] = 0;
            ++cnt;
            return 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if ((a[2][i] == a[3][i]) && (a[2][i] > 0)) {
            res.push_back(moves(a[2][i], 4, i + 1));
            a[2][i] = 0;
            ++cnt;
            return 1;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if ((a[1][i] > 0) && (a[1][i + 1] == 0)) {
            res.push_back(moves(a[1][i], 2, i + 2));
            swap(a[1][i], a[1][i + 1]);
            return 1;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if ((a[2][i] == 0) && (a[2][i + 1] > 0)) {
            res.push_back(moves(a[2][i + 1], 3, i + 1));
            swap(a[2][i], a[2][i + 1]);
            return 1;
        }
    }
    if ((a[1][n - 1] > 0) && (a[2][n - 1] == 0)) {
        res.push_back(moves(a[1][n - 1], 3, n));
        swap(a[1][n - 1], a[2][n - 1]);
        return 1;
    }
    if ((a[1][0] == 0) && (a[2][0] > 0)) {
        res.push_back(moves(a[2][0], 2, 1));
        swap(a[1][0], a[2][0]);
        return 1;
    }
    return 0;

   

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(4, vector<int> (n));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    if (!move(a)) {
        cout << -1 << endl;
        return;
    }
    while (cnt < k) {
        move(a);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].i << " " << res[i].r << " " << res[i].c << "\n";
    }

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