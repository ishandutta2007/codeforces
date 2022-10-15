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
const ll N = 1001;
//const int M = 10000000;

vector<int> used;
vector<vector<int> > g;
bool ok;
void dfs(int pos, int col = 1) {
    used[pos] = col;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to]) {
            if (used[to] == col) {
                ok = 0;
            }
        }
        else
            dfs(to, 3 - col);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    ok = 1;
    vector<vector<int> > ed(n, vector<int>(n, 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ed[a][b] = ed[b][a] = 0;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            if (ed[i][j]) {
                g[i].push_back(j);
                g[j].push_back(i);

            }
        }
    string s;
    s.resize(n);
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0) {
            s[i] = 'b';
            continue;
        }
        if (used[i])
            continue;
        dfs(i);
    }
    if (!ok) {
        cout << "No\n";
        return;
    }
    //cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        if (used[i] == 1)
            s[i] = 'a';
        if (used[i] == 2)
            s[i] = 'c';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((((s[i] == 'a') && (s[j] == 'c')) || ((s[i] == 'c') && (s[j] == 'a'))) && (ed[i][j] == 0))
                ok = 0;
        }
    }
    if (!ok) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    cout << s << endl;

    

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