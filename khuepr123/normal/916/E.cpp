#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
const int maxN = 1e5 + 5;
const int mod = 1e9 + 7;
#define fore(i, gf1, gf2) for(int i = gf1; i <= gf2; i++)
int n;
vector<int> vc[maxN];
int cnt;
int order[maxN];
int in[maxN];
int out[maxN];
int a[maxN];
int h[maxN];
int par[maxN];
int x, y;
int root;
int ans = 0;
 
int euler[maxN * 2];
int cntler = 0;
void dfs(int node, int pr){
    in[node] = ++cnt;
    order[cnt] = node;
    par[node] = pr;
    h[node] = h[pr] + 1;
    euler[++cntler] = node;
    for(auto child : vc[node]){
        if(child == pr) continue;
        dfs(child, node);
        euler[++cntler] = node;
    }
    out[node] = cnt + 1;
}
 
int ftree[maxN];
int stree[maxN];
 
///////////////////////////////////////////
void add(int *tree, int pos, int num){
    while(pos <= n){
        tree[pos] += num;
        pos = pos + (pos & (-pos));
    }
}
void admire(int left, int right, int num){
    add(ftree, left, num);
    add(ftree, right + 1, -num);
    add(stree, left, num * (left - 1));
    add(stree, right + 1, -num * right);
}
int sum(int *tree, int pos){
    int ans = 0;
    while(pos){
        ans += tree[pos];
        pos = pos - (pos & (-pos));
    }
    return ans;
}
int prefix(int pos){
    return sum(ftree, pos) * pos - sum(stree, pos);
}
int area(int left, int right){
    return prefix(right) - prefix(left - 1);
}
////////////////////////////////////////////
 
int sparse[maxN * 2][20];
int lg[maxN * 2];
int minpos[maxN];
int maxpos[maxN];
 
int lcs(int n1, int n2){
    int left = min(minpos[n1], minpos[n2]);
    int right = max(maxpos[n1], maxpos[n2]) + 1ll;
    int lger = lg[right - left];
    int new1 = sparse[left][lger];
    int new2 = sparse[right - (1 << lger)][lger];
    if(h[new1] > h[new2]) return new2;
    else return new1;
}
 
int parup[maxN][20];
 
void pullup(int& node, int hei){
    int cur = 18;
    while(cur != -1){
        if(h[parup[node][cur]] > hei) node = parup[node][cur];
        --cur;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; int o; cin >> o;
    fore(i, 0, n + 2){
        ftree[i] = 0;
        stree[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    fore(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    cnt = 0;
    root = 1;
    par[1] = n + 1;
    par[n + 1] = n + 1;
    h[0] = mod;
    h[n + 1] = -1;
    dfs(1, n + 1);
    lg[0] = -1;
    for(int i = 1; i <= n; i++){
        admire(i, i, a[order[i]]);
        parup[i][0] = par[i];
        minpos[i] = mod;
        maxpos[i] = -mod;
    }
    fore(i, 1, n * 2){
        sparse[i][0] = euler[i];
        lg[i] = lg[i / 2] + 1;
        minpos[euler[i]] = min(minpos[euler[i]], i);
        maxpos[euler[i]] = max(maxpos[euler[i]], i);
    }
    parup[n + 1][0] = par[n + 1];
    for(int rg = 0; rg < 19; rg++){
        fore(i, 1, n * 2 + 1 - (1 << (rg + 1))){
            int n1 = sparse[i][rg];
            int n2 = sparse[i + (1 << rg)][rg];
            if(h[n1] > h[n2]) sparse[i][rg + 1] = n2;
            else              sparse[i][rg + 1] = n1;
        }
        fore(i, 1, n + 1){
            parup[i][rg + 1] = parup[parup[i][rg]][rg];
        }
    }
    while(o--){
        cin >> x >> y;
        if(x == 1){
            root = y;
        }
        else if(x == 3){
            int cope = root;
            pullup(cope, h[y]);
            // cout << cope << " " << y << endl;
            if(cope == y) cout << area(1, n) << endl;
            else if(par[cope] != y) cout << area(in[y], out[y] - 1) << endl;
            else cout << area(1, n) - area(in[cope], out[cope] - 1) << endl;
        }
        else{
            int n1, n2;
            cin >> n2 >> n1;
            swap(n1, y); // n1 n2 y
            int cope = root;
            int spec1 = lcs(n1, n2);
            int spec2 = lcs(n1, root);
            int spec3 = lcs(n2, root);
            // cout << spec1 << " ";
            // cout << spec2 << " ";
            // cout << spec3 << "\n";
            
            if(h[spec1] < h[spec2]) swap(spec1, spec2);
            if(h[spec2] < h[spec3]) swap(spec2, spec3);
            if(h[spec1] < h[spec2]) swap(spec1, spec2);
            n1 = spec1;
            // cout << cope << " " << n1 << endl;
            pullup(cope, h[n1]);
            if(cope == n1){
                admire(1, n, y);
            }
            else if(par[cope] != n1){
                admire(in[n1], out[n1] - 1, y);
            }
            else{
                admire(1, n, y);
                admire(in[cope], out[cope] - 1, -y);
            }
        }
        // for(int i = 1; i <= n; i++){
        //     cout << area(i, i) << " ";
        // }
        // cout << endl;
    }
}