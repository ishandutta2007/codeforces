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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pii> t(n);
    vector<int> tt(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first;
        tt[i] = t[i].first;
        t[i].second = i;
    }
    sort(t.begin(), t.end());

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = t[i].second;
    }
    int ok = 1;
    vector<int> used(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        int b = p[i];
        for (int to:g[b]) {
            if (tt[to] == tt[b]) {
                cout << -1 << endl;
                return;
            }
            used[tt[to]] = i;
        }
        for (int j = 1; j < tt[b]; ++j) {
            if (used[j] != i) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] + 1 << " ";
    }
    cout << endl;

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