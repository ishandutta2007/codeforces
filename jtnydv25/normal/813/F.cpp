#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define pb push_back
const int N = 1e5 + 10, SQN = 400;

int par[N], invert[N], sz[N], par2[N], invert2[N], sz2[N];
void pre(){ for(int i = 0; i < N; i++) par[i] = i; memset(invert, 0, sizeof invert);}
pii get(int s){
    int color = 0;
    while(par[s] != s){
        color ^= invert[s];
        s = par[s];
    }
    return {s, color ^ invert[s]};
}
vector<pii> roll_par, roll_sz, roll_invert;
bool problem = 0;
void merge(bool roll, int u, int v){
    if(problem || u == v) return;
    pii P = get(u), Q = get(v);
    u = P.F, v = Q.F;
    int colu = P.S, colv = Q.S;
    if(u == v && colu == colv){
        problem = 1;
        return;
    }
    if(u != v){
        if(sz[u] > sz[v]){
            swap(u, v), swap(colu, colv); 
        }
        // attach u to v
        if(sz[u] == sz[v]){
            if(roll) roll_sz.pb({v, sz[v]});
            sz[v]++;
        }
        if(roll)roll_par.pb({u, par[u]});
        par[u] = v;
        if(colu == colv){
            if(roll)roll_invert.pb({u, invert[u]});
            invert[u] = 1;
        }
    }
}
void roll_back(){
    reverse(roll_sz.begin(), roll_sz.end());
    reverse(roll_invert.begin(), roll_invert.end());
    reverse(roll_par.begin(), roll_par.end());
    for(auto it : roll_sz) sz[it.F] = it.S;
    for(auto it : roll_invert) invert[it.F] = it.S;
    for(auto it : roll_par) par[it.F] = it.S;
    roll_par.clear();
    roll_invert.clear();
    roll_sz.clear(); 
}
int n, q, x, y;
int flag[N], ind[N];  // flag = 1 => add, else delete
map<pii, int> lst;
pii P[N];
set<pii> edges;
int main(){
    sd(n); sd(q);
    for(int i = 1; i <= q; i++){
        sd(P[i].F); sd(P[i].S);
        if(P[i].F > P[i].S) P[i] = {P[i].S, P[i].F};
        if(!lst[P[i]]){
            flag[i] = 1;
            lst[P[i]] = i;
        }
        else{
            ind[i] = lst[P[i]];
            ind[lst[P[i]]] = i;
            lst[P[i]] = 0;
        }
    }
    for(int i = 1; i <= q; i++) if(flag[i] && !ind[i]) ind[i] = q + 1;
    for(int i = 1; i <= q; i += SQN){
        int s = i, e = min(q, i + SQN - 1);
        for(int j = s; j <= e; j++){
            if(!flag[j]) edges.erase(P[j]);
        }
        problem = 0;
        pre();
        for(auto it : edges){
            merge(0, it.F, it.S);
        }
        // save state
        int problem2 = problem;
        for(int j = s; j <= e; j++){
            problem = problem2;
            for(int k = s; k <= e; k++){
                if(k <= j && flag[k] && ind[k] > j) merge(1, P[k].F, P[k].S);
                if(k > j && !flag[k] && ind[k] <= j) merge(1, P[k].F, P[k].S);
            }
            if(problem) printf("NO\n");
            else printf("YES\n");
            if(flag[j]) edges.insert(P[j]);
            else edges.erase(P[j]);
            roll_back();
        }
    }
}