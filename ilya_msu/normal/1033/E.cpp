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


int q = 0;

int n;
vector<int> gr;
vector<int> used;
vector<vector<int> > g;

int findVertex() {
    vector<int> rest;
    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            rest.push_back(i);
    }
    cout << "? " << gr.size() << endl;
    for (int i = 0; i < gr.size(); ++i) {
        cout << gr[i] << " ";
    }
    cout << endl;
    int r0;
    cin >> r0;
    int st = 0, en = rest.size();
    while (en - st > 1) {
        int m = (en + st) / 2;
        int k = m - st;
        int r1;
        if (k <= 1)
            r1 = 0;
        else {
            ++q;
        cout << "? " << k << endl;
        for (int i = st; i < m; ++i) {
            cout << rest[i] << " ";
        }
        cout << endl;
        cin >> r1;
        }
        if (r1 == -1) {
            exit(0);
        }
        k = m - st + gr.size();
        ++q;
        cout << "? " << k << endl;
        for (int i = st; i < m; ++i) {
            cout << rest[i] << " ";
        }
        for (int i = 0; i < gr.size(); ++i) {
            cout << gr[i] << " ";
        }
        cout << endl;
        int r2;
        cin >> r2;
        if (r2 == -1) {
            exit(0);
        }
        if (r2 > r1 + r0) {
            en = m;
        }
        else
            st = m;
    }
    return rest[st];

}

int findEd(int v, const vector<int>& a) {
    int st = 0, en = a.size();
    int k = a.size() + 1;
    ++q;
    cout << "? " << k << endl;
    for (int i = st; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << v << endl;
    int r;
    cin >> r;
    if (r == -1) {
        exit(0);
    }
    if (r == 0)
        return -1;
    while (en - st > 1) {
        int m = (en + st) / 2;
        k = m - st + 1;
        ++q;
        cout << "? " << k << endl;
        for (int i = st; i < m; ++i) {
            cout << a[i] << " ";
        }
        cout << v << endl;
        cin >> r;
        if (r == -1) {
            exit(0);
        }
        if (r == 0) 
            st = m;
        else
            en = m;
    }
    return st;
}


vector<int> path;

bool dfs(int pos, int p, int v) {
    if (v == pos) {
        path.push_back(pos);
        return 1;
    }
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        if (dfs(to, pos, v)) {
            path.push_back(pos);
            return 1;
        }
    }
    return 0;
}

void findPath(int u, int v) {
    dfs(u, -1, v);


}

void solve() {
    cin >> n;
    gr.assign(1, 1);
    vector<int> lft(1, 1), right(0);
    used.assign(n + 1, 0);
    used[1] = 1;
    g.clear();
    g.resize(n + 1);
    while (gr.size() < n) {
        cerr << gr.size() << " " << q << endl;
        int v = findVertex();
        int lid = findEd(v, lft);
        int rid = findEd(v, right);
        if ((lid >= 0) && (rid >= 0)) {
            findPath(lft[lid], right[rid]);
            path.push_back(v);
            cout << "N " << path.size() << endl;
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << " ";
            }
            cout << endl;
            return;
        }
        if (lid >= 0) {
            g[v].push_back(lft[lid]);
            g[lft[lid]].push_back(v);
            right.push_back(v);
            used[v] = 1;
            gr.push_back(v);
        }
        if (rid >= 0) {
            g[v].push_back(right[rid]);
            g[right[rid]].push_back(v);
            lft.push_back(v);
            used[v] = 1;
            gr.push_back(v);
        }
    }
    cout << "Y " << lft.size() << endl;
    for (int i = 0; i < lft.size(); ++i) {
        cout << lft[i] << " ";
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