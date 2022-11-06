#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(pair<int,int>a, pair<int,int>b){
    return a.first*b.second<b.first*a.second;
}
struct SegTree{
    int size;
    vector<int>arr;
    vector<int>sums;
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        arr.assign(2*size,0LL);
        sums.assign(2*size,0LL);
    }
    void set(int l, int r, int v, int x, int lx, int rx){
        if(lx>=r||l>=rx)return;
        if(lx>=l&&rx<=r){
            arr[x]+=v;
            sums[x]+=v;
            return;
        }
        int m = (lx+rx)/2;
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
        sums[x] = min(sums[2*x+1],sums[2*x+2])+arr[x];
    }
    void set(int l, int r, int v){
        set(l,r,v,0,0,size);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx>=r||l>=rx)return (int)1e18;
        if(lx>=l&&rx<=r){
            return sums[x];
        }
        int m = (lx+rx)/2;
        int s1 = query(l,r,2*x+1,lx,m);
        int s2 = query(l,r,2*x+2,m,rx);
        return min(s1,s2)+arr[x];
    }
    int query(int l, int r){
        return query(l,r,0,0,size);
    }
};
int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int>a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        vector<pair<int,int>>sorted;
        vector<int>sz(m+1);
        vector<vector<int>>b(m+1);
        for(int i = 1; i<=m; i++){
            cin >> sz[i];
            for(int j = 0; j<sz[i]; j++){
                int x;
                cin >> x;
                b[i].push_back(x);
            }
        }
        sorted.push_back({0,1});
        for(int i = 1; i<=n; i++){
            sorted.push_back({a[i],1});
        }
        for(int i = 1; i<=m; i++){
            int sum = 0;
            for(int nxt: b[i]){
                sum+=nxt;
            }
            int v = gcd(sum,sz[i]);
            sorted.push_back({sum/v,sz[i]/v});
            for(int nxt: b[i]){
                v = gcd(sum-nxt,sz[i]-1);
                sorted.push_back({(sum-nxt)/v,(sz[i]-1)/v});
            }
        }
        sort(sorted.begin()+1,sorted.end(),comp);
        map<pair<int,int>,int>hm;
        for(int i = 1; i<sorted.size(); i++){
            hm[sorted[i]] = i;
        }
        int mxn = sorted.size()+5;
        SegTree segtree;
        segtree.init(mxn+5);
        vector<int>ans;
        for(int i = 1; i<=n; i++){
            int idx = hm[{a[i],1}];
            segtree.set(0,idx+1,1);
        }
        for(int i = 1; i<=m; i++){
            int sum = 0;
            for(int nxt: b[i]){
                sum+=nxt;
            }
            int v = gcd(sum,sz[i]);
            int idx = hm[{sum/v,sz[i]/v}];
            segtree.set(0,idx+1,-1);
        }
        for(int i = 1; i<=m; i++){
            int sum = 0;
            for(int nxt: b[i]){
                sum+=nxt;
            }
            int v = gcd(sum,sz[i]);
            int idx = hm[{sum/v,sz[i]/v}];
            segtree.set(0,idx+1,1);
            for(int nxt: b[i]){
                v = gcd(sum-nxt,sz[i]-1);
                int ind = hm[{(sum-nxt)/v,(sz[i]-1)/v}];
                segtree.set(0,ind+1,-1);
                if(segtree.query(0,mxn)>=0)ans.push_back(1);
                else ans.push_back(0);
                segtree.set(0,ind+1,1);
            }
            segtree.set(0,idx+1,-1);
        }
        for(int nxt: ans){
            cout << nxt;
        }
        cout << "\n";
    }
    return 0;
}