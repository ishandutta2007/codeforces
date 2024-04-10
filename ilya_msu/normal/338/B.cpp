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
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

vector<int> p;
vector<vector<int> > g;
vector<int> din;
vector<pii> M1, M2;
vector<int> ans;
int n, m, d;

int dfs1(int pos, int pr = -1) {
    if (pr == -1)
        din[pos] = 0;
    else
        din[pos] = din[pr] + 1;
    vector<pii> temp;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        temp.push_back(pii(dfs1(to, pos) + 1, to));
    }
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    if (temp.size() > 0)
        M1[pos] = temp[0];
    else
        M1[pos] = pii(-1, -1);
    if (M1[pos].first == 0)
        M1[pos].first = -1;

    if (temp.size() > 1)
        M2[pos] = temp[1];
    else
        M2[pos] = pii(-1, -1);
    if (M2[pos].first == 0)
        M2[pos].first = -1;
    int res = -1;
    if (p[pos])
        res = 0;
    res = max(res, M1[pos].first);
    return res;
}

void dfs2(int pos, int pr = -1, int D = -1) {
    int x = max(D, M1[pos].first);
    ans[pos] = (x <= d);
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        int y;
        if (to == M1[pos].second) {
            y = max(D, M2[pos].first);
        }
        else
            y = max(D, M1[pos].first);
        if (y != -1)
            ++y;
        if (p[pos])
            y = max(y, 1);
        dfs2(to, pos, y);
    }
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    cin >> n >> m >> d;
    g.resize(n);
    p.assign(n, false);
    din.resize(n);
    M1.resize(n);
    M2.resize(n);
    int x;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        p[x - 1] = true;
    }
    int f, s;
    for (int i = 0; i < n - 1; ++i) {
        cin >> f >> s;
        --f, --s;
        g[f].push_back(s);
        g[s].push_back(f);
    }
    dfs1(0);
    ans.resize(n);
    dfs2(0);
    int res = 0;
    for (int i = 0; i < n; ++i)
        if (ans[i])
            ++res;
    cout << res << endl;
    return 0;
}