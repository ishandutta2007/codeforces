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
    vector<int> r(n), c(n);
    int d;
    for (int i = 0; i < n; ++i) {
        cin >> d;
        r[d - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> d;
        c[d - 1] = i + 1;
    }
    vector<int> p1(n + 1), p2(n + 1);
    for (int i = 0; i <= n; ++i)
        p1[i] = p2[i] = i;
    vector<int> r1, c1, r2, c2;
    for (int i = 0; i < n; ++i) {
        int x = p1[r[i]], y = p2[c[i]];
        if ((x == i + 1) && (y == i + 1))
            continue;
        r1.push_back(i + 1);
        c1.push_back(y);
        r2.push_back(x);
        c2.push_back(i + 1);
        for (int j = 1; j <= n; ++j) {
            if (p1[j] == i + 1) {
                p1[j] = x;
                continue;
            }
            if (p1[j] == x) {
                p1[j] = i + 1;
                continue;
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (p2[j] == i + 1) {
                p2[j] = y;
                continue;
            }
            if (p2[j] == y) {
                p2[j] = i + 1;
                continue;
            }
        }
        /* 
        cout << i << ": ";
        for (int j = 1; j <= n; ++j) {
            cout << p2[j] << " ";
        }
        cout << endl;*/
    }
    cout << r1.size() << endl;
    for (int i = 0; i < r1.size(); ++i) {
        cout << r1[i] << " " << c1[i] << " " << r2[i] << " " << c2[i] << "\n";
    }
    
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