//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
const int QDIM = 2E5+7;
struct dot{
    int x,y;
};
dot K[QDIM];
pair<dot,dot> Q[QDIM];
bool ans[QDIM];
int n,m,k,q;
struct node{
    int l,r,h1,h2,pos;
};
const bool operator < (const node& a,const node& b){
    if (a.r==b.r) {
        if (a.pos==-1 && b.pos!=-1)
            return 1;
        else return 0;
    }
    return a.r<b.r;
}
int T[N*4];
void update(int t,int tl,int tr,int pos,int val){
    if (tl>pos || tr<pos)
        return;
    if (tl==tr){
        T[t] = val;
        return;
    }
    int tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t] = min(T[t*2+1],T[t*2+2]);
}
const int INF = 1E9;
int get(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return INF;
    if (l<=tl && tr<=r)
        return T[t];
    int tm = (tl+tr)/2;
    return min(get(t*2+1,tl,tm,l,r),get(t*2+2,tm+1,tr,l,r));
}
void calcans(){
    for(int i = 0;i<=m*4;++i)
        T[i] = 0;
    vector<node> V;
    for(int i = 1;i<=q;++i){
        V.push_back({Q[i].first.x,Q[i].second.x,Q[i].first.y,Q[i].second.y,i});
    }
    for(int i = 1;i<=k;++i){
        V.push_back({0,K[i].x,0,K[i].y,-1});
    }
    sort(V.begin(),V.end());
    for(auto [l,r,h1,h2,pos]:V){
        if (pos==-1){
            update(0,1,m,h2,r);
        }
        else{
            int val = get(0,1,m,h1,h2);
            if (val>=l)
                ans[pos] = 1;
        }
    }
}
void solve(){

    cin>>n>>m>>k>>q;
    for(int i = 1;i<=k;++i){
        cin>>K[i].x>>K[i].y;
    }
    for(int i = 1;i<=q;++i){
        cin>>Q[i].first.x>>Q[i].first.y>>Q[i].second.x>>Q[i].second.y;
    }
    calcans();
    for(int i = 1;i<=k;++i){
        swap(K[i].x,K[i].y);
    }
    for(int i = 1;i<=q;++i){
        swap(Q[i].first.x,Q[i].first.y);
        swap(Q[i].second.x,Q[i].second.y);
    }
    swap(n,m);
    calcans();
    for(int i = 1;i<=q;++i){
        if (ans[i])
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}