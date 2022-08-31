#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int mod1 = 1e9 + 9, mod2 = 1000000033, B1 = 31, B2 = 37;
const int N = 3e5 +10;
#define ll long long
char str[N];
unordered_set<ll > st[N];
vector<int> con[N];
int cnt = 0, dif[N], ind[N], tree[N], c[N];
void dfs(int s, int p, int x, int y){
    int k = str[s - 1] - 'a' + 1;
    int x1 = (x * 1ll * B1 + k) % mod1, y1 = (y * 1ll * B2 + k) % mod2;
    ll hash = (x1 *1ll * mod2 + y1);
    vector<int> children;
    tree[s] = 1;
    int bigc = 0;
    for(int v: con[s]){
        if(v != p){
            children.push_back(v);
            dfs(v, s, x1, y1);
            tree[s] += tree[v];
            if(tree[v] > tree[bigc]) bigc = v;
        }
    }
    if(!bigc){
        dif[s] = 1;
        ind[s] = ++cnt;
        st[ind[s]] = {hash};
        return;
    }
    ind[s] = ind[bigc]; st[ind[s]].insert(hash);
    for(int c: children){
        if(c == bigc) continue;
        for(ll P: st[ind[c]]){
            st[ind[s]].insert(P);
        }
    }
    dif[s] = st[ind[s]].size();
}
int main(){
    int n, u, v; sd(n);
    for(int i = 1; i <= n; i++) sd(c[i]);
    scanf("%s", str);
    for(int i = 0; i < n-1; i++){
        sd(u), sd(v);
        con[u].push_back(v);
        con[v].push_back(u);
    }
    dfs(1, 0, 0, 0);
    int mx = 0; cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dif[i] + c[i] > mx){
            mx = dif[i] + c[i], cnt = 1;
        }
        else if(dif[i] + c[i] == mx) cnt ++;
    }
    printf("%d\n%d\n", mx, cnt);
}