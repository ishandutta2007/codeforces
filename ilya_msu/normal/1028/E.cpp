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
    vector<ll> b(n);
    ll m = 0, id = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] > m) {
            m = b[i];
            id = i;
        }
    }
    if (m == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    id = -1;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (j == n)
            j = 0;
        if ((b[i] < m) && (b[j] == m)) {
            id = j;
            break;
        }
    }
    if (id == -1) {
        cout << "NO\n";
        return;
    }
    vector<ll> a(n);
    a[id] = b[id];
    for (int i = id - 1; i > id - n; --i) {
        int j = (i + n) % n;
        int j1 = (i + n + 1) % n;
        int k = (i - 1 + 2 * n) % n;
        a[j] = b[j];
        while (a[j] <= b[k])
            a[j] += a[j1];
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    

}

//#define LOCAL

int main() {
    //ios_base::sync_with_stdio(0);
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