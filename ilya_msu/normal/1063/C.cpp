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
    int n;
    cin >> n;
    vector<string> c(n);
    
    int l = 0;
    int r = (1 << (n - 1));
    int m = r / 2;
    cout << "0 0" << endl;
    cin >> c[0];
    if (n == 1) {
        cout << "1 0 1 1" << endl;
        return;
    }
    cout << r / 2 << " 0" << endl;
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
        if (c[0] == c[i]) {
            l = m;
        }
        else {
            r = m;
        }
        m = (l + r) / 2;
        if (i + 1 < n)
            cout << m << " 0" << endl;
    }
    //cout << l << " " << r << endl;
    cout << l + 1 << " 1 " << l + 2 << " 3" << endl;


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