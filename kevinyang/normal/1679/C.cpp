#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
    int size;
    vector<int>arr;
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        arr.assign(2*size,0LL);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            arr[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        arr[x] = min(arr[2*x+1],arr[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int query(int l,int r, int x, int lx, int rx){
        if(lx>=r||l>=rx)return (int)1e18;
        if(lx>=l&&rx<=r)return arr[x];
        int m = (lx+rx)/2;
        int s1 = query(l,r,2*x+1,lx,m);
        int s2 = query(l,r,2*x+2,m,rx);
        return min(s1,s2);
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
    SegTree segtree2;
    segtree2.init(n+5);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int x,y;
            cin >> x >> y;
            int v = segtree.query(x,x+1);
            segtree.set(x,v+1);
            v = segtree2.query(y,y+1);
            segtree2.set(y,v+1);
        }
        else if(t==2){
            int x,y;
            cin >> x >> y;
            int v = segtree.query(x,x+1);
            segtree.set(x,v-1);
            v = segtree2.query(y,y+1);
            segtree2.set(y,v-1);
        }
        else{
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if(segtree.query(a,c+1)>=1||segtree2.query(b,d+1)>=1){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
    return 0;
}