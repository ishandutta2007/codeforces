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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;



void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.')
            ++sum;
        if ((s[i] == '.') && ((i == n - 1) || (s[i + 1] != '.')))
            ++count;
    }
    for (int i = 0; i < m; ++i) {
        int pos;
        string t;
        cin >> pos >> t;
        --pos;
        if (s[pos] == '.')
            --sum;
        if (t[0] == '.')
            ++sum;
        if (t[0] == '.') {
            if (s[pos] != '.') {
                if ((pos > 0) && (pos + 1 < n) && (s[pos - 1] == '.') && (s[pos + 1] == '.'))
                    --count;
                if (((pos == 0) || (s[pos - 1] != '.')) && ((pos == n - 1) || (s[pos + 1] != '.')))
                    ++count;
            }
        }
        if (t[0] != '.') {
            if (s[pos] == '.') {
                if ((pos > 0) && (pos + 1 < n) && (s[pos - 1] == '.') && (s[pos + 1] == '.'))
                    ++count;
                if (((pos == 0) || (s[pos - 1] != '.')) && ((pos == n - 1) || (s[pos + 1] != '.')))
                    --count;
            }
        }
        s[pos] = t[0];
        cout << sum - count << endl;
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