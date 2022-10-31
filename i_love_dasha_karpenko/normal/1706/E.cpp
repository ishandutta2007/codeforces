#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 2e5+7;
const int INF = 1e9+7;
pair<int,int> E[N],Q[N];
int L[N],R[N],P[N];
vector<int> V[N];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int n,m,q,T[N];
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = L[tl];
        return;
    }
    int tm = (tl+tr)/2;
    buildtree(t+1,tl,tm);
    buildtree(t+(tm-tl+1)*2,tm+1,tr);
    T[t] = max(T[t+1],T[t+(tm-tl+1)*2]);
}
int get(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr){
        return 0;
    }
    if (l<=tl && tr<=r){
        return T[t];
    }
    int tm = (tl+tr)/2;
    return max(get(t+1,tl,tm,l,r),get(t+(tm-tl+1)*2,tm+1,tr,l,r));
}
void unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b){
        return;
    }
    P[a] = b;
}
void solve(){

    cin>>n>>m>>q;
    for(int i = 1;i<=m;i+=1){
        cin>>E[i].first>>E[i].second;
    }
    for(int i = 1;i<n;i+=1){
        L[i] = 0;
        R[i] = m;
    }
    for(int iter = 0;iter<=20;iter+=1){
        for(int i = 1;i<n;i+=1){
            if (L[i]!=R[i]) {
                V[(L[i] + R[i]) / 2].push_back(i);
            }
        }
        for(int i = 1;i<=n;i+=1){
            P[i] = i;
        }
        for(int e = 0;e<=m;e+=1){
            if (e!=0) {
                unite(E[e].first, E[e].second);
            }
            for(int i:V[e]){
                if (F(i)==F(i+1)){
                    R[i] = e;
                }
                else{
                    L[i] = e+1;
                }
            }
            V[e].clear();
        }
    }
    buildtree(0,1,n);
    for(int i = 1;i<=q;i+=1){
        int l,r;
        cin>>l>>r;
        cout<<get(0,1,n,l,r-1)<<' ';
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}