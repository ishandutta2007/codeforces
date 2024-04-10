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


int mul(const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i)
        res += a[i] * b[i];
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        bool ok = 1;
        vector<vector<int> > b;
        for (int j = 0; j < n; ++j) {
            if (j == i)
                continue;
            vector<int> x(5);
            for (int k = 0; k < 5; ++k)
                x[k] = a[j][k] - a[i][k];
            b.push_back(x);
        }
        for (int j = 0; j < b.size(); ++j) {
            for (int k = 0; k < j; ++k) {
                if (mul(b[j], b[k]) > 0) {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            res.push_back(i + 1);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << "\n";
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