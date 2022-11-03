#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<string> s;
vector<int> val;
vector<int> g0, g1;
vector<int> p;
vector<int> ifch;

void dfs(int v){
    if(g0[v] != -1){
        dfs(g0[v]);
    }
    if(g1[v] != -1){
        dfs(g1[v]);
    }
    if(s[v] == "IN"){
        return;
    }
    if(s[v] == "AND"){
        val[v] = val[g0[v]] & val[g1[v]];
        return;
    }
    if(s[v] == "OR"){
        val[v] = val[g0[v]] | val[g1[v]];
        return;
    }
    if(s[v] == "XOR"){
        val[v] = val[g0[v]] ^ val[g1[v]];
        return;
    }
    if(s[v] == "NOT"){
        val[v] = 1 - val[g0[v]];
        return;
    }
}

void dfs2(int v){
    if(s[v] == "IN"){
        return;
    }
    if(s[v] == "AND"){
        if(val[v] == ((1 - val[g0[v]]) & val[g1[v]])){
            ifch[g0[v]] = val[0];
        }else{
            ifch[g0[v]] = ifch[v];
        }
        dfs2(g0[v]);

        if(val[v] == ((1 - val[g1[v]]) & val[g0[v]])){
            ifch[g1[v]] = val[0];
        }else{
            ifch[g1[v]] = ifch[v];
        }
        dfs2(g1[v]);
        return;
    }
    if(s[v] == "OR"){
        if(val[v] == ((1 - val[g0[v]]) | val[g1[v]])){
            ifch[g0[v]] = val[0];
        }else{
            ifch[g0[v]] = ifch[v];
        }
        dfs2(g0[v]);

        if(val[v] == ((1 - val[g1[v]]) | val[g0[v]])){
            ifch[g1[v]] = val[0];
        }else{
            ifch[g1[v]] = ifch[v];
        }
        dfs2(g1[v]);
        return;
    }
    if(s[v] == "XOR"){
        if(val[v] == ((1 - val[g0[v]]) ^ val[g1[v]])){
            ifch[g0[v]] = val[0];
        }else{
            ifch[g0[v]] = ifch[v];
        }
        dfs2(g0[v]);

        if(val[v] == ((1 - val[g1[v]]) ^ val[g0[v]])){
            ifch[g1[v]] = val[0];
        }else{
            ifch[g1[v]] = ifch[v];
        }
        dfs2(g1[v]);
        return;
    }
    if(s[v] == "NOT"){
        ifch[g0[v]] = ifch[v];
        dfs2(g0[v]);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    s.resize(n);
    val.resize(n);
    g0.resize(n, -1);
    g1.resize(n, -1);
    p.resize(n);
    ifch.resize(n, -1);
    p[0] = -1;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        if(s[i] == "OR" || s[i] == "XOR" || s[i] == "AND"){
            cin >> g0[i] >> g1[i];
            --g0[i];
            --g1[i];
            p[g0[i]] = p[g1[i]] = i;
        }else if(s[i] == "NOT"){
            cin >> g0[i];
            --g0[i];
            p[g0[i]] = i;
        }else if(s[i] == "IN"){
            cin >> val[i];
        }
    }
    dfs(0);
    ifch[0] = 1 - val[0];
    dfs2(0);
    for(int i = 0; i < n; ++i){
        if(s[i] == "IN"){
            cout << ifch[i];
        }
    }
    cout << endl;
    return 0;
}