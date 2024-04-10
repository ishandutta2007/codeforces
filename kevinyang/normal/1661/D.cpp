#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
    int size;
    vector<int>arr;
    vector<int>val;//lazy addition
    vector<int>val2;//lazy arithmetic sequence
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        arr.assign(8*size,0LL);
        val.assign(8*size,0LL);
        val2.assign(8*size,0LL);
    }
    void pushdown(int x, int len){
        if(val[x]==0&&val2[x]==0)return;
        int v1 = val[x]; int v2 = val2[x];
        val[x] = 0; val2[x] = 0;
        if(v1!=0){
            val[2*x+1]+=v1; val[2*x+2]+=v1; arr[x]+=v1*len; 
        }
        if(v2!=0){
            arr[x]+=v2*len*(len-1)/2;
            val[2*x+2]+=v2*len/2;
            val2[2*x+1]+=v2; val2[2*x+2]+=v2;
        }
    }
    void set(int l, int r, int v, int d, int x, int lx, int rx){//assign
        if(lx>=r||l>=rx)return;
        if(lx>=l&&rx<=r){
            val[x] += v+d*(lx-l);
            val2[x] += d;
            pushdown(x,rx-lx);
            return;
        }
        int m = (lx+rx)/2;
        pushdown(x,rx-lx);
        pushdown(2*x+1,m-lx);
        pushdown(2*x+2,rx-m);
        set(l,r,v,d,2*x+1,lx,m);
        set(l,r,v,d,2*x+2,m,rx);
        arr[x] = arr[2*x+1]+arr[2*x+2];
    }
    void set(int l, int r, int v, int d){
        set(l,r,v,d,0,0,size);
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
    int n,k;
    cin >> n >> k;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    SegTree segtree;
    segtree.init(2*n+5);
    int ans = 0;
    for(int i = n; i>=1; i--){
        int v = arr[i]-segtree.query(i,i+1);
        if(v<=0)continue;
        int val = min(i,k);
        int rq = (v+val-1)/val;
        ans+=rq;
        segtree.set(max(1LL,i-k+1),max(1LL,i-k+1)+k,rq,rq);
    }
    cout << ans << "\n";
    return 0;
}