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
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 100 * 1000 + 10;
//const ll mod = 3046201;
vector<vector<int> > g;
vector<int> used;
int x;

int dfs(int pos) {
    int res = 1;
    used[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (!used[to])
            res += dfs(to);
    }
    if (pos == x)
        res -= 10000;
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n >> x;
    --x;
    vector<int> a(n);
    vector<int> next(n);
    g.resize(n);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (a[i] >= 0) {
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }
    }
    vector<int> comp;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int x = dfs(i);
            if (x > 0)
                comp.push_back(x);
        }
    }
    int add = 1;
    while(a[x] != -1) {
        x = a[x];
        ++add;
    }
    vector<bool> sum(1001, false);
    sum[0] = 1;
    sort(comp.begin(), comp.end());
    for (int i = 0; i < comp.size(); ++i) {
        for (int j = 1000; j >= 0; --j)
            if (sum[j])
                sum[j + comp[i]] = 1;
    }
    for (int i = 0; i < sum.size(); ++i) 
        if (sum[i])
            printf("%d\n", i + add);
    return 0;
}