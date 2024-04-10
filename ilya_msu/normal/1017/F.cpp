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

uint n, a, b, c, d;

uint f(uint x) {
    return (((a * x) + b) * x + c) * x + d;
}

uint res;
const int N = (3 * 100 * 1000 * 1000 + 20) / 6;


void add(uint p) {
    uint m = n / p;
    uint ad = 0;
    while (m > 0) {
        ad += m;
        m /= p;
    }
    res += ad * f(p);
}

void solve() {
    cin >> n >> a >> b >> c >> d;
    vector<bool> pp1(N, 1), pp2(N, 1);
    res = 0;
    add(2);
    add(3);
    for (int i = 0; i < N; ++i) {
        if ((pp1[i]) && (i)) {
            uint x = 6 * i + 1;
            for (uint j = i + x; j < N; j += x) {
                pp1[j] = 0;
            }
            for (uint j = 5 * i; j < N; j += x) {
                pp2[j] = 0;
            }
            add(x);
        }
        if (pp2[i]) {
            uint x = 6 * i + 5;
            add(x);
            for (uint j = i + x; j < N; j += x) {
                pp2[j] = 0;
            }
            for (uint j = 5 * i + 4; j < N; j += x) {
                pp1[j] = 0;
            }
        }
    }
    cout << res << endl;
    
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