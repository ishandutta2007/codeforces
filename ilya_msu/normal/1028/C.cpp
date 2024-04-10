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
    vector<int> x1(n), x2(n), y1(n), y2(n);
    for (int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

        vector<int> x(x1.begin(), x1.end()), y(y1.begin(), y1.end());
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        x.resize(2);
        y.resize(2);

        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < y.size(); ++j) {
                int xx = x[i], yy = y[j];
                int ok = 0;
                for (int k = 0; k < n; ++k) {
                    if ((xx >= x1[k]) && (xx <= x2[k]) &&
                        (yy >= y1[k]) && (yy <= y2[k])) 
                        ++ok;
                    
                }
                if (ok >= n - 1) {
                    cout << xx << " " << yy << endl;
                    return;
                }
            }
        }
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