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


vector<vector<int> > solve(const vector<pii>& a) {
    vector<vector<int> > res(100 + 1, vector<int> (10000 + 1, -1));
    res[0][0] = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int x = res.size() - 1; x >= 0; --x) {
            for (int y = res[x].size() - 1; y >= 0; --y) {
                if (res[x][y] == -1)
                    continue;
                for (int j = 1; j <= a[i].second; ++j) {
                    res[x + j][y + a[i].first * j] = res[x][y] + 1;
                }
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(101, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }
    int num = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i])
            ++num;
    }
    if (num <= 2) {
        cout << n << endl;
        return;
    }
    vector<pii> b;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i]) {
            b.push_back(pii(i, c[i]));
        }
    }
    vector<vector<int> > res = solve(b);
    int ans = 0;
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 1; j <= c[i]; ++j) {
            int sum = j * i;
            if (res[j][sum] == 1) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    
    
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