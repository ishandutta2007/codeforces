#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, m, a[maxN];
int x, y, z, k;
 
vector<int> vc[maxN];
set<ii> edge;
set<int> component;
stack<int> s;
bool used[maxN];
int god[maxN];
vector<int> v1[maxN];
 
void dfs_tree(int node, int par){
    used[node] = 1;
    component.insert(node);
    map<int, int> counter;
    for(int child : vc[node]){
        counter[child]++;
        if(counter[child] > 1){
            edge.insert(ii(child, node));
            continue;
        }
        if(edge.find(ii(child, node)) == edge.end()){
            edge.insert(ii(node, child));
            if(!used[child]){
                dfs_tree(child, node);
            }
        }
    }
    s.push(node);
}
 
void dfs_strong(int node){
    used[node] = 1;
    component.insert(node);
    for(int child : vc[node]){
        if(!used[child]){
            dfs_strong(child);
        }
    }
}

int Euler[maxN * 2];
int h[maxN];
int cnt = 0;
int in[maxN];
int sparse[maxN * 2][20];
int lg[maxN * 2];

int st[maxN];
int en[maxN];
int dumb[maxN];

void dfs_euler(int node, int par){
    Euler[++cnt] = node;
    in[node] = cnt;
    h[node] = h[par] + 1;
    for(int child : vc[node]){
        if(child != par){
            dfs_euler(child, node);
            Euler[++cnt] = node;
        }
    }
    return;
}

int lca(int n1, int n2){
    n1 = in[n1]; n2 = in[n2];
    if(n1 > n2) swap(n1, n2); ++n2;
    int dis = lg[n2 - n1];
    int n3 = sparse[n1][dis];
    int n4 = sparse[n2 - (1ll << dis)][dis];
    return ((h[n3] < h[n4]) ? n3 : n4);
}

bool killed = 0;
ii dfs_end(int node, int par){
    int stt = 0; int enn = 0;
    stt += st[node];   enn += en[node];
    stt -= dumb[node]; enn -= dumb[node];
    for(int child : vc[node]){
        if(child == par) continue;
        ii pr = dfs_end(child, node);
        stt += pr.fi;
        enn += pr.se;
    }
    if(stt && enn) killed = 1;
    return ii(stt, enn);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o;
    cin >> n >> m >> o;
    s.push(n + 1);
    for1(i, 1, m){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    vector<int> v2[maxN];
    for1(i, 1, o){
        cin >> x >> y;
        v2[x].pb(y);
    }
    memset(used, 0, sizeof(used));
    for1(i, 1, n){
        if(!used[i]){
            component.clear();
            dfs_tree(i, i);
            vc[n + 1].pb(i);
        }
    }
    // s contain dfser
    for1(i, 1, n){
        vc[i].clear();
    }
    ++n;
    for(ii pr : edge){
        vc[pr.se].pb(pr.fi);
        // cout << pr.fi << " " << pr.se << endl;
    }
    // full directed graph now
    memset(used, 0, sizeof(used));
    cnt = 0;
    while(!s.empty()){
        int node = s.top(); s.pop();
        if(used[node]) continue;
        component.clear();
        dfs_strong(node);
        ++cnt;
        for(auto i : component){
            // cout << i << " ";
            god[i] = cnt;
        }
        // cout << endl;
    }
    for1(i, 1, n){
        for(auto child : v2[i]){
            if(god[i] != god[child])
            v1[god[i]].pb(god[child]);
        }
        v2[i].clear();
        swap(v2[i], vc[i]);
    }
    for1(i, 1, n){
        // cout << i << "     ";
        for(auto child : v2[i]){
            // cout << child << " ";
            if(god[i] != god[child]){
                vc[god[i]].pb(god[child]);
                vc[god[child]].pb(god[i]);
                
                // cout << god[i] << " " << god[child] << endl;
            }
        }
        // cout << endl;
    }
    n = cnt;
    // directed graph, n node, query in v1, edge in vc, ezpz
    cnt = 0;
    h[n] = -1;
    dfs_euler(n, n);
    for1(i, 1, cnt){
        // cout << Euler[i] << " ";
        sparse[i][0] = Euler[i];
    }
    for1(j, 0, 25){
        for1(i, 1, cnt - (1ll << (j + 1)) + 1){
            int n1 = sparse[i][j];
            int n2 = sparse[i + (1ll << j)][j];
            if(h[n1] < h[n2]) sparse[i][j + 1] = n1;
            else              sparse[i][j + 1] = n2;
        }
    }
    lg[0] = -1;
    for1(i, 1, cnt){
        lg[i] = lg[i / 2] + 1;
    }
    memset(st, 0, sizeof(st));
    memset(en, 0, sizeof(en));
    memset(dumb, 0, sizeof(dumb));
    
    for1(i, 1, n){
        for(int child : v1[i]){
            st[i]++;
            en[child]++;
            dumb[lca(i, child)]++;
        }
    }
    if(dumb[n]) killed = 1;
    dfs_end(n, n);
    if(killed) cout << "No\n";
    else cout << "Yes\n";
}