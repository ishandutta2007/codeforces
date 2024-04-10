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
const ll mod = 998244353;


void solve() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a;
        int c = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1])
                ++c;
            else {
                a.push_back(c);
                c = 1;
            }
        }
        if (a.empty()) {
            cout << (n + 2) / 3 << "\n";
            continue;
        }
        if (s[0] == s[n - 1]) {
            a[0] += c;
        }
        else 
        a.push_back(c);
        int res = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < 3)
                continue;
            res += a[i] / 3;
        }
        cout << res << "\n";


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