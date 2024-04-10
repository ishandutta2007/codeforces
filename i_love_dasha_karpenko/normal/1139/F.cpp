//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> super_set_pp;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> super_set_int;

#define endl '\n'
const int N = 1e5+7;
const int INF = 2e9+7;
struct seg_tree{
    super_set_pp T[N*2];
    super_set_int elem;
    void update(int t,int tl,int tr,int pos,pair<int,int> val,int type){
        if (tl>pos || tr<pos)
            return;
        if (type==0)
            T[t].insert(val);
        else T[t].erase(val);
        if (tl==tr){
            return;
        }
        int tm = (tl+tr)>>1;
        update(t+1,tl,tm,pos,val,type);
        update(t+(tm-tl+1)*2,tm+1,tr,pos,val,type);
    }
    int get(int t,int tl,int tr,int l,int r,int val){
        if (l>tr || tl>r)
            return 0;
        if (l<=tl && tr<=r){
            return T[t].order_of_key({val,INF});
        }
        int tm = (tl+tr)>>1;
        return get(t+1,tl,tm,l,r,val)+get(t+(tm-tl+1)*2,tm+1,tr,l,r,val);
    }
    void add(int pos,pair<int,int> val,int type){
        update(0,0,elem.size()-1,elem.order_of_key(pos),val,type);
    }
    int get(int l,int r,int val){
        return get(0,0,elem.size()-1,elem.order_of_key(l),elem.order_of_key(r+1)-1,val);
    }
};
seg_tree T;
vector<pair<int,int> > events;
pair<int,int> A[N],B[N];
int ans[N];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>A[i].first;
    }
    for(int i = 1;i<=n;++i){
        cin>>A[i].second;
    }
    for(int i = 1;i<=n;++i){
        int l = A[i].first,r = A[i].second,p;
        cin>>p;
        T.elem.insert(l-p);
        A[i] = {l,p};
        events.push_back({l,i});
        events.push_back({r+1,-i});
    }
    for(int i = 1;i<=m;++i)
        cin>>B[i].first;
    for(int i = 1;i<=m;++i){
        cin>>B[i].second;
        events.push_back({B[i].first,i+n});
    }
    sort(events.begin(),events.end());
    for(auto [val,ind]:events){
        if (ind<=n){
            int type = 0;
            if (ind<0)
                type = 1,ind = -ind;
            T.add(A[ind].first-A[ind].second,{A[ind].first+A[ind].second,ind},type);
        }
        else{
            ind-=n;
            ans[ind] = T.get(-INF,B[ind].first-B[ind].second,B[ind].first+B[ind].second);
        }
    }
    for(int i = 1;i<=m;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}