#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;
const int K = 400;
const int C = N/K + 2;

int dpz[N+5][C+5];
int sz[N+5];
int dp[N+5];

vector <int> gg[N+5];
vector <int> graf[N+5];

const int INF = 10000000;

int dpn[C+5];

void solveBig(int v){
    int tsz = 0;
    dpz[v][0] = graf[v].size();
    for(int i=1; i<=C; i++) dpz[v][i] = -INF;
    for(auto c : graf[v]){
        solveBig(c);
        for(int i=0; i<=C; i++) dpn[i] = dpz[v][i];
        for(int i=0; i<=min(C, sz[c]); i++){
            for(int j=0; j<=tsz; j++){
                //cnt++;
                if(i+j+1 > C) continue;
                dpz[v][i+j+1] = max(dpz[v][i+j+1], dpn[j] + dpz[c][i] - 1);
            }
        }
        tsz += sz[c];
        tsz = min(tsz, C);
    }
}

vector <int> ord;

void find_tree(int v, int p){
    sz[v] = 1;
    ord.push_back(v);
    for(auto c : gg[v]){
        if(c == p) continue;
        graf[v].push_back(c);
        find_tree(c, v);
        sz[v] += sz[c];
    }
}

int qa[N+5], qb[N+5], soln[N+5];
vector <pair <int, int>> vec[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        gg[a].push_back(b);
        gg[b].push_back(a);
    }
    find_tree(1, 0);
    reverse(ord.begin(), ord.end());
    int qrs;
    cin >> qrs;
    solveBig(1);
    for(int i=1; i<=qrs; i++){
        cin >> qa[i] >> qb[i];
        if(qb[i] <= K){
            vec[qb[i]].push_back({qa[i], i});
        }
        else{
            ll res = 0;
            for(int j=0; j<=min(sz[qa[i]], C); j++) res = max(res, dpz[qa[i]][j] - 1LL*j*qb[i]);
            soln[i] = res;
        }
    }
    for(int i=0; i<=K; i++){
        for(auto v : ord){
            dp[v] = 0;
            for(auto c : graf[v]){
                dp[v] += max(1, dp[c] - i);
            }
        }
        for(auto c : vec[i]) soln[c.second] = dp[c.first];
    }
    for(int i=1; i<=qrs; i++) cout << soln[i] << "\n";
    return 0;
}