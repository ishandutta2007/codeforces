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
//#include<unordered_map>




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
const ll N = 1000000;
//const int M = 10000000;

vector<vector<int> > g;
vector<int> d1, d2;

void dfs(int pos, int pr = -1) {
    int sum = 0;
    int g1 = 0, g2 = 0;
    int m1 = g.size() + 1000, m2 = g.size() + 1000;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        dfs(to, pos);
        if (d2[to] >= d1[to]) {
            ++g2;
            sum += d2[to];
        }
        else {
            ++g1;
            sum += d1[to];
            int dif = d1[to] - d2[to];
            if (dif < m1) {
                m2 = m1;
                m1 = dif;
            }
            else {
                if (dif < m2) {
                    m2 = dif;
                }
            }
        }
    }
    d2[pos] = max(d2[pos], sum);
    if (g2 > 0)
        d2[pos] = max(d2[pos], sum + 1);
    if (g2 >= 2) {
        d1[pos] = sum + 2;
        return;
    }
    if (g2 == 1) {
        d1[pos] = sum + 2 - m1;
        return;
    }
    d1[pos] = sum + 2 - m1 - m2;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    g.resize(n);
    d1.assign(n, 0);
    d2.assign(n, 0);
    vector<int> deg(n, 0);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[b].push_back(a);
        g[a].push_back(b);
        ++deg[a], ++deg[b];
    }
    int m = 0;
    for (int i = 0; i < n; ++i)
        m = max(m, deg[i]);
    if (x >= y) {
        if (m == n - 1) {
            cout << x + y * (n - 2) << endl;
        }
        else
            cout << y * (n - 1) << endl;
        return;
    }
    dfs(0);
    cout << x * max(d1[0], d2[0]) + y * (n - 1 - max(d1[0], d2[0])) << endl;    
}





//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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