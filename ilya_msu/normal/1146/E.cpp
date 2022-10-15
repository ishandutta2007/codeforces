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
#include <random>
#include <chrono>


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

const int N = 100000 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), res(n, N);
    vector<vector<int> > pos(N), neg(N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            pos[a[i]].push_back(i);
        }
        if (a[i] < 0) {
            neg[-a[i]].push_back(i);
        }
        if (a[i] == 0)
            res[i] = 0;
    }
    string sg, s;
    vector<int> val(q);
    for (int i = 0; i < q; ++i) {
        cin >> s >> val[i];
        sg += s;
    }
    int pos_id = N - 1;
    int tr = 1;
    s = sg;
    for (int qq = q - 1; qq >= 0; --qq) {
        if ((s[qq] == '>') && (val[qq] >= 0)) {
            int x = val[qq];
            for (int i = pos_id; i > x; --i) {
                for (int j = 0; j < pos[i].size(); ++j) {
                    res[pos[i][j]] = -tr * abs(a[pos[i][j]]);
                }
                for (int j = 0; j < neg[i].size(); ++j) {
                    res[neg[i][j]] = -tr * abs(a[neg[i][j]]);
                }
            }
            pos_id = min(x, pos_id);
        }
        if ((s[qq] == '<') && (val[qq] <= 0)) {
            int x = -val[qq];
            for (int i = pos_id; i > x; --i) {
                for (int j = 0; j < pos[i].size(); ++j) {
                    res[pos[i][j]] = tr * abs(a[pos[i][j]]);
                }
                for (int j = 0; j < neg[i].size(); ++j) {
                    res[neg[i][j]] = tr * abs(a[neg[i][j]]);
                }
            }
            pos_id = min(x, pos_id);
        }
        if ((s[qq] == '>') && (val[qq] < 0)) {
            int x = -val[qq] - 1;
            for (int i = pos_id; i > x; --i) {
                for (int j = 0; j < pos[i].size(); ++j) {
                    res[pos[i][j]] = -tr * abs(a[pos[i][j]]);
                }
                for (int j = 0; j < neg[i].size(); ++j) {
                    res[neg[i][j]] = -tr * abs(a[neg[i][j]]);
                }
            }
            tr *= -1;
            pos_id = min(x, pos_id);
        }
        if ((s[qq] == '<') && (val[qq] > 0)) {
            int x = val[qq] - 1;
            for (int i = pos_id; i > x; --i) {
                for (int j = 0; j < pos[i].size(); ++j) {
                    res[pos[i][j]] = tr * abs(a[pos[i][j]]);
                }
                for (int j = 0; j < neg[i].size(); ++j) {
                    res[neg[i][j]] = tr * abs(a[neg[i][j]]);
                }
            }
            tr *= -1;
            pos_id = min(x, pos_id);
        }
        

    }
    for (int i = pos_id; i > 0; --i) {
        for (int j = 0; j < pos[i].size(); ++j) {
            res[pos[i][j]] = tr * a[pos[i][j]];
        }
        for (int j = 0; j < neg[i].size(); ++j) {
            res[neg[i][j]] = tr * a[neg[i][j]];
        }
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;

    
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