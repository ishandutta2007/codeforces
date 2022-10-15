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
const int N = 1000000;

vector<int> solve(const vector<int>& c, int a, int b) {
    int n = c.size();
    if (n == 0)
        return vector<int>();
    if (n == 1) {
        return vector<int>((c[0] + a - 1) / a, 0);
    }
    int res = 1000;
    vector<int> ind;
    for (int i = 0; (i - 1) * a < c[n - 1]; ++i) {
        vector<int> d(c.begin(), c.end() - 1);
        int j = 0;
        if (c[n - 1] > i * a)
            j = (c[n - 1] - i * a + b - 1) / b;
        if (n >= 2) {
            d[n - 2] = max(0, d[n - 2] - b * i - j * a);
        }
        if (n >= 3) {
            d[n - 3] = max(0, d[n - 3] - b * j);
        }
        vector<int> ans = solve(d, a, b);
        if (ans.size() + i + j < res) {
            res = ans.size() + i + j;
            ind = ans;
            for (int k = 0; k < i; ++k)
                ind.push_back(n - 1);
            for (int k = 0; k < j; ++k)
                ind.push_back(n - 2);
        }
    }
    return ind;
}


void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        ++h[i];
    }
    int res = (h[0] + b - 1) / b;
    h[0] -= res * b;
    h[2] -= res * b;
    h[1] -= res * a;
    int add = (h[n - 1] + b - 1) / b;
    h[n - 1] -= add * b;
    h[n - 2] -= add * a;
    h[n - 3] -= add * b;
    vector<int> ans(res, 2);
    for (int i = 0; i < add; ++i)
        ans.push_back(n - 1);    
    res += add;
    vector<int> c(n - 2);
    for (int i = 1; i + 1 < n; ++i)
        c[i - 1] = max(0, h[i]);
    vector<int> ans2 = solve(c, a, b);
    for (int i = 0; i < ans2.size(); ++i)
        ans.push_back(ans2[i] + 2);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    
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