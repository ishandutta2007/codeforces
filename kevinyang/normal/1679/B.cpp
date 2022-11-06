#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
    int size;
    vector<int>arr;
    vector<int>val;//lazy
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        arr.assign(4*size,0LL);
        val.assign(4*size,-1LL);
    }
    void pushdown(int x, int len){
        if(val[x]==-1)return;
        int v = val[x];
        arr[x] = v*len; val[x] = -1;
        val[2*x+1] = v; val[2*x+2] = v;
    }
    void set(int l, int r, int v, int x, int lx, int rx){
        if(lx>=r||l>=rx)return;
        if(lx>=l&&rx<=r){
            arr[x]=v*(rx-lx);
            val[x] = -1;
            if(rx-lx==1)return;
            val[2*x+1] = v;
            val[2*x+2] = v;
            return;
        }
        int m = (lx+rx)/2;
        pushdown(x,rx-lx);
        pushdown(2*x+1,m-lx);
        pushdown(2*x+2,rx-m);
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
        arr[x] = arr[2*x+1]+arr[2*x+2];
    }
    void set(int l, int r, int v){
        set(l,r,v,0,0,size);
    }
    int query(int l,int r, int x, int lx, int rx){
        if(lx>=r||l>=rx)return 0;
        if(lx>=l&&rx<=r){
            pushdown(x,rx-lx);
            return arr[x];
        }
        int m = (lx+rx)/2;
        pushdown(x,rx-lx);
        pushdown(2*x+1,m-lx);
        pushdown(2*x+2,rx-m);
        int s1 = query(l,r,2*x+1,lx,m);
        int s2 = query(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    int query(int l, int r){
        return query(l,r,0,0,size);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    SegTree segtree;
    segtree.init(n+5);
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        segtree.set(i,i+1,x);
    }
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int i,v;
            cin >> i >> v;
            segtree.set(i,i+1,v);
        }
        else{
            int x;
            cin >> x;
            segtree.set(1,n+1,x);
        }
        cout << segtree.query(1,n+1) << "\n";
    }
    return 0;
}