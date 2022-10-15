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
#include<unordered_map>
#include<deque>




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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;



void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> a(r);
    for (int i = 0; i < r; ++i)
        cin >> a[i];
    string let = "";
    for (int i = 0; i < 26; ++i) {
        let += 'a' + i;
        let += 'A' + i;
    }
    for (int i = 0; i < 10; ++i)
        let += '0' + i;
    int all = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) 
            all += (a[i][j] == 'R');
    }
    int x1 = all / k;
    int x2 = x1 + 1;
    int r2 = all % k;
    int r1 = k - r2;
    //cerr << x1 << " " << r1 << " " << x2 << " " << r2 << endl;
    vector<string> res(r, string(c, let[k - 1]));
    int i1 = 0, j1 = 0;
    for (int i = 0; i < r1; ++i) {
        int cnt = 0;
        while (cnt < x1) {
            res[i1][j1] = let[i];
            if (a[i1][j1] == 'R')
                ++cnt;
            if ((i1 & 1) == 0)
                ++j1;
            else 
                --j1;
            if (j1 == c) {
                ++i1;
                j1 = c - 1;
            }
            if (j1 == -1) {
                ++i1;
                j1 = 0;
            }
        }
    }
    for (int i = r1; i < k; ++i) {
        int cnt = 0;
        while (cnt < x2) {
            res[i1][j1] = let[i];
            if (a[i1][j1] == 'R')
                ++cnt;
            if ((i1 & 1) == 0)
                ++j1;
            else
                --j1;
            if (j1 == c) {
                ++i1;
                j1 = c - 1;
            }
            if (j1 == -1) {
                ++i1;
                j1 = 0;
            }
        }
    }
    for (int i = 0; i < r; ++i)
        cout << res[i] << "\n";


}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}