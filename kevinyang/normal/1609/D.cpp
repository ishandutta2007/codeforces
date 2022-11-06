#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
    vector<int>parent,sz;
    int size;
    void init(int n){
        size = n;
        parent.resize(n+1); sz.resize(n+1);
        for(int i = 1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x); y = find(y);
        if(x==y)return;
        if(sz[x]<sz[y]){
            parent[x] = y;
            sz[y]+=sz[x];
        }
        else{
            parent[y] = x;
            sz[x]+=sz[y];
        }
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,d;
    cin >> n >> d;
    int extra = 0;
    DisjointSet ds;
    ds.init(n);
    while(d--){
        int x,y;
        cin >> x >> y;
        if(ds.find(x)==ds.find(y)){
            extra++;
        }
        else{
            ds.Union(x,y);
        }
        set<int>s;
        for(int i = 1; i<=n; i++){
            s.insert(ds.find(i));
        }
        vector<int>arr;
        for(int nxt: s){
            arr.push_back(ds.sz[ds.find(nxt)]);
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        int ans = 0;
        for(int i = 0; i<=min(extra,(int)arr.size()-1); i++){
            ans+=arr[i];
        }
        cout << ans-1 << "\n";
    }
    return 0;
}