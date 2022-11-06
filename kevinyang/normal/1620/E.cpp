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
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        parent[x] = y;
        sz[y]+=sz[x];
        sz[x] = 0;
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    int cur = 1;
    DisjointSet ds;
    ds.init((int)5e5+5);
    vector<vector<int>>sets((int)5e5+5);//sets with respect to id(the value of the numbers) holds the indices in the array
    vector<int>ind((int)5e5+5);//holds the actual index in the dsu with the id as the index in ind
    for(int i = 1; i<=(int)5e5; i++){
        ind[i] = i;
    }
    while(q--){
        int cm;
        cin >> cm;
        if(cm==1){
            int x;
            cin >> x;
            int idx = ind[x];
            sets[idx].push_back(cur);
            ds.sz[idx]++;
            cur++;
        }
        else{
            int x,y;
            cin >> x >> y;
            if(x==y)continue;
            int i = ind[x]; int j = ind[y];
            if(ds.sz[i]<ds.sz[j]){
                ds.Union(i,j);
                for(int nxt: sets[i]){
                    sets[j].push_back(nxt);
                }
                sets[i].clear();
            }
            else{
                ds.Union(j,i);
                for(int nxt: sets[j]){
                    sets[i].push_back(nxt);
                }
                sets[j].clear();
                ind[y] = i;
                ind[x] = j;
            }
        }
    }
    vector<int>ans(cur+5);
    for(int i = 1; i<=(int)5e5; i++){
        for(int nxt: sets[ind[i]]){
            ans[nxt] = i;
        }
    }
    for(int i = 1; i<cur; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}