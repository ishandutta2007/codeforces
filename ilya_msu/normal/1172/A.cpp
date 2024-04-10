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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int pos1 = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 1)
            pos1 = i;
    }
    bool ok = 1;
    if (pos1 != -1) {
        for (int i = pos1; i < n; ++i) {
            if (b[i] != i - pos1 + 1)
                ok = 0;
        }
    }
    if (pos1 == -1)
        ok = 0;
    int res1 = 0;
    int res2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0)
            res1 = max(res1, n + 1 - a[i]);
    }
    res2 = res1;
    for (int i = 0; i < n; ++i) {
        if (((!ok) || (i < pos1)) && (b[i] > 0)) {
            res1 = max(res1, i + 1 + n - b[i] + 1);
        }
        if (b[i] > 0)
            res2 = max(res2, i + 1 + n - b[i] + 1);
    }
    //cerr << ok << " " << pos1 << " " << res1 << " " << res2 << "\n";
    if ((ok) && (res1 <= pos1))
        cout << res1 << endl;
    else
        cout << res2 << endl;    
    
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