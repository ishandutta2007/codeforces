#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e6+7;
pair<int,int> A[N];
int B[N];
ll T[N*2],S[N*2],len[N*2];
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = 0;
        S[t] = 1;
        len[t] = 1;
        return;
    }
    int tm = (tl+tr)>>1;
    int l = t+1,r = t+((tm-tl+1)<<1);
    buildtree(l,tl,tm);
    buildtree(r,tm+1,tr);
    T[t] = min(T[r]+S[l],T[l]-S[r]+len[r]);
    S[t] = S[l]+S[r];
    len[t] = len[l]+len[r];
}
void update(int t,int tl,int tr,int pos,int val){
    if (tl>pos || tr<pos)
        return;
    if (tl==tr){
        if (val!=-1){
            T[t] = 0;
            S[t] = val;
            len[t] = 1;
        }
        else{
            T[t] = 0;
            S[t] = 0;
            len[t] = 0;
        }
        return;
    }
    int tm = (tl+tr)>>1;
    int l = t+1,r = t+((tm-tl+1)<<1);
    update(l,tl,tm,pos,val);
    update(r,tm+1,tr,pos,val);
    T[t] = min(T[r]+S[l],T[l]-S[r]+len[r]);
    S[t] = S[l]+S[r];
    len[t] = len[l]+len[r];
}

void solve(){
    int n,m;
    cin>>n>>m;
    ll res = 0;
    super_set S;
    for(int i = 1;i<=n;++i) {
        cin >> A[i].first, A[i].second = i;
        res+=i-1-S.order_of_key({A[i].first+1,0});
        S.insert({A[i].first,i});
    }
    
    for(int i = 1;i<=m;++i)
        cin>>B[i];
    sort(A+1,A+1+n);
    sort(B+1,B+1+m);
    buildtree(0,1,n);
    int ptr = 1;
    vector<int> nact;
    for(int i = 1;i<=m;++i){
        if (B[i]!=B[i-1]){
            while(!nact.empty()){
                update(0,1,n,nact.back(),0);
                nact.pop_back();
            }
        }
        while(ptr<=n && A[ptr].first<B[i]){
            update(0,1,n,A[ptr].second,0);
            ++ptr;
        }
        while(ptr<=n && A[ptr].first==B[i]){
            update(0,1,n,A[ptr].second,-1);
            nact.push_back(A[ptr].second);
            ++ptr;
        }
        res+=T[0];
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}