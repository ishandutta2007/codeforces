//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 1E6+7;
int T[DIM*4],mod[DIM*4];
void push(int t){
    for(int i = t*2+1;i<=t*2+2;++i){
        T[i]+=mod[t];
        mod[i]+=mod[t];
    }
    mod[t] = 0;
}
void update(int t,int tl,int tr,int l,int r,int val){
    if (l>tr || tl>r)
        return;
    if (l<=tl && tr<=r){
        T[t]+=val;
        mod[t]+=val;
        return;
    }
    push(t);
    int tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = min(T[t*2+1],T[t*2+2]);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > > V;
    for(int i = 1;i<=n;++i){
        int l,r,w;
        cin>>l>>r>>w;
        --r;
        V.push_back({w,{l,r}});
    }
    sort(V.begin(),V.end());
    int ptr = 0;
    int res = 1E9;
    for(int i = 0;i<n;++i){
        update(0,1,m-1,V[i].second.first,V[i].second.second,1);
        while(ptr<i){
            update(0,1,m-1,V[ptr].second.first,V[ptr].second.second,-1);
            if (T[0]==0){
                update(0,1,m-1,V[ptr].second.first,V[ptr].second.second,1);
                break;
            }
            ++ptr;
        }
        if (T[0]>0)
            res = min(res,V[i].first-V[ptr].first);
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
    return 0;
}