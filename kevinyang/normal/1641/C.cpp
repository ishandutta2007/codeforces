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
struct query{
    int t,l,r,x;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<query>queries(q+1);
    for(int i = 1; i<=q; i++){
        int t;
        cin >> t;
        if(t==0){
            int l,r,x;
            cin >> l >> r >> x;
            queries[i] = {t,l,r,x};
        }
        else{
            int x;
            cin >> x;
            queries[i] = {t,0,0,x};
        }
    }
    vector<int>low(q+1);
    vector<int>high(q+1,q+1);
    vector<int>mid(q+1);
    vector<int>bad(q+1);
    vector<int>ind(q+1);
    vector<int>tim(n+1,(int)1e9);
    if(true){
        SegTree segtree;
        segtree.init(n+5);
        for(int i = 1; i<=q; i++){
            if(queries[i].t==0&&queries[i].x==0){
                int l = queries[i].l; int r = queries[i].r;
                segtree.set(l,r+1,1);
            }
        }
        for(int i = 1; i<=q; i++){
            if(queries[i].t==0&&queries[i].x==1){
                int l = queries[i].l; int r = queries[i].r;
                int v = r-l+1-segtree.query(l,r+1);
                assert(v>=1);
                if(v!=1){
                    bad[i] = 1;
                }
                else{
                    int lo = l-1; int hi = r+1; int mi = (lo+hi)/2;
                    while(lo+1<hi){
                        if(segtree.query(l,mi+1)==mi-l+1){
                            lo = mi;
                        }
                        else{
                            hi = mi;
                        }
                        mi = (lo+hi)/2;
                    }
                    ind[i] = hi;
                }
            }
        }
    }
    /*
    for(int i = 1; i<=n; i++){
        cout << bad[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i<=q; i++){
        cout << ind[i] << " ";
    }
    cout << "\n";
    */
    for(int tt = 0; tt<20; tt++){
        for(int i = 1; i<=q; i++){
            mid[i] = (low[i]+high[i])/2;
        }
        vector<pair<int,int>>val;
        for(int i = 1; i<=q; i++){
            if(low[i]==high[i]-1||(queries[i].t==0&&queries[i].x==0)||bad[i]||queries[i].t==1){
                continue;
            }
            val.push_back({mid[i],i});
        }
        sort(val.begin(),val.end());
        SegTree segtree;
        segtree.init(n+5);
        int i = 0;
        for(pair<int,int>nxt: val){
            while(i<nxt.first){
                i++;
                if(queries[i].t==0&&queries[i].x==0){
                    int l = queries[i].l; int r = queries[i].r;
                    segtree.set(l,r+1,1);
                }
            }
            int l = queries[nxt.second].l; int r = queries[nxt.second].r;
            int v = r-l+1-segtree.query(l,r+1);
            int idx = nxt.second;
            if(v==1){
                high[idx] = mid[idx];
            }
            else{
                low[idx] = mid[idx];
            }
        }
    }
    for(int i = 1; i<=q; i++){
            if((queries[i].t==0&&queries[i].x==0)||bad[i]||queries[i].t==1){
                continue;
            }
            //cout << i << " : " << ind[i] << " " << high[i] << "\n";
            tim[ind[i]] = min(tim[ind[i]],max(high[i],i));
    }
    /*
    for(int i = 1; i<=n; i++){
        cout << tim[i] << " ";
    }
    cout << "\n";
    */
    SegTree segtree;
    segtree.init(n+5);
    for(int i = 1; i<=q; i++){
        int t = queries[i].t; int l = queries[i].l; int r = queries[i].r; int x = queries[i].x;
        if(t==0){
            if(x==0){
                segtree.set(l,r+1,1);
            }
        }
        else{
            if(segtree.query(x,x+1)==1){
                cout << "NO\n";
                continue;
            }
            if(tim[x]<=i){
                cout << "YES\n";
            }
            else{
                cout << "N/A\n";
            }
        }
    }
    return 0;
}