#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

const int N = 1000;
const int MOD = 998244353;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

vector <int> graf[N+5];
vector <int> rgraf[N+5];

ll cnt[N+5];
ll ncnt[N+5];

bool check(){
    for(int i=1; i<=n; i++){
        if(cnt[i]) return 0;
    }
    return 1;
}

void psh(){
    for(int i=1; i<=n; i++){
        ncnt[i] = cnt[i];
    }
    for(int i=1; i<=n; i++){
        if(!cnt[i]) continue;
        for(auto c : graf[i]){
            ncnt[c]++;
        }
        ncnt[i]--;
    }
    for(int i=1; i<=n; i++) cnt[i] = ncnt[i];
}

int deg[N+5];

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        graf[i].clear();
        rgraf[i].clear();
        deg[i] = 0;
        cin >> cnt[i];
    }
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        deg[v]++;
        graf[u].push_back(v);
        rgraf[v].push_back(u);
    }
    if(check()){
        cout << 0 << "\n";
        return;
    }
    for(int i=1; i<=n+m; i++){
        psh();
        if(check()){
            cout << i << "\n";
            return;
        }
    }
    int t = n + m;
    queue <int> q;
    for(int i=1; i<=n; i++){
        cnt[i] %= MOD;
        if(!deg[i]){
            q.push(i);
        }
    }
    int last = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        last = cnt[v];
        for(auto c : graf[v]){
            deg[c]--;
            if(!deg[c]) q.push(c);
            cnt[c] = add(cnt[c], cnt[v]);
        }
    }
    cout << add(last, t) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
10 11
998244353 0 0 0 998244353 0 0 0 0 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 3
7 9
*/