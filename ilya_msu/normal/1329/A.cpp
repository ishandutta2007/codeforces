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
#include<cmath>





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
const ll mod = 998244353;//1000 * 1000 * 1000 + 7;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    for (int i = 0; i < m; ++i)
        cin >> l[i];
    vector<int> p(m);
    int fr = n;
    for (int i = 0; i < m; ++i) {
        p[i] = i + 1;
        if (p[i] > n - l[i] + 1) {
            cout << -1 << endl;
            return;
        }
        fr = min(fr, n - (p[i] + l[i] - 1));
    }
    for (int i = 1; i < m; ++i) {
        int sh = min(fr, l[i - 1] - 1);
        p[i] = p[i - 1] + 1 + sh;
        fr -= sh;
    }
    if (fr != 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < m; ++i) {
        cout << p[i] << " ";
    }
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