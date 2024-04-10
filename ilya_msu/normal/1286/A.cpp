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
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    int x0 = n / 2, x1 = (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<vector<vector<int> > > d0(n + 1, vector<vector<int> >(n + 1, 
            vector<int>(n + 1, 200)));
    vector<vector<vector<int> > > d1(n + 1, vector<vector<int> >(n + 1, 
            vector<int>(n + 1, 200)));
    d1[0][0][0] = 0;
    d0[0][0][0] = 0;
    if (p[0] == 0) {
        d1[1][1][0] = 0;
        d0[1][0][1] = 0;
    }
    else {
        if (p[0] & 1)
            d1[1][1][0] = 0;
        else 
            d0[1][0][1] = 0;
    }
    for (int i1 = 1; i1 < n; ++i1) {
        for (int i2 = 0; i2 < n; ++i2) {
            for (int i3 = 0; i3 < n; ++i3) {
                    if (p[i1] != 0) {
                        if (p[i1] & 1) {
                            d1[i1 + 1][i2 + 1][i3] = min(d1[i1 + 1][i2 + 1][i3], d0[i1][i2][i3] + 1);
                        }
                        else {
                            d0[i1 + 1][i2][i3 + 1] = 
                            min(d0[i1 + 1][i2][i3 + 1], d0[i1][i2][i3]);
                        }
                    }
                    else {
                        d1[i1 + 1][i2 + 1][i3] = min(d1[i1 + 1][i2 + 1][i3], d0[i1][i2][i3] + 1);
                        d0[i1 + 1][i2][i3 + 1] = 
                            min(d0[i1 + 1][i2][i3 + 1], d0[i1][i2][i3]);
                    }
                    if (p[i1] != 0) {
                        if (p[i1] & 1) {
                            d1[i1 + 1][i2 + 1][i3] = min(d1[i1 + 1][i2 + 1][i3], d1[i1][i2][i3]);
                        }
                        else {
                            d0[i1 + 1][i2][i3 + 1] = 
                            min(d0[i1 + 1][i2][i3 + 1], d1[i1][i2][i3] + 1);
                        }
                    }
                    else {
                        d1[i1 + 1][i2 + 1][i3] = min(d1[i1 + 1][i2 + 1][i3], d1[i1][i2][i3]);
                        d0[i1 + 1][i2][i3 + 1] = 
                            min(d0[i1 + 1][i2][i3 + 1], d1[i1][i2][i3] + 1);
                    }

            }
        }
    }
    
    cout << min(d0[n][x1][x0], d1[n][x1][x0]) << endl;

}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}