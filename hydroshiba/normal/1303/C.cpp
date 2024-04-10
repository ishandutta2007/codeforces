#include "bits/stdc++.h"
using namespace std;

bool pass[26];

void dfs(int i, vector<set<int>> &g){
    if(pass[i]) return;
    pass[i] = 1;

    cout << char(i + 'a');
    for(int j : g[i]) dfs(j, g);
}

void solve(){
    string s;
    cin >> s;

    vector<set<int>> g(26);
    vector<bool> check(26);

    for(int i = 0; i < 26; ++i) pass[i] = 0;

    int num = 0;
    for(int i = 0; i < s.size(); ++i){
        if(i)
            g[s[i] - 'a'].insert(s[i - 1] - 'a'),
            g[s[i - 1] - 'a'].insert(s[i] - 'a');
        if(i < s.size() - 1)
            g[s[i] - 'a'].insert(s[i + 1] - 'a'),
            g[s[i + 1] - 'a'].insert(s[i] - 'a');

        if(!check[s[i] - 'a']) ++num, check[s[i] - 'a'] = 1;
    }

    int edges = 0;
    for(int i = 0; i < 26; ++i){
        if(g[i].size() > 2){
            cout << "NO\n";
            return;
        }
        edges += g[i].size();
    }

    edges /= 2;
    if(edges > num - 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for(int i = 25; i > -1; --i) if(!check[i]) cout << char(i + 'a');
    else if(g[i].size() <= 1) dfs(i, g);

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}