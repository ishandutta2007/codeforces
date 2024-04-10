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
    string s;
    cin >> s;
    int n = s.size();
    int r = n % 4;
    int m = n / 4;
    string res = "";
    if (r >= 2) {
        res += s[2 * m];
    }
    vector<int> c(3, 0);
    int i1 = 2 * m - 1, i2 = n - 2 * m;
    for (int i = 0; i < m; ++i) {
        //cerr << i1 << " " << i2 << endl;
        c.assign(3, 0);
        ++c[s[i1] - 'a'];
        ++c[s[i1 - 1] - 'a'];
        ++c[s[i2] - 'a'];
        ++c[s[i2 + 1] - 'a'];
        for (int j = 0; j < 3; ++j)
            if (c[j] >= 2) {
                res += 'a' + j;
                break;
            }
        i1 -= 2;
        i2 += 2;
    }
    reverse(res.begin(), res.end());
    cout << res;
    if (r >= 2)
        res.resize(res.size() - 1);
    reverse(res.begin(), res.end());
    cout << res << endl;
    return;
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