#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 1000000000;
const int MAXC = 20000000;

int idxx = 1;

struct Segment{
    int node, l, r, mn, mx, lazy;
} seg[MAXC];

void create_node(int par, int l, int r, int t){
    int node = ++idxx;
    seg[node].lazy = 0;
    seg[node].mn = l;
    seg[node].mx = r;
    if(t == 0) seg[par].l = node;
    else seg[par].r = node;
}

void propagate(int node, int l, int r){
    seg[node].mn += seg[node].lazy;
    seg[node].mx += seg[node].lazy;
    if(l == r){
        seg[node].lazy = 0;
        return;
    }
    int mid = (l+r)/2;
    if(!seg[node].l) create_node(node, l, mid, 0);
    if(!seg[node].r) create_node(node, mid + 1, r, 1);
    seg[seg[node].l].lazy += seg[node].lazy;
    seg[seg[node].r].lazy += seg[node].lazy;
    seg[node].lazy = 0;
}

int query(int node, int l, int r, int x){
    propagate(node, l, r);
    if(l == r) return seg[node].mx;
    int mid = (l+r)/2;
    if(x <= mid) return query(seg[node].l, l, mid, x);
    else return query(seg[node].r, mid+1, r, x);
}

void upd_manji(int node, int l, int r, int x){
    propagate(node, l, r);
    if(seg[node].mx < x){
        seg[node].lazy++;
        propagate(node, l, r);
        return;
    }
    if(seg[node].mn >= x) return;
    int mid = (l+r)/2;
    upd_manji(seg[node].l, l, mid, x);
    upd_manji(seg[node].r, mid+1, r, x);
    seg[node].mn = seg[seg[node].l].mn;
    seg[node].mx = seg[seg[node].r].mx;
}

void upd_veci(int node, int l, int r, int x){
    propagate(node, l, r);
    if(seg[node].mn > x){
        seg[node].lazy--;
        propagate(node, l, r);
        return;
    }
    if(seg[node].mx <= x) return;
    int mid = (l+r)/2;
    upd_veci(seg[node].l, l, mid, x);
    upd_veci(seg[node].r, mid+1, r, x);
    seg[node].mn = seg[seg[node].l].mn;
    seg[node].mx = seg[seg[node].r].mx;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    seg[1].mn = 1;
    seg[1].mx = MAX;
    int lastans = 0;
    while(n--){
        int t, k;
        cin >> t >> k;
        upd_manji(1, 1, MAX, t);
        upd_veci(1, 1, MAX, t);
        while(k--){
            int x;
            cin >> x;
            x = (x + lastans)%(MAX + 1);
            cout << (lastans = query(1, 1, MAX, x)) << "\n";
        }
    }
    return 0;
}