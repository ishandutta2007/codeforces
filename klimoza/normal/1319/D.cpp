#include <bits/stdc++.h>
#include <queue>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define int long long

typedef long long ll;

using namespace std;

void solve();
signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cout.precision(15); cout << fixed;
    solve();
    return 0;
}

const int N = 2e5 + 7;

vector<int> rg[N], g[N];

int d[N];

void bfs(int s){
    queue<int> f;
    fill(d, d + N, 2e9);
    d[s] = 0;
    f.push(s);
    while(!f.empty()){
        int v = f.front();
        f.pop();
        //cout << v << " kek\n";
        for(int i = 0; i < rg[v].size(); i++){
            int u = rg[v][i];
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1;
                f.push(u);
            }
        }
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    int k; cin >> k;
    vector<int> p(k);
    for(int i = 0; i < k; i++){
        cin >> p[i]; p[i]--;
    }
    bfs(p.back());
    //for(int i = 0; i < n; i++) cout << d[i] << " " << i << endl;
    int m1 = 0, m2 = 0;
    for(int i = 0; i < k - 1; i++){
        int v = p[i], u = p[i + 1];
        if(d[v] != d[u] + 1){
            m1++; m2++;
        } else{
            for(int j = 0; j < g[v].size(); j++){
                if(g[v][j] == u) continue;
                if(d[g[v][j]] + 1 == d[v]){
                    m2++;
                    break;
                }
            }
        }
    }
    cout << m1 << " " << m2 << endl;
}