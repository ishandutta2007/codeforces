#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll oldres[200005];
ll res[200005];
ll fnres[200005];
int poz[200005];
vector <int> graf[200005];
vector <ll> pre[200005];
vector <ll> suf[200005];
int par[200005];

const int MOD = 1000000007;

ll mul(ll a, ll b){
    a %= MOD;
    b %= MOD;
    return (a*b)%MOD;
}

void dfs(int v){
    oldres[v] = 1;
    vector <int> vec;
    for(auto c : graf[v]){
        dfs(c);
        oldres[v] = mul(oldres[v], oldres[c]+1);
        vec.push_back(c);
    }
    int x = vec.size();
    if(x == 0) return;
    for(int i=0; i<x; i++) poz[vec[i]] = i;
    pre[v].push_back((oldres[vec[0]]+1)%MOD);
    for(int i=1; i<x; i++) pre[v].push_back(mul(pre[v][i-1], oldres[vec[i]]+1));
    suf[v].push_back((oldres[vec[x-1]]+1)%MOD);
    for(int i=x-2; i>=0; i--) suf[v].push_back(mul(suf[v][x-i-2], oldres[vec[i]]+1));
}

void dfs1(int v){
    if(v == 1) res[v] = fnres[v] = oldres[v];
    else{
        int pr = par[v];
        int x = poz[v];
        int b = pre[par[v]].size();
        ll d=1;
        if(x > 0) d = mul(pre[pr][x-1], d);
        if(b-x >= 2) d = mul(d, suf[pr][b-x-2]);
        d = mul(d, res[par[pr]]+1);
        res[pr] = d;
        res[v] = mul(oldres[v], res[pr]+1);
        fnres[v] = res[v];
    }
    for(auto c : graf[v]) dfs1(c);
}

int main(){

    int n;
    cin >> n;
    for(int i=2; i<=n; i++){
        cin >> par[i];
        graf[par[i]].push_back(i);
    }
    //res[0] = 1;
    dfs(1);
    dfs1(1);
    for(int i=1; i<=n; i++) cout << fnres[i] << " ";
    return 0;
}