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
    vector<int> x(n + 1);
    x[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> x[i + 1];
    }
    sort(x.begin(), x.end());
    vector<int> cnt(n + 5, 0);
    int add = 0;
    for (int i = 0; i < m; ++i) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 != 1)
            continue;
            if (x2 == 1000000000) {
                ++add;
                continue;
            }
        int id = (upper_bound(x.begin(), x.end(), x2) - x.begin());
        //cerr << id - 1 << endl;
        ++cnt[id - 1];
    }
    for (int i = cnt.size() - 2; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }
    int res = INF;
    for (int i = 1; i < cnt.size(); ++i) {
        //cerr << cnt[i] << endl;
        res = min(cnt[i] + i - 1, res);
    }
    cout << res + add << endl;

    
    
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