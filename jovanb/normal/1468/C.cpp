#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

const int MAX = 500000;

struct segment{
    int lft, res;
} seg[8*MAX];

int val[MAX+5];

void mrg(int node){
    if(val[seg[node*2].lft]) seg[node].lft = seg[node*2].lft;
    else seg[node].lft = seg[node*2+1].lft;
    if(val[seg[node*2].res] >= val[seg[node*2+1].res]) seg[node].res = seg[node*2].res;
    else seg[node].res = seg[node*2+1].res;
}

void upd(int node, int l, int r, int x){
    if(l == r){
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) upd(node*2, l, mid, x);
    else upd(node*2+1, mid+1, r, x);
    mrg(node);
}

void init(int node, int l, int r){
    seg[node].lft = seg[node].res = l;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int q;
    cin >> q;
    int cnt = 0;
    init(1, 1, MAX);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            cnt++;
            int x;
            cin >> x;
            val[cnt] = x;
            upd(1, 1, MAX, cnt);
        }
        else if(t == 2){
            cout << seg[1].lft << " ";
            val[seg[1].lft] = 0;
            upd(1, 1, MAX, seg[1].lft);
        }
        else{
            cout << seg[1].res << " ";
            val[seg[1].res] = 0;
            upd(1, 1, MAX, seg[1].res);
        }
    }
    return 0;
}