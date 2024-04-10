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
    int r1, c1, r2, c2;
    moves(int _r1, int _c1, int _r2, int _c2) : r1(_r1), c1(_c1), r2(_r2), c2(_c2) {}
};


vector<moves> solve(int n, int m, vector<vector<int> > b, vector<pii> p) {
    vector<moves> res;
    int c = -1;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (b[i][j] == -1) {
                continue;
            }
            ++c;
            int d = c - j;
            if (d < 0) {
                for (int k = 0; k < -d; ++k) {
                    swap(b[i][j - k], b[i][j - 1 - k]);
                    res.push_back(moves(i, j - k, i, j - 1 - k));
                }
            }
            if (d == 0) {
                continue;
            }
            if (d > 0) {
                --c;
                int l = j + 1;
                while (b[i][l] != -1)
                    ++l;
                for (int k = l - 1; k >= j; --k) {
                    swap(b[i][k], b[i][k + 1]);
                    res.push_back(moves(i, k, i, k + 1));
                }
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        if (b[0][j] != -1) {
            swap(b[0][j], b[1][j]);
            res.push_back(moves(0, j, 1, j));
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] != -1) {
                for (int k = i - 1; k >= 1; --k) {
                    swap(b[k + 1][j], b[k][j]);
                    res.push_back(moves(k + 1, j, k, j));
                }
            }
        }
    }
    for (int t = 0; t < m; ++t) {
        int cl = 0;
        while (b[1][cl] != t)
            ++cl;
        swap(b[1][cl], b[0][cl]);
        res.push_back(moves(1, cl, 0, cl));
        for (int j = cl; j > t; --j) {
            swap(b[0][j], b[0][j - 1]);
            res.push_back(moves(0, j, 0, j - 1));
        }
        for (int j = cl; j > t; --j) {
            swap(b[1][j], b[1][j - 1]);
            res.push_back(moves(1, j - 1, 1, j));
        }
    }
    return res;

}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > b1(n, vector<int>(n, -1)), b2(n, vector<int>(n, -1));
    vector<pii> p1(m), p2(m);
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        p1[i] = pii(r, c);
        b1[r][c] = i;
    }
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        p2[i] = pii(r, c);
        b2[r][c] = i;
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<moves> r1 = solve(n, m, b1, p1);
    vector<moves> r2 = solve(n, m, b2, p2);
    cout << r1.size() + r2.size() << "\n";
    for (int i = 0; i < r1.size(); ++i) {
        cout << r1[i].r1 + 1 << " " << r1[i].c1 + 1 << " " << r1[i].r2 + 1 << " " << r1[i].c2 + 1 << "\n";
    }
    for (int i = r2.size() - 1; i >= 0; --i) {
        cout << r2[i].r2 + 1 << " " << r2[i].c2 + 1 << " " << r2[i].r1 + 1 << " " << r2[i].c1 + 1 << "\n";
    }

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