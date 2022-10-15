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
const int N = 500;
//const int M = 10000000;
int n;
vector<vector<int> > g;
vector<int> d;
vector<vector<int> > dd;
void dfs(int pos, int pr = -1) {
    d[pos] = 0;
    for (int i = 0; i < 6; ++i)
        dd[pos][i] = 0;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        dfs(to, pos);
        dd[pos][d[to]]++;
    }
    if (dd[pos][5] > 0) {
        d[pos] = 5;
        return;
    }
    if (dd[pos][4] > 0) {
        if (dd[pos][4] > 1) {
            d[pos] = 5;
            return;
        }
        for (int i = 1; i < 4; ++i) {
            if (dd[pos][i] > 0) {
                d[pos] = 5;
                return;
            }
        }
        if (dd[pos][0] == 0) {
            d[pos] = 4;
            return;
        }
        if (dd[pos][0] > 1) {
            d[pos] = 5;
            return;
        }
        if (pr != -1) {
            d[pos] = 5;
            return;
        }
        d[pos] = 4;
        return;
    }
    if (dd[pos][3] > 0) {
        int x = 0;
        for (int i = 1; i < 4; ++i)
            x += dd[pos][i];
        if (x > 1) {
            d[pos] = 5;
            return;
        }
        if (dd[pos][0] > 2) {
            d[pos] = 5;
            return;
        }
        if (dd[pos][0] <= 1) {
            d[pos] = 4;
            return;
        }
        if (pr == -1) {
            d[pos] = 4;
        }
        else
            d[pos] = 5;
        return;
    }
    if (dd[pos][2] > 0) {
        if (dd[pos][2] > 2) {
            d[pos] = 5;
            return;
        }
        if (dd[pos][2] == 2) {
            d[pos] = 3;
            return;
        }
        d[pos] = 2;
        return;
    }
    if (dd[pos][1] > 0) {
        d[pos] = 2;
        return;
    }
    if (dd[pos][0] <= 1) {
        d[pos] = 0;
        return;
    }
    if (dd[pos][0] == 2) {
        d[pos] = 1;
        return;
    }
    d[pos] = 2;
    return;
}

void solve() {
    cin >> n;
    g.resize(n);
    dd.assign(n, vector<int>(6, 0));
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d.resize(n);
    dfs(0);
    if (d[0] == 5)
        cout << "No\n";
    else
        cout << "Yes\n";
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