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

int N = 1010;

void solve() {
    vector<int> p(N, 0);
    for (int i = 3; i < N; ++i) {
        int ok = 1;
        for (int d = 2; d * d <= i; ++d) {
            if (i % d == 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            p[i] = 1;
    }
    
    int n;
    cin >> n;
    if (n == 8) {
        cout << 11 << endl;
        for (int i = 1; i < 8; ++i) {
            cout << i << " " << i + 1 << "\n";
        }
        cout << 1 << " " << 8 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 1 << " " << 4 << endl;
        cout << 1 << " " << 5 << endl;
        return;
    }
    int j = n;
    while (p[j] == 0)
        ++j;
    int d = j - n;
    cout << j << endl;
    for (int i = 1; i < n; ++i) {
        cout << i << " " << i + 1 << "\n";
    }
    cout << 1 << " " << n << "\n";
    for (int i = 1; d > 0; i += 3, --d) {
        cout << i << " " << i + 2 << "\n";
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