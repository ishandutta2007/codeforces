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

vector<vector<int> > g;
vector<int> used;
vector<vector<int> > ans;
int id = 0;

void dfs(int pos) {
    ans[id].push_back(pos);
    used[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to])
            continue;
        dfs(to);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pii> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = pii(a[i], i);
    }
    sort(b.begin(), b.end());
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        g[i].push_back(b[i].second);
        g[b[i].second].push_back(i);
    }
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ans.push_back(vector<int>());
            dfs(i);
            ++id;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size();
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j] + 1;
        }
        cout << "\n";
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