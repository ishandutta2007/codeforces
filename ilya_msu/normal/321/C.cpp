#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 500000;
//const int N = 1000 * 1000 * 1000 + 10;
vector<vector<int> > g;
vector<int> used1, used2;
vector<int> d, sub;
vector<int> res;

int dfs1(int pos) {
    used1[pos] = true;
    int ans = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if ((!used1[to]) && (res[to] == -1)) {
            ans += dfs1(to);
        }
    }
    sub[pos] = ans;
    return ans;
}

int dfs2(int pos, int s) {
    used2[pos] = true;
    int i1 = -1, m = INF;
    int ans = s - sub[pos];
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (res[to] != -1)
            continue;
        if (used2[to])
            continue;
        int k = dfs2(to, s);
        if (d[k] < m) {
            m = d[k];
            i1 = k;
        }
        ans = max(ans, sub[to]);
    }
    d[pos] = ans;
    if (ans < m)
        return pos;
    return i1;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int a, b;
    g.resize(n);
    res.assign(n, -1);
    d.resize(n);
    sub.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int count = 0;
    int x = 0;
    while(count < n) {
        used1.assign(n, false);
        used2.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (res[i] != -1)
                continue;
            if (used1[i])
                continue;
            int s = dfs1(i);
            int v = dfs2(i, s);
            res[v] = x;
            ++count;
        }
        ++x;
    }
    for (int i = 0; i < n; ++i) {
        cout << (char)('A' + res[i]) << " ";
    }
    cout << endl;
    return 0;
}