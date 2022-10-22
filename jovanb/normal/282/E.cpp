#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll pre[100005];
ll niz[100005];

struct segment{
    int val;
    int l;
    int r;
} trie[5000005];

int cnt = 0;

void trieadd(ll x, int val){
    int node = 0;
    for(int i=39; i>=0; i--){
        if(x & (1LL<<i)){
            if(!trie[node].r) trie[node].r = ++cnt;
            node = trie[node].r;
        }
        else{
            if(!trie[node].l) trie[node].l = ++cnt;
            node = trie[node].l;
        }
        trie[node].val += val;
    }
}

ll query(ll x){
    int node = 0;
    ll res = 0;
    for(int i=39; i>=0; i--){
        if(x & (1LL<<i)){
            if(!trie[trie[node].l].val) node = trie[node].r;
            else{
                res += (1LL<<i);
                node = trie[node].l;
            }
        }
        else{
            if(!trie[trie[node].r].val) node = trie[node].l;
            else{
                res += (1LL<<i);
                node = trie[node].r;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    trieadd(0, 1);
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        pre[i] = pre[i-1] ^ niz[i];
        trieadd(pre[i], 1);
    }
    ll tren = 0;
    ll res = query(0);
    for(int i=n; i>=1; i--){
        tren ^= niz[i];
        trieadd(pre[i], -1);
        res = max(res, query(tren));
    }
    cout << res;
    return 0;
}