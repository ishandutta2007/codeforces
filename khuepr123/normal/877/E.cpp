#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxN = 2e5 + 5;

int n, x, y;
vector<int> vc[maxN];
int light[maxN];
string s;

struct makeTree{
    int sum;
    bool pw;
};

int euler[maxN * 2];
makeTree tree[maxN * 8];
int l[maxN * 8];
int r[maxN * 8];
int m;

void dfs(int node){
    m++;
    euler[m] = node;
    for(int i = 0; i < vc[node].size(); i++){
        int child = vc[node][i];
        dfs(child);
    }
    m++;
    euler[m] = node;
}

void redate(int node){
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    if(tree[node].pw) tree[node].sum = r[node] - l[node] + 1 - tree[node].sum;
}

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right){
        tree[node].sum = light[euler[left]];
        tree[node].pw  = 0;
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2    , left   , mid);
    build(node * 2 + 1, mid + 1, right);
    redate(node);
}

void turn(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        tree[node].pw = !tree[node].pw;
        tree[node].sum = right - left + 1 - tree[node].sum;
        return;
    }
    if(r[node * 2] < left) turn(node * 2 + 1, left, right);
    else if(r[node * 2] >= right) turn(node * 2, left, right);
    else{
        turn(node * 2    , left           , r[node * 2]);
        turn(node * 2 + 1, l[node * 2 + 1], right      );
    }
    redate(node);
}

int ans;
int temp;
int ll[maxN * 2];
int rr[maxN * 2];

void get(int node, int left, int right, bool ind){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        temp = tree[node].sum;
        if(ind) temp = r[node] - l[node] + 1 - temp;
        ans = ans + temp;
        return;
    }
    ind = (ind xor tree[node].pw);
    if(r[node * 2] < left) get(node * 2 + 1, left, right, ind);
    else if(r[node * 2] >= right) get(node * 2, left, right, ind);
    else{
        get(node * 2    , left           , r[node * 2], ind);
        get(node * 2 + 1, l[node * 2 + 1], right      , ind);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    m = 0;
    for(int i = 2; i <= n; i++){
        cin >> x;
        vc[x].pb(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> light[i];
    }
    int o; cin >> o;
    dfs(1);
    for(int i = 1; i <= n; i++){
        ll[i] = n * 2;
        rr[i] = 1;
    }
    for(int i = 1; i <= n * 2; i++){
        ll[euler[i]] = min(ll[euler[i]], i);
        rr[euler[i]] = max(rr[euler[i]], i);
        
    }
    
    build(1, 1, m);
    
    while(o--){
        cin >> s >> x;
        if(s == "pow") turn(1, ll[x], rr[x]);
        else{
            ans = 0;
            get(1, ll[x], rr[x], 0);
            cout << ans / 2 << endl;
        }
    }
}