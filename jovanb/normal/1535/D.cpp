#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int K = 18;

pair <int, int> corr[(1<<K)];

struct segment{
    int cnt, mn, lazy;
} seg[4*(1<<K)];

void init(int node, int l, int r){
    seg[node].cnt = r-l+1;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

void mrg(int node){
    seg[node].mn = min(seg[node*2].mn, seg[node*2+1].mn);
    seg[node].cnt = 0;
    seg[node].cnt += seg[node*2].cnt * (seg[node*2].mn == seg[node].mn);
    seg[node].cnt += seg[node*2+1].cnt * (seg[node*2+1].mn == seg[node].mn);
}

void propagate(int node, int l, int r){
    seg[node].mn += seg[node].lazy;
    if(l == r){
        seg[node].lazy = 0;
        return;
    }
    seg[node*2].lazy += seg[node].lazy;
    seg[node*2+1].lazy += seg[node].lazy;
    seg[node].lazy = 0;
}

void upd(int node, int l, int r, int tl, int tr, int val){
    propagate(node, l, r);
    if(l > tr || tl > r) return;
    if(tl <= l && r <= tr){
        seg[node].lazy += val;
        propagate(node, l, r);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, val);
    upd(node*2+1, mid+1, r, tl, tr, val);
    mrg(node);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> k;
    int tr = 0;
    int n = (1<<k);
    for(int sz=1; sz<=k; sz++){
        for(int i=1; i<=(1<<(k-sz)); i++){
            tr++;
            if(corr[tr-1].second == n) corr[tr] = {1, (1<<sz)};
            else corr[tr] = {corr[tr-1].second + 1, corr[tr-1].second + (1<<sz)};
        }
    }
    string s;
    cin >> s;
    init(1, 1, n);
    for(int i=1; i<=(1<<k); i++){
        int mid = (corr[i].first + corr[i].second)/2;
        if(s[i-1] == '1'){
            upd(1, 1, n, corr[i].first, mid, 1);
        }
        else if(s[i-1] == '0'){
            upd(1, 1, n, mid+1, corr[i].second, 1);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int i;
        char c;
        cin >> i >> c;
        int mid = (corr[i].first + corr[i].second)/2;
        if(s[i-1] == '1'){
            upd(1, 1, n, corr[i].first, mid, -1);
        }
        else if(s[i-1] == '0'){
            upd(1, 1, n, mid+1, corr[i].second, -1);
        }
        s[i-1] = c;
        if(s[i-1] == '1'){
            upd(1, 1, n, corr[i].first, mid, 1);
        }
        else if(s[i-1] == '0'){
            upd(1, 1, n, mid+1, corr[i].second, 1);
        }
        cout << seg[1].cnt << "\n";
    }
    return 0;
}