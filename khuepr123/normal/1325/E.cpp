/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int mod = 1e9 + 7;
const int maxN = 100005;
int n, a[maxN];
int x, y, z, k;

vector<int> fac[maxN * 10];
int num[maxN * 10];
queue<ii> q;

vector<int> vc[maxN];
int ans = mod;

inline void conn(int i, int j){
    vc[i].pb(j);
    vc[j].pb(i);
}

int d[maxN];

void bfs(queue<ii> &qb, int bns){
    while(!qb.empty()){
        ii pr = qb.front(); qb.pop();
        int par = pr.se;
        int node = pr.fi;
        for(int cc : vc[node]){
            if(cc != par){
                if(d[cc] != -1){
                    ans = min(ans, d[node] + d[cc] + bns);
                    // cout << d[node] << " " << d[cc] << endl;
                }
                else{
                    d[cc] = d[node] + 1;
                    qb.push(ii(cc, node));
                }
            }
        }
    }
}

inline void clean(){
    while(!q.empty()) q.pop();
    memset(d, -1, sizeof(d));
}

void prt(int fvl){
    cout << fvl << endl; exit(0);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    for1(i, 0, maxN * 10 - 1) num[i] = i;
    x = 0;
    for1(i, 2, maxN * 10 - 1){
        if(num[i] > 1){
            ++x;
            for(int j = i; j < maxN * 10; j += i){
                bool fl = 1;
                num[j] /= i;
                while(num[j] % i == 0){
                    num[j] /= i;
                    fl = !fl;
                }
                if(fl) fac[j].pb(x);
            }
        }
    }
    clean();
    cin >> n;
    bool whythefuck = 0;
    set<int> fuckingnum;
    for1(i, 1, n){
        cin >> x;
        y = 0;
        for(int cc : fac[x]) y = y * maxN + cc;
        if(fuckingnum.find(y) != fuckingnum.end()) whythefuck = 1;
        fuckingnum.insert(y);
        if(fac[x].size() == 0){
            // if(n == 78500) cout << x << endl;
            prt(1);
        }
        if(fac[x].size() == 1){
            x = fac[x][0];
            q.push(ii(x, 0));
            d[x] = 0;
        }
        else conn(fac[x][0], fac[x][1]);
    }
    if(whythefuck) prt(2);
    bfs(q, 3);
    for1(node, 1, 200){
        clean();
        q.push(ii(node, 0));
        d[node] = 0;
        bfs(q, 1);
    }
    if(ans > mod / 2) prt(-1);
    prt(ans);
}