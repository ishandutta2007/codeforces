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
//#include<atcoder/dsu>


//using namespace atcoder;
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int w = count(s.begin(), s.end(), 'W');
    int ww = w + k;
    int c = 0;
    vector<int> st, en;
    for (int i = 0; i < n; ++i) {
        if ((s[i] == 'W') && ((i == 0) || (s[i - 1] == 'L'))) {
            st.push_back(i);
        }
        if ((s[i] == 'W') && ((i == n - 1) || (s[i + 1] == 'L'))) {
            en.push_back(i + 1);
        }
    }
    vector<int> p;
    for (int i = 1; i < st.size(); ++i) {
        p.push_back(st[i] - en[i - 1]);
    }
    sort(p.begin(), p.end());
    int id = 0;
    while ((id < p.size()) && (p[id] <= k)) {
        k -= p[id];
        ++id;
    }
    c = max(1, (int)st.size() - id);
    if (ww == 0) {
        cout << 0 << "\n";
        return;
    }
    cout << min(ww, n) * 2 - c << "\n";
}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}