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
#include <fstream>



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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;



void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.rbegin(), s2.rend());
    int n = s1.size();
    int n1 = (n + 1) / 2, n2 = n / 2;
    s1.resize(n1);
    s2.resize(n2);
    string res;
    res.resize(n);
    int i1 = 0, i2 = 0, i = 0;
    while (i < n) {
        if (i % 2 == 0) {
            if (s1[i1] < s2[i2]) {
                res[i] = s1[i1];
                ++i;
                ++i1;
            }
            else {
                break;
            }
        }
        else {
            if (s2[i2] > s1[i1]) {
                res[i] = s2[i2];
                ++i;
                ++i2;
            }
            else {
                break;
            }
        }
    }
    int j = n - 1, j1 = n1 - 1, j2 = n2 - 1;
    while (j >= i) {
        if ((i + n - 1 - j) % 2 == 0) {
            res[j] = s1[j1];
            --j;
            --j1;
        }
        else {
            res[j] = s2[j2];
            --j;
            --j2;
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