#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 150000;
const int K = 600;
const int MOD = 998244353;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }
int sub(int a, int b){ return add(a, MOD - b); }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int in[N+5], out[N+5];
vector <int> graf[N+5];
int sz[N+5];

int sol[N+5];
int typ[N+5], qv[N+5], qd[N+5];

int tjm;

int n;

vector <pair <int, int>> ord;

void dfs_sz(int v, int p){
    in[v] = ++tjm;
    sz[v] = 1;
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs_sz(c, v);
        sz[v] += sz[c];
    }
    out[v] = tjm;
    ord.push_back({v, p});
}

vector <tuple <int, int, int>> vec[N+5];

void dfs_fin(){
    for(auto pr : ord){
        int v = pr.first;
        int p = pr.second;
        sort(vec[v].begin(), vec[v].end());
        reverse(vec[v].begin(), vec[v].end());
        while(vec[v].size() && get<0>(vec[v].back()) < in[v]){
            int k = get<1>(vec[v].back());
            int d = get<2>(vec[v].back());
            sol[k] = sub(sol[k], mul(n - sz[v], d));
            vec[v].pop_back();
        }
        for(auto c : graf[v]){
            if(c == p) continue;
            while(vec[v].size() && get<0>(vec[v].back()) <= out[c]){
                int k = get<1>(vec[v].back());
                int d = get<2>(vec[v].back());
                sol[k] = sub(sol[k], mul(sz[c], d));
                vec[v].pop_back();
            }
        }
        while(vec[v].size()){
            int k = get<1>(vec[v].back());
            int d = get<2>(vec[v].back());
            sol[k] = sub(sol[k], mul(n - sz[v], d));
            vec[v].pop_back();
        }
    }
}

int dole[N+5];
int mj[N+5];
int dp[N+5];
int glob;

void dfs_calc(){
    for(int i=n-1; i>=0; i--){
        auto pr = ord[i];
        int v = pr.first;
        int p = pr.second;
        dp[v] = add(dp[v], dole[v]);
        dp[v] = add(dp[v], glob);
        for(auto c : graf[v]){
            if(c == p) continue;
            dole[c] = add(dole[c], dole[v]);
            dole[c] = add(dole[c], mul(mj[v], sz[c]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int qrs;
    cin >> n >> qrs;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=qrs; i++){
        cin >> typ[i];
        if(typ[i] == 1) cin >> qv[i] >> qd[i];
        else cin >> qv[i];
    }
    dfs_sz(1, 0);
    int svi = 0;
    for(int lq=1; lq<=qrs; lq+=K){
        int rq = lq + K - 1;
        rq = min(rq, qrs);
        for(int i=1; i<=n; i++) dole[i] = mj[i] = 0;
        glob = 0;
        for(int i=lq; i<=rq; i++){
            if(typ[i] == 1){
                mj[qv[i]] = add(mj[qv[i]], qd[i]);
                glob = add(glob, mul(n - sz[qv[i]], qd[i]));
                dole[qv[i]] = sub(dole[qv[i]], mul(n - sz[qv[i]], qd[i]));
                svi = add(svi, mul(n, qd[i]));
                continue;
            }
            sol[i] = svi;
            sol[i] = sub(sol[i], dp[qv[i]]);
            for(int j=lq; j<i; j++){
                if(typ[j] == 2) continue;
                if(qv[i] != qv[j]) vec[qv[j]].push_back({in[qv[i]], i, qd[j]});
            }
        }
        dfs_calc();
    }
    dfs_fin();
    int inv = pw(n, MOD - 2);
    for(int i=1; i<=qrs; i++){
        if(typ[i] == 2){
            cout << mul(sol[i], inv) << "\n";
        }
    }
    return 0;
}