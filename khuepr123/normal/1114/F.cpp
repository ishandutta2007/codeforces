#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxN = 4e5 + 5;
const int mod = 1e9 + 7;

int n;

int lazy[maxN * 4];
int tree[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];

int fac[maxN];
int prm[63];
int a[maxN];
int ans;
int tot[64];
int x, y, z;
string s;

int pw(int num, int coef){
    if(coef == 0) return 1;
    int hh = pw(num, coef / 2);
    hh = (hh * hh) % mod;
    if(coef & 1) hh = (hh * num) % mod;
    return hh;
}

int calc(int num){
    int res = 1;
    for(int i = 0; i < 62; i++){
        if(num & (1ll << i)){
            res = (res * tot[i]) % mod;
        }
    }
    return res;
}

void redate(int node){
    tree[node] = (lazy[node * 2] | lazy[node * 2 + 1]) 
    | (tree[node * 2] | tree[node * 2 + 1]);
}

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    lazy[node] = 0;
    if(left == right){
        tree[node] = fac[a[left]];
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
    redate(node);
}

void update(int node, int left, int right, int val){
    tree[node] = tree[node] | val;
    if(left == l[node] && right == r[node]){
        lazy[node] = lazy[node] | val;
        return;
    }
    else if(left > r[node * 2]) update(node * 2 + 1, left, right, val);
    else if(right <= r[node * 2]) update(node * 2, left, right, val);
    else{
        update(node * 2 + 1, l[node * 2 + 1], right, val);
        update(node * 2, left, r[node * 2], val);
    }
}

void take(int node, int left, int right){
    ans = ans | lazy[node];
    if(left == l[node] && right == r[node]){
        ans = ans | tree[node];
        return;
    }
    else if(left > r[node * 2]) take(node * 2 + 1, left, right);
    else if(right <= r[node * 2]) take(node * 2, left, right);
    else{
        take(node * 2 + 1, l[node * 2 + 1], right);
        take(node * 2, left, r[node * 2]);
    }
}

int ftree[maxN];
int stree[maxN];

void add(int *whattree, int pos, int num){
    while(pos <= n){
        whattree[pos] = (whattree[pos] * num) % mod;
        pos = pos + (pos & -pos);
    }
}

void admire(int left, int right, int num){
    add(ftree, left, num);
    add(ftree, right + 1, pw(num, mod - 2));
    add(stree, left, pw(num, (left - 1)));
    add(stree, right + 1, pw(num, mod - 1 - right));
}

int sum(int* whattree, int pos){
    int anse = 1;
    while(pos){
        anse = (anse * whattree[pos]) % mod;
        pos = pos - (pos & -pos);
    }
    return anse;
}

int presum(int ind){
    return (pw(sum(ftree, ind), ind) * pw(sum(stree, ind), mod - 2)) % mod;
}

int area(int left, int right){
    return (presum(right) * pw(presum(left - 1), mod - 2)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int o; cin >> o;
    for(int i = 0; i <= 300; i++){
        fac[i] = 0;
    }
    int cnt = 0;
    for(int i = 2; i <= 300; i++){
        if(fac[i] == 0){
            for(int j = i; j <= 300; j+=i){
                fac[j] |= (1ll << cnt);
            }
            tot[cnt] = ((i - 1) * pw(i, mod - 2)) % mod;
            cnt++;
        }
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        ftree[i] = 1;
        stree[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, i, i, fac[a[i]]);
        admire(i, i, a[i]);
    }
    
    string s;
    while(o--){
        cin >> s >> x >> y;
        if(s[0] == 'M'){
            cin >> z;
            admire(x, y, z);
            update(1, x, y, fac[z]);
        }
        else{
            ans = 0;
            take(1, x, y);
            ans = calc(ans);
            ans = (ans * area(x, y)) % mod;
            ans = (ans + mod) % mod;
            cout << ans << endl;
        }
    }
    
}