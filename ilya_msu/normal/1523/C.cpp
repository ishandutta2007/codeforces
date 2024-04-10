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
const ll mod = 998244353;
const ll N = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> st;
    st.push_back(0);
    vector<int> p(n);
    vector<string> res(n);
    for (int i = 1; i < n; ++i) {
        while (!st.empty()) {
            int id = st.back();
            int v = a[id];
            if (a[i] == 1) {
                p[i] = id;
                st.push_back(i);
                break;
            }
            st.pop_back();
            if (a[i] == v + 1) {
                p[i] = id;
                st.push_back(i);
                break;
            }
        }
    }
    res[0] = "1";
    for (int i = 1; i < n; ++i) {
        if (a[i] == 1) {
            res[i] = res[p[i]] + ".1";
            continue;
        }
        res[i] = res[p[i]];
        while ((!res[i].empty()) && (res[i][res[i].size() - 1] != '.'))
            res[i].pop_back();
        res[i] += to_string(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << "\n";
    }

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