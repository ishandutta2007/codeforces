#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
    vector<int>arr;
    vector<int>val;
    int size;
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        arr.resize(size*2);
        val.resize(size*2); 
    }
    void pushdown(int x, int len){
        if(val[x]==0)return;
        arr[x]+=len*val[x];
        if(len>1){
            val[2*x+1]+=val[x]; val[2*x+2]+=val[x];
        }
        val[x] = 0;
    }
    void set(int l, int r, int v, int x, int lx, int rx){
        if(lx>=r||l>=rx){
            pushdown(x,rx-lx);
            return;
        }
        if(lx>=l&&rx<=r){
            val[x]+=v;
            pushdown(x,rx-lx);
            return;
        }
        pushdown(x,rx-lx);
        int m = (lx+rx)/2;
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
        arr[x] = arr[2*x+1] + arr[2*x+2];
    }
    void set(int l, int r, int v){
        set(l,r,v,0,0,size);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx>=r||l>=rx){
            pushdown(x,rx-lx);
            return 0;
        }
        if(lx>=l&&rx<=r){
            pushdown(x,rx-lx);
            return arr[x];
        }
        int m = (lx+rx)/2;
        pushdown(x,rx-lx);
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        SegTree segtree;
        segtree.init(n+5);
        for(int i = 1; i<=n; i++){
            segtree.set(i,i+1,arr[i]);
        }
        int ans = 0;
        for(int i = 1; i<n; i++){
            int v = abs(segtree.query(i,i+1)-segtree.query(i+1,i+2));
            if(segtree.query(i,i+1)<segtree.query(i+1,i+2)){
                segtree.set(i+1,n+1,-v);
                ans+=v;
            }
            else{
                segtree.set(1,i+1,-v);
                ans+=v;
            }
        }
        ans+=abs(segtree.query(1,2));
        cout << ans << "\n";
    }
    return 0;
}