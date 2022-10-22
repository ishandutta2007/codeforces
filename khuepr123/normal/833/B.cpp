#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const int mod = 1e9 + 7;
#define reupdate(node) tree[node].mx = max(tree[node * 2].mx + tree[node * 2].lazy, tree[node * 2 + 1].mx + tree[node * 2 + 1].lazy);

int dp[maxN];
int store[maxN];
int previous[maxN];
int n;

struct newtree{
    int mx;
    int lazy;
};

struct newtree tree[maxN * 4];
int a[maxN];

map<int, int> mp;
int looper;

int coef;
int maxRange;
int l[maxN * 4];
int r[maxN * 4];


void update(int node, int left, int right, int val){
    // cout << node << " " << left << " " << right << endl;
    if(l[node] == left && r[node] == right){
        tree[node].lazy += val;
        return;
    }
    if(r[node * 2] < left){
        update(node * 2 + 1, left, right, val);
        reupdate(node);
        return;
    }
    if(l[node * 2 + 1] > right){
        update(node * 2, left, right, val);
        reupdate(node);
        return;
    }
    update(node * 2, left, r[node * 2], val);
    update(node * 2 + 1, l[node * 2 + 1], right, val);
    reupdate(node);
}

int query(int node, int left, int right){
    if(l[node] == left && r[node] == right) return tree[node].mx + tree[node].lazy;
    if(r[node * 2] < left){
        return query(node * 2 + 1, left, right) + tree[node].lazy;
    }
    if(l[node * 2 + 1] > right){
        return query(node * 2, left, right) + tree[node].lazy;
    }
    return max(query(node * 2, left, r[node * 2]), query(node * 2 + 1, l[node * 2 + 1], right)) + tree[node].lazy;
}

void CreateSegTree(){
    coef = log2(n - 1) + 1;
    maxRange = 1 << coef;
    for(int i = 1; i < maxRange * 2; i++){
        tree[i].lazy = 0;
        tree[i].mx = 0;
        l[i] = i - maxRange + 1;
        r[i] = i - maxRange + 1;
    }
    for(int i = maxRange; i < maxRange + n; i++){
        tree[i].mx = store[i - maxRange + 1];
    }
    for(int i = maxRange - 1; i > 0; i--){
        tree[i].mx = max(tree[i * 2].mx, tree[i * 2 + 1].mx);
        l[i] = l[i * 2];
        r[i] = r[i * 2 + 1];
    }
}

signed main(){
    cin >> n >> looper;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()) previous[i] = 0;
        else previous[i] = mp[a[i]];
        mp[a[i]] = i;
        
    }
    store[0] = 0;
    for(int i = 1; i <= n; i++){
        store[i] = store[i - 1];
        if(previous[i] == 0) store[i]++;
    }
    looper--;
    while(looper--){
        CreateSegTree();
        dp[1] = store[1];
        //cout << dp[1] << " ";
        for(int i = 2; i <= n; i++){
            // for(int j = previous[i]; j < i; j++) store[j]++;
            // int mn = 0;
            // for(int j = 1; j <= i; j++) mn = max(mn, store[j]);
            // dp[i] = mn;
            update(1, max(previous[i], 1), i - 1, 1);
            dp[i] = query(1, 1, i);
            
        }
        for(int i = 1; i <= n; i++){
            store[i] = dp[i];
        }
    }
    cout << store[n];
}