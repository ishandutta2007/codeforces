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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

vector<vector<int> > ans;
vector<vector<pair<int, int> > > g;

map<pair<pii, int>, int > mp;

int get(int i, int j, int c = 0) {
    auto it = mp.find(make_pair(pii(i, j), c));
    if (it != mp.end())
        return it->second;
    for (int id = 0; id < g[i].size(); ++id) {
        int to = g[i][id].first;
        int v = g[i][id].second;
        if (v < c)
            continue;
        if (get(j, to, v) == 0) {
            mp[make_pair(pii(i, j), c)] = 1;
            return 1;
        }
    }
    mp[make_pair(pii(i, j), c)] = 0;
    return 0;
}


void solve() {
    int n, m;
    cin >> n >> m;
    ans.assign(n, vector<int>(n, -1));
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        --x, --y;
        g[x].push_back(make_pair(y, c));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = get(i, j);
            if (ans[i][j] == 1)
                cout << 'A';
            else
                cout << 'B';
        }
        cout << endl;
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