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
int n, m;
vector<vector<pii> > g;
vector<vector<int> > ed;
vector<int> ok;
vector<int> res;




bool tryDfs(int pos, int prevM = -1) {
    ok[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        pii v = g[pos][i];
        int e = v.second;
        if (abs(e) == prevM)
            continue;
        int to = v.first;
        if (res[abs(e)] != -1)
            continue;
        if (ok[to]) {
            if (e < 0) {
                res[-e] = 0;
            }
            else
                res[e] = 1;
            return 1;
        }
        if (tryDfs(to, abs(e))) {
            if (e < 0) {
                res[-e] = 0;
            }
            else
                res[e] = 1;
            return 1;
        }
    }
    ok[pos] = 0;

    return 0;
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    ed.resize(m + 1);
    ok.assign(n + 1, 0);
    ok[0] = 1;
    res.assign(m + 1, -1);
    
    
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            if (x < 0) {
                ed[-x].push_back(-i);
            }
            else
                ed[x].push_back(i);
        }
    }
    for (int i = 0; i < m + 1; ++i) {
        if (ed[i].size() == 0)
            continue;
        if (ed[i].size() == 1) {
            ok[abs(ed[i][0])] = 1;
            if (ed[i][0] < 0)
                res[i] = 0;
            else
                res[i] = 1;
        }
        if (ed[i].size() == 2) {
            sort(ed[i].begin(), ed[i].end());
            if (ed[i][1] < 0) {
                ok[-ed[i][0]] = ok[-ed[i][1]] = 1;
                res[i] = 0;
                continue;
            }
            if (ed[i][0] > 0) {
                ok[ed[i][0]] = ok[ed[i][1]] = 1;
                res[i] = 1;
                continue;
            }
            g[-ed[i][0]].push_back(pii(ed[i][1], -i));
            g[ed[i][1]].push_back(pii(-ed[i][0], i));
        }
    }
    
    for (int i = 0; i <= n; ++i) {
        if (ok[i])
            continue;
        if (!tryDfs(i)) {
            cout << "NO\n";
            return;
        }

    }
    
    cout << "YES\n";
    for (int i = 1; i <= m; ++i) {
        if (res[i] == -1)
            res[i] = 0;
        cout << res[i];
    }
    cout << endl;
    


    
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