#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

int n, m, k;

struct edge{
    int a, b;
    int f, c;
    int ind;
    edge() = default;
    edge(int a, int b, int c, int ind) : a(a), b(b), f(0), c(c), ind(ind) {};
};

const int MX = 600 * 5;
int fin = MX - 1;

edge e[MX * 10]; int sz = 0;
vector<int> g[10 * MX];
int used[MX]; int timer = 1;

void add_edge(int a, int b, int c, int ind){
    e[sz] = edge(a, b, c, ind);
    g[a].push_back(sz++);
    e[sz] = edge(b, a, 0, ind);
    g[b].push_back(sz++);
}

void init(){
    sz = 0;
    timer++;
    for(int i = 0; i < 3 * (n + m); i++)
        g[i].clear();
    g[fin].clear();
}

int dfs(int v){
    if(v == fin) return 1;
    used[v] = timer;
    for(int i : g[v]){
        int to = e[i].b;
        if(e[i].f != e[i].c && used[to] != timer && dfs(to)){
            e[i].f++;
            e[i ^ 1].f--;
            return 1;
        }
    }
    return 0;
}

void solve(){
    //0 source
    //fin out
    //[1, m] edges
    //[m + 1, n + m] vertexes
    vector<int> szz(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add_edge(0, i + 1, 1, i);
        add_edge(i + 1, m + a, 1, i);
        add_edge(i + 1, m + b, 1, i);
        szz[a]++, szz[b]++;
    }
    int val = 0;
    for(int i = 1; i <= n; i++){
        add_edge(i + m, fin, max(0, 2 * (szz[i] - k)), -1);
        val += max(0, 2 * (szz[i] - k));
    }
    int res = 0;
    while(dfs(0)){ timer++, res++; }
    vector<int> ans(m);
    if(res == val){
        int some = 1000;
        for(int i = 0; i < m; i++)
            ans[i] = i + 1;
        vector< vector<int> > to_ans(n);
        for(int i = 0; i < m; i++){
            for(int j : g[i + 1]){
                if(e[j].c != 0 && e[j].f == e[j].c){
                    to_ans[e[j].b - (m + 1)].push_back(e[j].ind);
                }
            }
        }
        for(int i = 0; i < n; i++) { ;
            while (!to_ans[i].empty()) {
                int v1 = to_ans[i].back();
                to_ans[i].pop_back();
                int v2 = to_ans[i].back();
                to_ans[i].pop_back();
                ans[v1] = ans[v2] = some++;
            }
        }
    }
    for(int i : ans)
        cout << i << ' ';
    cout << '\n';
    return;
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m >> k;
        init();
        solve();
    }

    return 0;
}