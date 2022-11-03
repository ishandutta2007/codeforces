#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;


vector<vector<int>> g;
vector<int> bad;

void dfs(int v){
    for(auto u: g[v]){
        if(!bad[u]){
            cout << '(';
            dfs(u);
            cout << ')';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int sz = 1;
    int cur = 0;
    g.resize(1);
    vector<int> p = {-1};
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            g[cur].push_back(sz);
            g.push_back(vector<int>());
            p.push_back(cur);
            cur = sz;
            ++sz;
        }else{
            cur = p[cur];
        }
    }
    queue<int> q;
    vector<int> deg;
    bad.resize(g.size(), 0);
    for(int i = 0; i < g.size(); ++i){
        deg.push_back(g[i].size());
    }
    for(int i = 0; i < g.size(); ++i){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(n > k){
        int z = q.front();
        q.pop();
        bad[z] = 1;
        --deg[p[z]];
        if(deg[p[z]] == 0){
            q.push(p[z]);
        }
        n -= 2;
    }
    dfs(0);
    cout << endl;



}